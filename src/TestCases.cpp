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
#include "Map.h"
using namespace std;

int main() {
	srand(time(NULL));
	Item test("random");
	Enchantment test2("random");
	cout << test << endl;
	cout << test2 << endl;
	Map map(10);
	return 0;
}
