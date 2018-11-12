/* Author  : Adam Walker
 * File    : Character.h
 * Date    : 31 Oct 2018
 * Project : CS225 Group Project
 * Purpose : Header file to abstract characters
 */
#pragma once
#include <string>
#include <iostream>
#include "Items.h"

using namespace std;
class Character {
private:
	string name;
	float health;
	float attack;
	float defense; // takes away from the attack stats
	vector<Item*> inventory;
	int currentPos[2] = {0, 0};
public:
	Character(string = "Player", float = 100.0, float = 20.0, float= 10.0);
	~Character();
	void Attack(Character&);
	void AddItem(Item*);
	bool RemoveItem(Item*);
	int* getPos() { return currentPos; }
	void setPos(int* newPos) { currentPos[0] = newPos[0]; currentPos[1] = newPos[1]; }
	float getHealth() { return health; }
	friend ostream& operator<<(ostream&, Character&); // displays characters fields
};
