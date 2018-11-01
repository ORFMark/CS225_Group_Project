/*
 * Items.cpp
 *
 *  Created on: Oct 30, 2018
 *      Author: Mark
 */

#include "Items.h"
using namespace std;
Item::Item(string name) {
	cout << "Building item" << endl;;
	string line;
	ifstream fin("Items.txt");

	getline(fin, line);
	cout << line << endl;
	vector<string> parser = stringSplit(line);

	this->name = parser.at(0);
	this->target = parser.at(1);
	this->bonus = stoi(parser.at(2));
	if(parser.at(3) == "F") {
		this->isPrecent = false;
	}
	else {
		this->isPrecent = true;
	}
	cout << "finished building item" << this->name << endl;
	fin.close();
}


