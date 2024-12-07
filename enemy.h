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
		SLIME =  0, // –³‘®«
		MAGICIAN = 1, // ‰Î‘®«
		SAHAGIN = 2, // …‘®«
		GOBLINS = 3, // Šâ‘®«
		SPRITE = 4, // •—‘®«
	};

	int name;
	const int NAME_SIZE = 5;
};