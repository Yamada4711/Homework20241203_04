#include "enemy.h"
#include <iostream>
using namespace std;

Enemy::Enemy()
{
	//							スラ 魔 サハ ゴブ 妖
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
	const char* enemyName[] = { "スライム", "魔術師", "サハギン", "ゴブリン", "妖精" };
	const char* enemyAttribute[] = { "無", "火", "水", "岩", "風" };
	cout << enemyName[name] << endl;
	cout << "属性 > " << enemyAttribute[attribute] << endl;
	cout << "  HP > " << hp << endl;
	cout << "  MP > " << mp << endl;
	cout << " STR > " << str << endl;
	cout << " VIT > " << vit << endl;
	cout << endl;
	cout << endl;
}

bool Enemy::AttackAI(Attack& attack, const int pStr, int* ppVit, int pVit, int* ppHp, int pAttribute)
{
	if ((pAttribute == 2 && attribute == 1 && *ppVit > 0) || // 相手　水属性　かつ　自分　火属性　かつ　相手　水防御中
		pAttribute == 2 && attribute == 3 ||				// 相手　水属性　かつ　自分　岩属性
		pAttribute == 4 && attribute == 1 ||				// 相手　風属性　かつ　自分　火属性
		attribute == 4 ||									// 自分　風属性
		pAttribute == 1)									// 相手　火属性
	{
		return attack.AttackMagicAndDead(ppHp, ppVit, &mp, pAttribute, attribute);
	}
	else
	{
		return attack.AttackPhysicsAndDead(str, pVit, ppHp);
	}
}

int* Enemy::GetPHp()
{
	return &hp;
}

int* Enemy::GetPVit()
{
	return &vit;
}

int Enemy::GetVit()
{
	return vit;
}

int Enemy::GetAttribute()
{
	return attribute;
}