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
	int GetHp() const;
	void SetMp();
	int GetMp() const;
	void SetVit();
	int GetVit() const;
	int GetStr() const;
	int GetAttribute() const;
};