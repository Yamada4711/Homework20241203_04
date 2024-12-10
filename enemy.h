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
		SLIME =  0, // –³‘®«
		MAGICIAN = 1, // ‰Î‘®«
		SAHAGIN = 2, // …‘®«
		GOBLINS = 3, // Šâ‘®«
		SPRITE = 4, // •—‘®«
	};

	int name;
	const int NAME_SIZE = 5;
};