/* Author  : Mark Burrell
 * File    : Util.cpp
 * Date    : 31 Oct 2018
 * Project : CS225 Group Project
 * Purpose : Code file for Util functions that will get reused alot
 */
#include "Util.h"
int randInt(int lowerBound, int upperBound) {
	return ((double) rand() / (double) RAND_MAX) * (upperBound - lowerBound) + lowerBound;
}

vector<string> stringSplit(string rawString) {
	vector<string> strV;
	vector<int> splitList;
	string subStr;
	int i = 0;
	for(i = 0; i < rawString.length(); i++) {
		if (rawString.at(i) == '\'') {
			//cout << "found quote at " << i << endl;
			splitList.push_back(i);
		}
	}
	for (i = 0; i < splitList.size(); i+=2) {
		//cout << "i: " << i <<endl;
		//cout << "Start: " << splitList.at(i) << endl;
		//cout << "end: " << splitList.at(i+1) << endl;
		//cout << "Raw: " << rawString << endl;
		//cout << "Splice: " << rawString.substr(splitList.at(i), (splitList.at(i+1) - splitList.at(i))) << endl;
		subStr = rawString.substr(splitList.at(i), splitList.at(i+1) - splitList.at(i));
		if (subStr.at(0) == '\'') {
			subStr.erase(0,1);
		}
		//cout << subStr << endl;
		strV.push_back(subStr);
	}
	return strV;
}

int inputInt(string prompt) {
	int in = 0;
	cout << prompt;
	cin >> in;
	while (!cin) {
		cout << "Not a valid integer!" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << prompt;
		cin >> in;
	}
	return in;
}

char inputLetter(string prompt) {
	char out;
	bool done = false;

	do {
		cout << prompt;
		cin >> out;
		if ((out >= 'a' && out <= 'z') || (out >= 'A' && out <= 'Z')) {
			done = true;
		}
		else {
			cout << "Not a valid letter" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	} while (!done);
	return out;
}

string inputString(string prompt) {
	string out;
	bool done = false;

	do {
		cout << prompt;
		cin >> out;
		if (!cin) {
			cout << "Invalid input!!!" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			done = false;
		}
		else {
			done = true;
		}
	} while (!done);
	return out;
}
