#include "attack.h"
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

bool Attack::AttackPhysicsAndDead(int str, int vit, int* pHp)
{
	int damage = CalculationDamage(str, vit);
	if (*pHp - damage > 0)
	{
		*pHp -= damage;
		return false; // ����͎���łȂ�
	}
	else
	{
		*pHp = 0;
		return true; // ����͎���
	}
}

bool Attack::AttackMagicAndDead(int* pHp, int* pVit, int* pMp, int opponentAttribute, int myAttribute)
{
	const char* attribute[] = { "��", "��", "��", "��", "��" };
	cout << attribute[myAttribute] << "�����̖��@�������" << endl;
	if (*pMp > 0)
	{
		--*pMp;
		int damage = 0;
		switch (opponentAttribute)
		{
		case FIRE:
			cout << "���@�ϐ��������悤��" << endl;
			if (myAttribute == WATER)
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
			if (myAttribute == FIRE)
			{
				cout << "0�_���[�W�I" << endl
					<< "���̖������������I�����U�����L���ɂȂ����I" << endl;
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
			cout << damage << "�_���[�W�I" << endl;
			break;
		case ROCK:
			if (myAttribute == WIND)
			{
				damage = 5;
			}
			else if (myAttribute == WATER)
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
			if (myAttribute == FIRE)
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
		if (*pHp - damage > 0)
		{
			*pHp -= damage;
			return false; // ����͐����Ă���
		}
		else
		{
			*pHp = 0;
			return true; // ����͎���
		}
	}
	else
	{
		cout << "MP������Ȃ��I" << endl;
		return false;
	}
}
