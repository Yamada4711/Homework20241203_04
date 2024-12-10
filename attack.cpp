#include "attack.h"
#include "character.h"
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

bool Attack::AttackPhysicsAndDead(Character* pCA, Character* pCB)
{
	int damage = CalculationDamage(pCA->GetStr(), pCB->GetVit());
	pCB->SetHp(damage);
	if (pCB->GetHp() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Attack::AttackMagicAndDead(Character* pCA, Character* pCB)
{
	const char* attribute[] = { "無", "火", "水", "岩", "風" };
	cout << attribute[pCA->GetAttribute()] << "属性の魔法を放った" << endl;
	if (pCA->GetMp() > 0)
	{
		pCA->SetMp();
		int damage = 0;
		switch (pCB->GetAttribute())
		{
		case FIRE:
			cout << "魔法耐性が高いようだ" << endl;
			if (pCA->GetAttribute() == WATER)
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
			if (pCA->GetAttribute() == FIRE)
			{
				cout << "0ダメージ！" << endl
					<< "水の膜が蒸発した！物理攻撃が有効になった！" << endl;
				damage = 0;
				pCB->SetVit();
				break;
			}
			else if (pCA->GetAttribute() == ROCK)
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
			if (pCA->GetAttribute() == WIND)
			{
				damage = 5;
			}
			else if (pCA->GetAttribute() == WATER)
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
			if (pCA->GetAttribute() == FIRE)
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
		pCB->SetHp(damage);
		if (pCB->GetHp() == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		cout << "MPが足りない！" << endl;
		return false;
	}
}
