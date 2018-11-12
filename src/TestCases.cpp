//============================================================================
// Name        : CS225_Group_Project.cpp
// Author      : Mark Burrell
// Version     :
// Copyright   : Copywrite 2018 MRB All rights Reserved
// Description : Run tests in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include "Items.h"
#include "Map.h"
#include "Character.h"
#include "UI.h"
using namespace std;

int main() {
	srand(time(NULL));
	Character player("Player", 100, 20, 10);
	Character monster = Character ("Monster",  randInt(1,100) * 3,  randInt(1,10) * 3,  randInt(1,10) * 3);
	Map map(10);
	while (player.getHealth() > 0 && monster.getHealth() > 0) {
		displayUI(player, map);
		monster.Attack(player);
		player.Attack(monster);
	}
	return 0;
}
