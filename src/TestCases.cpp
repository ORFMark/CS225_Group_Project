//============================================================================
// Name        : CS225_Group_Project.cpp
// Author      : Mark Burrell
// Version     :
// Copyright   : Copywrite 2018 MRB All rights Reserved
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include "items.h"
using namespace std;

int main() {
	ofstream fout("Items.txt");
	fout << "'Sword' attack 10 F" << endl;
	cout << Item::getItem("Sword") << endl;
	return 0;
}
