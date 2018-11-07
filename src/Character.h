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
public:
	Character(string, float, float, float);
	~Character();
	void Attack(Character&);
	// void Move(char direction); // changed to char ('u', 'd', 'l', 'r' : "up", "down", "left", "right")
	void AddItem(Item*);
	bool RemoveItem(Item*);
	friend ostream& operator<<(ostream&, Character&); // displays characters fields
};
