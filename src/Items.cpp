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
Enchantment::Enchantment(string name) {
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

		this->name = parser.at(0);
		this->target = parser.at(1);
		this->bonus = stoi(parser.at(2));
		if(parser.at(3) == "F") {
			this->isPrecent = false;
		}
		else {
			this->isPrecent = true;
		}
		//cout << "finished building Enchantment" << this->name << endl;
		fin.close();
}

Enchantment::~Enchantment() {
	cout << name << "Has been removed";
}
