#pragma once
#include "character.h"
#include "attack.h"
#include "enemy.h"

class Player :
	Character
{
public:
	Player();

	void ShowStatus();

	bool PlayerTurn();


	enum Race
	{
		HUMAN = 0,
		DWARF = 1,
		MARMAID = 2,
		BEASTMAN = 3,
		ELF = 4,
	};
	int race;
};