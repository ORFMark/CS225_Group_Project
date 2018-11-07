/*
 * Items.cpp
 *
 *  Created on: Oct 30, 2018
 *      Author: Mark
 */

#include "Items.h"

using namespace std;
Item::Item(string name) {
	//cout << "Building item" << endl;;
	hasEnchantment = false;
	string line;
	ifstream fin("Items.txt");
	int rand;
	getline(fin, line);
	int NUMBER_OF_ITEMS = stoi(line);
	vector<string> parser;
	if (name.compare("random") ==  0) {
		rand = randInt(0,NUMBER_OF_ITEMS);
		//	cout << rand << endl;
		for (int i = 0; i <= rand; i++) {
			getline(fin, line);
			parser = stringSplit(line);
		}
	}
	else {
		do {
			getline(fin, line);
			if (line.length() < 3) {
				throw "No Such item!";
			}
			parser = stringSplit(line);
		} while (parser.at(0).compare(name) != 0);
	}

	this->name = parser.at(0);
	this->target = parser.at(1);
	this->bonus = stoi(parser.at(2));
	if(parser.at(3) == "F") {
		this->isPrecent = false;
	}
	else {
		this->isPrecent = true;
	}
	//cout << "finished building item" << this->name << endl;
	fin.close();
}

ostream& operator<<(ostream& os, Item& item) {
	os << "Item: " << item.name << " Bonus: " << item.bonus;
	//fflush(stdout);
	return os;
}

bool Item::operator==(Item& item) {
	if (item.name == name)
		return true;
	return false;
}
Item::~Item() {
	cout << name << " has been destroyed" << endl;
}
Enchanted_Item::Enchanted_Item(string name) {
	hasEnchantment = true;
	string line;
	ifstream fin("Enchantment.txt");
	int rand;
	getline(fin, line);
	int NUMBER_OF_ITEMS = stoi(line);
	vector<string> parser;
	if (name.compare("random") ==  0) {
		rand = randInt(0,NUMBER_OF_ITEMS);
		//	cout << rand << endl;
		for (int i = 0; i <= rand; i++) {
			getline(fin, line);
			parser = stringSplit(line);
		}
	}
	else {
		do {
			getline(fin, line);
			parser = stringSplit(line);
		} while (parser.at(0).compare(name) != 0);
	}

	this->enchantmentName = parser.at(0);
	this->enchantmentTarget = parser.at(1);
	this->enchantmentBonus = stoi(parser.at(2));
	if(parser.at(3) == "F") {
		this->enchantmentPrecent = false;
	}
	else {
		this->enchantmentPrecent = true;
	}
	//cout << "finished building Enchantment" << this->name << endl;
	fin.close();
}
ostream& operator<<(ostream& os, Enchanted_Item& item) {
	os << "Item: " << item.name << "with" << item.enchantmentName  << " Item Bonus: " << item.bonus << "Enchantment Bonus: " << item.enchantmentBonus << endl;
	//fflush(stdout);
	return os;
}
Enchanted_Item::~Enchanted_Item() {
	cout << name << "Has been removed" << endl;
}
