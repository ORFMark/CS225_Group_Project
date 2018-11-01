/*
 * Util.cpp
 *
 *  Created on: Oct 31, 2018
 *      Author: Mark
 */
#include "Util.h"

int randInt(int lowerBound, int upperBound) {
	return (rand() / (double) RAND_MAX) * (upperBound - lowerBound) + lowerBound;
}

vector<string> stringSplit(string rawString) {
	vector<string> strV;
	vector<int> splitList;
	bool quoteSearch = false;
	cout << rawString.length() << endl;
	for(int i = 0; i < rawString.length(); i++) {
		if (rawString.at(i) == '\'') {
			cout << "Found ' at " << i << endl;
			splitList.push_back(i);
			quoteSearch = !quoteSearch;
		}
		else if (rawString.at(i) == ' ' && quoteSearch == false) {
			cout << "found ' '  at " << i << endl;
			splitList.push_back(i);
		}
	}
	cout << "size of split: " << splitList.size() << endl;
	for(int i = 0; i < splitList.size(); i+=2) {
		cout << rawString.substr(splitList.at(i), splitList.at(i+1)) << endl;
		strV.push_back(rawString.substr(splitList.at(i), splitList.at(i+1)));
	}
	cout << "length of strings: " << strV.size() << endl;
	return strV;
}



