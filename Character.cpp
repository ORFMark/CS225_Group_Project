/*
 * Author: Adam Walker
 * Date: October 31, 2018
 */

#include <iostream>
#include <string>
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
	target.health -= (attack - target.defense);
}

// TODO
//void Character::Loot(&Cell location) {
//
//}

ostream& operator<<(ostream& os, Character& player) {
	os << "Name: " << player.name << endl;
	os << "Health: " << player.health << endl;
	os << "Attack: " << player.attack << endl;
	os << "Defense: " << player.defense << endl;
	// os << "Inventory: " << ;
	return os;
}
