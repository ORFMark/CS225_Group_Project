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
#include "Util.h"
#include "Character.h"
#include "UI.h"
using namespace std;

int main() {
	srand(time(NULL));
	Character player("Player", 100, 20, 10);
	//Character monster = Character ("Monster",  randInt(1,100) * 3,  randInt(1,10) * 3,  randInt(1,10) * 3);
	Map map(10);
	char action;
	bool validAction = false;
	bool validMove = false;
	while (player.getHealth() > 0) {
		displayUI(player, map);
		do {
			action = inputLetter(
					"Do you want to interact with the cell or move: [i/m]");
			if (action == 'i') {
				map.cellAction(player);
				validAction = true;
			} else if (action == 'm')
				do {
					action = inputLetter(
							"What direction do you want to move [l/r/u/d]: ");
					try {
						map.Move(action, player);
						validMove = true;
						validAction = true;
					} catch (...) {
						cout << "Invalid Direction!" << endl;
						validMove = false;
					}
				} while (!validMove);
			else {
				cout << "Invalid action!" << endl;
				validAction = false;
			}
		} while (!validAction);
		validAction = false;
		validMove = false;
	}
	return 0;
}
