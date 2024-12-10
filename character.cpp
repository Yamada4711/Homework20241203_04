#include "character.h"

void Character::SetHp(int damage)
{
	if (damage > hp)
	{
		hp = 0;
	}
	else
	{
		hp -= damage;
	}
}

int Character::GetHp() const
{
	return hp;
}

void Character::SetMp()
{
	if (mp > 0)
	{
		mp--;
	}
	else
	{
		mp = 0;
	}
}

int Character::GetMp() const
{
	return mp;
}

void Character::SetVit()
{
	vit = 0;
}

int Character::GetVit() const 
{
	return vit;
}

int Character::GetStr() const
{
	return str;
}

int Character::GetAttribute() const
{
	return attribute;
}