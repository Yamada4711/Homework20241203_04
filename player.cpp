#include "player.h"
#include <iostream>
using namespace std;

Player::Player()
{
	//	{ 人間, ドワーフ, 人魚, 獣人, エルフ }
	const int hpArr[] =			{ 40, 60, 40, 50, 30 };
	const int mpArr[] =			{  0, 20, 30, 10, 50 };
	const int vitArr[] =		{  3,  4,  5,  4,  2 };
	const int strArr[] =		{ 10,  5,  4,  7,  1 };
	const int attributeArr[] =	{  0,  1,  2,  3,  4 };

	cout << "種族は何ですか？" << endl;
	cout << "おすすめは人間かドワーフです" << endl;
	cout << "0:人間、1:ドワーフ、2:人魚、3:獣人、4:エルフ" << endl;
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
	const char* playerRace[] = { "人間", "ドワーフ", "人魚", "獣人", "エルフ" };
	const char* enemyAttribute[] = { "無", "火", "水", "岩", "風" };
	cout << "プレイヤー" << endl;
	cout << "種族 > " << playerRace[race] << endl;
	cout << "属性 > " << enemyAttribute[attribute] << endl;
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
		cout << "行動を選んでください" << endl
			<< "1:進む、2:やめる" << endl;
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
			cout << "罠を踏んだ！10のダメージ!" << endl;
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
			cout << "回復の泉だ! HPが全回復した" << endl;
			hp = maxHp;
			break;
		default:
			cout << "敵襲だ！" << endl;
			Enemy enemy;
			Attack attack;
			bool enemyDead = false;
			while (true)
			{
				enemy.ShowStatus();
				ShowStatus();
				cout << endl;
				cout << "1:攻撃、2:魔法、3:逃げる" << endl;
				cin >> move;
				if (move == 3)
				{
					cout << "プレイヤーは逃げ出した" << endl;
					int escape = rand() % 10;
					if (escape != 1)
					{
						cout << "逃走に成功した" << endl;
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
					cout << "敵を倒した!" << endl;
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
			cout << "プレイヤーは力尽きた" << endl;
			cout << endl;
		}
	}
}