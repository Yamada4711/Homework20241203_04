#pragma once
#include "character.h"
#include "attack.h"

class Player;

class Enemy :
	public Character
{
public:
	Enemy();

	bool AttackAI(Character* pCB, Enemy* enemy);

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