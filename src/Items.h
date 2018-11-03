/*
 * Characters.h
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
private:
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
};
#endif /* CHARACTERS_H_ */
