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

int Character::GetHp()
{
	return hp;
}

void Character::SetMp()
{
	mp--;
}

int Character::GetMp()
{
	return mp;
}

void Character::SetVit()
{
	vit = 0;
}

int Character::GetVit()
{
	return vit;
}

int Character::GetStr()
{
	return str;
}

int Character::GetAttribute()
{
	return attribute;
}