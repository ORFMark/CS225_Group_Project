/*
 * Items.cpp
 *
 *  Created on: Oct 30, 2018
 *      Author: Mark
 */

#include "Items.h"
using namespace std;
string Item::getItem(string name) {
	string line;
	ifstream fin("Items.txt");
	while (true) {
		if (!fin.bad()) {
			getline(fin, line);
			cout << line;
		}
	}

}


