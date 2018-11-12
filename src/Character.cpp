/* Author  : Adam Walker
 * File    : Character.cpp
 * Date    : 31 Oct 2018
 * Project : CS225 Group Project
 * Purpose : To handle Characters and their actions
 */
#include <iostream>
#include <string>
#include <vector>
#include "Items.h"
#include "Character.h"
using namespace std;

Character::Character(string name, float health, float attack, float defense) {
	this->name = name;
	this->health = health;
	this->attack = attack;
	this->defense = defense;
}


void Character::Attack(Character& target) {
	if (attack > target.defense) {
		target.health -= attack - target.defense;
	}
}


void Character::AddItem(Item *item) {
	string h = "health";
	string d = "defense";
	string a = "attack";
	int caseSelect;
	inventory.push_back(item);
	if(item->getTargetStat().compare(h) == 0) {
		caseSelect = 0;
	}
	else if (item->getTargetStat().compare(d) == 0) {
		caseSelect = 1;
	}
	else if (item->getTargetStat().compare(a) == 0) {
		caseSelect = 2;
	}
	else {
		caseSelect = 99;
	}
	try {
		if(item->precent() == true) {
			switch(caseSelect) {
			case 0:
				health += health * (item->getBonus() / 100) ;
				break;
			case 1:
				defense += defense * (item->getBonus() / 100);
				break;
			case 2:
				attack += attack * (item->getBonus() / 100);
				break;
			default:
				throw("Invalid Item modifier");
				break;
			}

		}
		else {
			switch(caseSelect) {
			case 0:
				health += item->getBonus();
				break;
			case 1:
				defense += item->getBonus();
				break;
			case 2:
				attack += item->getBonus();
				break;
			default:
				throw("Invalid Item modifier");
				break;
			}
		}
		if (item->hasEnchantment() == true) {
			//Enchanted_Item *ptrEItem = (*Enchanted_Item) item;
			//Enchanted_Item eItem = *ptrEItem;
			if(item->getEnchantmentTargetStat().compare(h) == 0) {
					caseSelect = 0;
				}
				else if (item->getEnchantmentTargetStat().compare(d) == 0) {
					caseSelect = 1;
				}
				else if (item->getEnchantmentTargetStat().compare(a) == 0) {
					caseSelect = 2;
				}
				else {
					caseSelect = 99;
				}
			if(item->getEnchantmentPrecent() == true) {
				switch(caseSelect) {
				case 0:
					health += health * (item->getEnchantmentBonus() / 100);
					break;
				case 1:
					defense += defense * (item->getEnchantmentBonus() / 100);
					break;
				case 2:
					attack += attack * (item->getEnchantmentBonus() / 100);
					break;
				default:
					throw("Invalid Enchantment modifier");
					break;
				}

			}
			else {
				switch(caseSelect) {
				case 0:
					health += item->getEnchantmentBonus();
					break;
				case 1:
					defense += item->getEnchantmentBonus();
					break;
				case 2:
					attack += item->getEnchantmentBonus();
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




ostream& operator<<(ostream& os, Character& player) {
	os << "Name: " << player.name << endl;
	os << "Health: " << player.health << endl;
	os << "Attack: " << player.attack << endl;
	os << "Defense: " << player.defense << endl;
	os << "Inventory: ";
	for (int i = 0; i != player.inventory.size(); i++)
		os << *(player.inventory.at(i)) << " "; // need to override the insertion operator for the item class
	return os;
}
