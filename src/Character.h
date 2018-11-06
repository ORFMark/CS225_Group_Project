/*
 * Character.h
 *
 *  Created on: Nov 5, 2018
 *      Author: Mark
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_
#include <iostream>
#include <string>
#include "Items.h"
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
	void Attack(Character&);
	//void Loot(&Cell); // the cell class is to be added
	// void Move(char direction); // changed to char ('u', 'd', 'l', 'r' : "up", "down", "left", "right")
	void AddBonus(Item);
	void RemoveItem(Item);
	void applyCurse(Enchantment);
	void removeCurse(Enchantment);
	friend ostream& operator<<(ostream&, Character&); // displays characters fields
};





#endif /* CHARACTER_H_ */
