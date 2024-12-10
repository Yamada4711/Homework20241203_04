#include "enemy.h"
#include "attack.h"
#include "player.h"
#include <iostream>
using namespace std;

Enemy::Enemy()
{
	//							�X�� �� �T�n �S�u �d
	const int hpArr[] =		   {  4,  5, 11,  9,  3 };
	const int mpArr[] =		   {  0, 10,  3,  2, 20 };
	const int vitArr[] =	   {  1,  2,  5,  2,  1 };
	const int strArr[] =	   { 10,  3,  4,  5,  1 };
	const int attributeArr[] = {  0,  1,  2,  3,  4 };

	name = (rand() % NAME_SIZE);
	hp = hpArr[name];
	maxHp = hpArr[name];
	mp = mpArr[name];
	vit = vitArr[name];
	str = strArr[name];
	attribute = attributeArr[name];

	ShowStatus();
}

void Enemy::ShowStatus()
{
	const char* enemyName[] = { "�X���C��", "���p�t", "�T�n�M��", "�S�u����", "�d��" };
	const char* enemyAttribute[] = { "��", "��", "��", "��", "��" };
	cout << enemyName[name] << endl;
	cout << "���� > " << enemyAttribute[attribute] << endl;
	cout << "  HP > " << hp << endl;
	cout << "  MP > " << mp << endl;
	cout << " STR > " << str << endl;
	cout << " VIT > " << vit << endl;
	cout << endl;
	cout << endl;
}

bool Enemy::AttackAI(Character* pCB, Enemy* enemy)
{
	if ((pCB->GetAttribute() == 2 && attribute == 1 && pCB->GetVit() > 0) || // ����@�������@���@�����@�Α����@���@����@���h�䒆
		pCB->GetAttribute() == 2 && attribute == 3 ||				// ����@�������@���@�����@�⑮��
		pCB->GetAttribute() == 4 && attribute == 1 ||				// ����@�������@���@�����@�Α���
		attribute == 4 ||									// �����@������
		pCB->GetAttribute() == 0 ||							// ����@������
		pCB->GetAttribute() == 1)									// ����@�Α���
	{
		return Attack::AttackMagicAndDead(enemy, pCB);
	}
	else
	{
		return Attack::AttackPhysicsAndDead(enemy, pCB);
	}
}