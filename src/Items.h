/* Author  : Mark Burrell
 * File    : Item.cpp
 * Date    : 30 Oct 2018
 * Project : CS225 Group Project
 * Purpose : Header file for items for consulting so people don't need to read all the code
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
	bool isEnchanted;
	string enchantmentName;
	string enchantmentTarget;
	float enchantmentBonus;
	bool enchantmentPrecent;
	virtual ostream& displayItem(ostream& os);
public:
	Item(string name = "random");
	string getName() {
		return name;
	}
	string getTargetStat() {
		return target;
	}
	float getBonus() {
		return bonus;
	}
	bool precent() {
		return isPrecent;
	}
	bool hasEnchantment() {
		return isEnchanted;
	}
	string getEnchantmentName() {
		return enchantmentName;
	}
	string getEnchantmentTargetStat() {
		return enchantmentTarget;
	}
	float getEnchantmentBonus() {
		return enchantmentBonus;
	}
	bool getEnchantmentPrecent() {
		return enchantmentPrecent;
	}
	bool operator==(Item&);
	friend ostream& operator<<(ostream& os, Item& item);
	~Item();
};

class Enchanted_Item: public Item {
private:
	ostream& displayItem(ostream& os);
public:
	Enchanted_Item(string name = "random");
	friend ostream& operator<<(ostream& os, Enchanted_Item& item);
	~Enchanted_Item();
};
#endif /* ITEMS_H_ */
