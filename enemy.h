#pragma once
#include "character.h"
#include "attack.h"

class Enemy :
	Character
{
public:
	Enemy();

	bool AttackAI(Attack& attack, const int pStr, int* ppVit, int pVit, int* ppHp, int pAttribute);
	int* GetPHp();
	int* GetPVit();
	int GetVit();
	int GetAttribute();

	void ShowStatus();

	enum Name
	{
		SLIME =  0, // ������
		MAGICIAN = 1, // �Α���
		SAHAGIN = 2, // ������
		GOBLINS = 3, // �⑮��
		SPRITE = 4, // ������
	};

	int name;
	const int NAME_SIZE = 5;
};