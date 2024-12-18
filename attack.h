#pragma once

class Character;

class Attack
{
public:
	static bool AttackPhysicsAndDead(Character* pCA, Character* pCB);
	static bool AttackMagicAndDead(Character* pCA, Character* pCB);
protected:

	enum Attribute
	{
	//　 　属性						特徴
	//――――――――――――――――――――――――――――
		NOMAL = 0,		// 魔法が使えないが攻撃力が一番高い
		FIRE = 1,		// 魔法耐性が高い
		WATER = 2,		// 防御力が高い
		ROCK = 3,		// 攻撃力が二番目に高い
		WIND = 4,		// 魔法耐性が高い
	};
};