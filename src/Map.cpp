/* Author  : Adam Walker
 * File    : Map.cpp
 * Date    : 5 Nov 2018
 * Project : CS225 Group Project
 * Purpose : Code file to generate a square of cells to use as our map and move around within it
 */
#include "Map.h"

Map::Map(int size) {
	this->size = size; 
	map = new Cell*[size];
	for (int i = 0; i < size; i++) {
		map[i] = new Cell[size];
	}
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			Cell c((i*j) % (size*size) + 1);
			map[i][j] = c;
		}
	}
	spawn[0] = 0;
	spawn[1] = 0;
}

void Map::validPos(int* pos) {
	if (pos[0] < 0 || pos[0]> size || pos[1] < 0 || pos[1] > size) {
		throw "A forboding wall blocks you from going that direction";
	}
}
void Map::Move(char direction, Character& player) {
	int caseSelect = (int) direction;

	int* testPos = (int*) player.getPos();
	try {
		testPos = (int*) player.getPos();
		switch (caseSelect) {
		case 'r':
			testPos[1]++;
			validPos(testPos);
			break;
		case 'l':
			testPos[1]--;
			validPos(testPos);
			break;
		case 'd':
			testPos[0]++;
			validPos(testPos);
			break;
		case 'u':
			testPos[0]--;
			validPos(testPos);
			break;
		default:
			throw 0;
		}
		if (map[player.getPos()[0]][player.getPos()[1]].getEncounter().getHealth() <= 0) {
			map[player.getPos()[0]][player.getPos()[1]].setStatus('C');
		}
		player.setPos(testPos);

	}
	catch (const char* e) {
		throw e;
	}
	catch (int e) {
		throw ("Invalid Direction!\n");
	}


}

void Map::cellAction(Character& player) {
	map[player.getPos()[0]][player.getPos()[1]].setStatus('X');
	cout << map[player.getPos()[0]][player.getPos()[1]].getEncounter() << endl;
	if (map[player.getPos()[0]][player.getPos()[1]].getEncounter().getHealth() > 0) {
		player.Attack(map[player.getPos()[0]][player.getPos()[1]].getEncounter());
	}
	if (map[player.getPos()[0]][player.getPos()[1]].getEncounter().getHealth() > 0) {
		map[player.getPos()[0]][player.getPos()[1]].getEncounter().Attack(player);
	}
	else {
		//cout << "Monster Defeated!" << endl;
		map[player.getPos()[0]][player.getPos()[1]].lootCell(player);
		//cout << "Cell looted " << endl;
	}
}

ostream& operator<<(ostream& os, Map& map) {
	//os << "Displaying Map!" << endl;
	for( int i = 0; i < map.size; i++ ) {
		for( int j = 0; j < map.size; j++ ) {
			os << map.map[i][j].getStatus() << " | ";
		}
		os << endl;
	}
	return os;
}
