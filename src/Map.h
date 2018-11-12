/* Author  : Adam Walker
 * File    : Map.cpp
 * Date    : 5 Nov 2018
 * Project : CS225 Group Project
 * Purpose : Header File to abstract map
 */
#pragma once
#include "Cell.h"
using namespace std;
class Map {
private:
	int size;
	Cell** map;
	int spawn[2] = {0, 0};
	void validPos(int* pos);
public:
	int getSize() {return size; }
	Map(int size);
	void displayMap();
	void Move(char direction, Character& player); // changed to char ('u', 'd', 'l', 'r' : "up", "down", "left", "right")
	friend ostream& operator<<(ostream& os, Map& map);
};
