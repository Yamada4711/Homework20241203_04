#include "player.h"
#include <iostream>
using namespace std;

Player::Player()
{
	//	{ �l��, �h���[�t, �l��, �b�l, �G���t }
	const int hpArr[] =			{ 40, 60, 40, 50, 30 };
	const int mpArr[] =			{  0, 20, 30, 10, 50 };
	const int vitArr[] =		{  3,  4,  5,  4,  2 };
	const int strArr[] =		{ 10,  5,  4,  7,  1 };
	const int attributeArr[] =	{  0,  1,  2,  3,  4 };

	cout << "�푰�͉��ł����H" << endl;
	cout << "�������߂͐l�Ԃ��h���[�t�ł�" << endl;
	cout << "0:�l�ԁA1:�h���[�t�A2:�l���A3:�b�l�A4:�G���t" << endl;
	cin >> race;
	hp = hpArr[race];
	maxHp = hpArr[race];
	mp = mpArr[race];
	vit = vitArr[race];
	str = strArr[race];
	attribute = attributeArr[race];

	ShowStatus();
}

void Player::ShowStatus()
{
	const char* playerRace[] = { "�l��", "�h���[�t", "�l��", "�b�l", "�G���t" };
	const char* enemyAttribute[] = { "��", "��", "��", "��", "��" };
	cout << "�v���C���[" << endl;
	cout << "�푰 > " << playerRace[race] << endl;
	cout << "���� > " << enemyAttribute[attribute] << endl;
	cout << "  HP > " << hp << endl;
	cout << "  MP > " << mp << endl;
	cout << " STR > " << str << endl;
	cout << " VIT > " << vit << endl;
	cout << endl;
	cout << endl;
}

bool Player::PlayerTurn(Player player)
{
	while (true)
	{
		int move = 0;
		bool dead = false;
		cout << "�s����I��ł�������" << endl
			<< "1:�i�ށA2:��߂�" << endl;
		cin >> move;

		if (move == 2)
		{
			return false;
		}
		move = 0;

		int event = rand() % 5;
		switch (event)
		{
		case 0:
			cout << "㩂𓥂񂾁I10�̃_���[�W!" << endl;
			if (hp - 10 > 0)
			{
				hp -= 10;
			}
			else
			{
				hp = 0;
				dead = true;
			}
			break;
		case 1:
			cout << "�񕜂̐�! HP���S�񕜂���" << endl;
			hp = maxHp;
			break;
		default:
			cout << "�G�P���I" << endl;
			Enemy enemy;
			Attack attack;
			bool enemyDead = false;
			while (true)
			{
				enemy.ShowStatus();
				ShowStatus();
				cout << endl;
				cout << "1:�U���A2:���@�A3:������" << endl;
				cin >> move;
				if (move == 3)
				{
					cout << "�v���C���[�͓����o����" << endl;
					int escape = rand() % 10;
					if (escape != 1)
					{
						cout << "�����ɐ�������" << endl;
						cout << endl;
						break;
					}
				}
				else if (move == 2)
				{
					enemyDead = attack.AttackMagicAndDead(&player, &enemy);
					enemy.ShowStatus();
				}
				else
				{
					enemyDead = attack.AttackPhysicsAndDead(str, enemy.GetVit(), enemy.GetPHp());
					enemy.ShowStatus();
				}
				if (enemyDead)
				{
					cout << "�G��|����!" << endl;
					cout << endl;
					break;
				}
				dead = enemy.AttackAI(attack, str, &vit, vit, &hp, attribute);
				ShowStatus();
				if (dead)
				{
					break;
				}
			}
			break;
		}
		ShowStatus();
		if (dead)
		{
			cout << "�v���C���[�͗͐s����" << endl;
			cout << endl;
		}
	}
}