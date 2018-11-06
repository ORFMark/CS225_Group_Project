/*
 * Items.h
 *
 *  Created on: Oct 30, 2018
 *      Author: Mark
 */

#ifndef ITEMS_H_
#define ITEMS_H_
#include<iostream>
#include <string>
#include <fstream>
#include "util.h"
using namespace std;

class Item {
protected:
	string name;
	string target;
	float bonus;
	bool isPrecent;
public:
	Item(string name = "random");
	string getName() {return name;}
	string getTargetStat() {return target;}
	float getBonus() {return bonus;}
	bool precent() {return isPrecent;}
	bool operator==(Item&);
	friend ostream& operator<<(ostream& os, Item& item);
	~Item();
};

class Enchantment : public Item {
public:
	Enchantment(string name = "random");
	~Enchantment();
};
#endif /* ITEMS_H_ */
