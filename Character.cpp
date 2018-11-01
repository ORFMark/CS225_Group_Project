/*
 * Author: Adam Walker
 * Date: October 31, 2018
 */

#include <iostream>
#include <string>
#include "Items.h"
using namespace std;

class Character {
private: 
	string name;
	float health;
	float attack;
	float defense; // takes away from the attack stats
	// item<vector> inventory
public:
	Character(string, float, float, float);
	~Character();
	void Attack(Character& target);
	void Loot(&Cell); // the cell class is to be added
	void Move(char direction); // changed to char ('u', 'd', 'l', 'r' : "up", "down", "left", "right")
	void AddBonus(Item);
	void RemoveItem(Item);
	void status(); // will just print to screen the stats of the character, including the inventory
};

Character::Character(string name = "Player", float health = 100.0, float attack = 20.0, float defense = 10.0) {
	this->name = name;
	this->health = health;
	this->attack = attack;
	this->defense = defense;
}

Character::~Character() {
	cout << "Wasted" << endl;
}