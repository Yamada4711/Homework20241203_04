#include "attack.h"
#include <iostream>
using namespace std;

int CalculationDamage(int str, int vit)
{
	if (str > vit)
	{
		cout << str - vit << "のダメージ！" << endl;
		return str - vit;
	}
	else
	{
		cout << "ミス！" << endl;
		return 0;
	}
}

bool Attack::AttackPhysicsAndDead(int str, int vit, int* pHp)
{
	int damage = CalculationDamage(str, vit);
	if (*pHp - damage > 0)
	{
		*pHp -= damage;
		return false; // 相手は死んでない
	}
	else
	{
		*pHp = 0;
		return true; // 相手は死んだ
	}
}

bool Attack::AttackMagicAndDead(int* pHp, int* pVit, int* pMp, int opponentAttribute, int myAttribute)
{
	const char* attribute[] = { "無", "火", "水", "岩", "風" };
	cout << attribute[myAttribute] << "属性の魔法を放った" << endl;
	if (*pMp > 0)
	{
		--*pMp;
		int damage = 0;
		switch (opponentAttribute)
		{
		case FIRE:
			cout << "魔法耐性が高いようだ" << endl;
			if (myAttribute == WATER)
			{
				damage = 2;
			}
			else
			{
				damage = 0;
			}
			cout << damage << "ダメージ！" << endl;
			break;
		case WATER:
			if (myAttribute == FIRE)
			{
				cout << "0ダメージ！" << endl
					<< "水の膜が蒸発した！物理攻撃が有効になった！" << endl;
				damage = 0;
				*pVit = 0;
				break;
			}
			else if (myAttribute == ROCK)
			{
				damage = 5;
			}
			else
			{
				damage = 3;
			}
			cout << damage << "ダメージ！" << endl;
			break;
		case ROCK:
			if (myAttribute == WIND)
			{
				damage = 5;
			}
			else if (myAttribute == WATER)
			{
				cout << "この属性はあまり効果がないようだ" << endl;
				damage = 1;
			}
			else
			{
				damage = 3;
			}
			cout << damage << "ダメージ！" << endl;
			break;
		case WIND:
			cout << "魔法耐性が高いようだ" << endl;
			if (myAttribute == FIRE)
			{
				damage = 2;
			}
			else
			{
				damage = 0;
			}
			cout << damage << "ダメージ！" << endl;
		default:
			break;
		}
		if (*pHp - damage > 0)
		{
			*pHp -= damage;
			return false; // 相手は生きている
		}
		else
		{
			*pHp = 0;
			return true; // 相手は死んだ
		}
	}
	else
	{
		cout << "MPが足りない！" << endl;
		return false;
	}
}
