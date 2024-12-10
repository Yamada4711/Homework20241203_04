#pragma once

class Character
{
protected:
	int hp;
	int maxHp;
	int mp;
	int str;
	int vit;
	int attribute;

public:
	void SetHp(int damage);
	int GetHp();
	void SetMp();
	int GetMp();
	void SetVit();
	int GetVit();
	int GetStr();
	int GetAttribute();
};