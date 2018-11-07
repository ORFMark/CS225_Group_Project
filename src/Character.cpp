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


void Character::AddItem(Item *item) {
	string h = "health";
	string d = "defense";
	string a = "attack";
	int caseSelect;
	if(item->target.compare(h) == 0) {
		caseSelect = 0;
	}
	else if (item->target.compare(d) == 0) {
		caseSelect = 1;
	}
	else if (item->target.compare(a) == 0) {
		caseSelect = 2;
	}
	else {
		caseSelect = 99;
	}
	try {
		if(item->isPrecent == true) {
			switch(caseSelect) {
			case 0:
				health += health * (item->bonus / 100) ;
				break;
			case 1:
				defense += defense * (item->bonus / 100);
				break;
			case 2:
				attack += attack * (item->bonus / 100);
				break;
			default:
				throw("Invalid Item modifier");
				break;
			}

		}
		else {
			switch(caseSelect) {
			case 0:
				health += item->bonus;
				break;
			case 1:
				defense += item->bonus;
				break;
			case 2:
				attack += item->bonus;
				break;
			default:
				throw("Invalid Item modifier");
				break;
			}
		}
		if (item->hasEnchantment == true) {
			Enchanted_Item eItem = *item;
			if(eItem.enchantmentTarget.compare(h) == 0) {
					caseSelect = 0;
				}
				else if (eItem.enchantmentTarget.compare(d) == 0) {
					caseSelect = 1;
				}
				else if (eItem.enchantmentTarget.compare(a) == 0) {
					caseSelect = 2;
				}
				else {
					caseSelect = 99;
				}
			if(eItem.enchantmentPrecent == true) {
				switch(caseSelect) {
				case 0:
					health += health * (eItem.enchantmentBonus / 100);
					break;
				case 1:
					defense += defense * (eItem.enchantmentBonus / 100);
					break;
				case 2:
					attack += attack * (eItem.enchantmentBonus / 100);
					break;
				default:
					throw("Invalid Enchantment modifier");
					break;
				}

			}
			else {
				switch(caseSelect) {
				case 0:
					health += eItem.enchantmentBonus;
					break;
				case 1:
					defense += eItem.enchantmentBonus;
					break;
				case 2:
					attack += eItem.enchantmentBonus;
					break;
				default:
					throw("Invalid Enchantment modifier");
					break;
				}
			}
		}
	} catch (const char* e) {
		cout << e << endl;
	}
}

bool Character::RemoveItem(Item *item) {
	for(int i = 0; i < inventory.size(); i++) {
		if (inventory.at(i) == item) {
			inventory.erase(inventory.begin() + i);
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
