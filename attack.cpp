#include "attack.h"
#include "character.h"
#include <iostream>
using namespace std;

int CalculationDamage(int str, int vit)
{
	if (str > vit)
	{
		cout << str - vit << "�̃_���[�W�I" << endl;
		return str - vit;
	}
	else
	{
		cout << "�~�X�I" << endl;
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
	const char* attribute[] = { "��", "��", "��", "��", "��" };
	cout << attribute[pCA->GetAttribute()] << "�����̖��@�������" << endl;
	if (pCA->GetMp() > 0)
	{
		pCA->SetMp();
		int damage = 0;
		switch (pCB->GetAttribute())
		{
		case FIRE:
			cout << "���@�ϐ��������悤��" << endl;
			if (pCA->GetAttribute() == WATER)
			{
				damage = 2;
			}
			else
			{
				damage = 0;
			}
			cout << damage << "�_���[�W�I" << endl;
			break;
		case WATER:
			if (pCA->GetAttribute() == FIRE)
			{
				cout << "0�_���[�W�I" << endl
					<< "���̖������������I�����U�����L���ɂȂ����I" << endl;
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
			cout << damage << "�_���[�W�I" << endl;
			break;
		case ROCK:
			if (pCA->GetAttribute() == WIND)
			{
				damage = 5;
			}
			else if (pCA->GetAttribute() == WATER)
			{
				cout << "���̑����͂��܂���ʂ��Ȃ��悤��" << endl;
				damage = 1;
			}
			else
			{
				damage = 3;
			}
			cout << damage << "�_���[�W�I" << endl;
			break;
		case WIND:
			cout << "���@�ϐ��������悤��" << endl;
			if (pCA->GetAttribute() == FIRE)
			{
				damage = 2;
			}
			else
			{
				damage = 0;
			}
			cout << damage << "�_���[�W�I" << endl;
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
		cout << "MP������Ȃ��I" << endl;
		return false;
	}
}
