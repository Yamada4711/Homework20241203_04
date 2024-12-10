#include <iostream>
#include <ctime>
#include "player.h"
#include "attack.h"
#include "enemy.h"
using namespace std;

int main()
{
	srand((unsigned int)time(NULL));
	Player player;
	player.PlayerTurn(player);
}