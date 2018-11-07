/*
 * Author: Adam Walker
 * Date: October 31, 2018
 */

#include <iostream>
#include <string>
#include <vector>
#include "Items.h"
#include "Character.h"
using namespace std;

Character::Character(string name = "Player", float health = 100.0, float attack = 20.0, float defense = 10.0) {
	this->name = name;
	this->health = health;
	this->attack = attack;
	this->defense = defense;
}

Character::~Character() {
	cout << "Wasted!" << endl;
}

void Character::Attack(Character& target) {
	if (target.health > 0)
		target.health -= (attack - target.defense);
}


void Character::AddBonus(Item *item) {

 }

bool Character::RemoveItem(Item item) {
	vector<Item>::iterator it;
	for (it = inventory.begin(); it != inventory.end(); it++) {
		if (item == *it) { // need to override the boolean equals operator for the item class
			inventory.erase(it);
			return true;
		}
	}
	return false;
}

// TODO
//void Character::Loot(&Cell location) {
//
//}

ostream& operator<<(ostream& os, Character& player) {
	vector<Item>::iterator it;
	os << "Name: " << player.name << endl;
	os << "Health: " << player.health << endl;
	os << "Attack: " << player.attack << endl;
	os << "Defense: " << player.defense << endl;
	os << "Inventory: ";
	for (it = player.inventory.begin(); it != player.inventory.end(); it++)
		os << *it << " "; // need to override the insertion operator for the item class
	return os;
}
