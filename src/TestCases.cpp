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
#include "Character.h"
using namespace std;

int main() {
	srand(time(NULL));
	Item test("random");
	Enchanted_Item test2("random");
	cout << test << endl;
	cout << test2 << endl;
	Character player("Player", 100, 20, 10);
	player.AddItem(&test2);
	cout << player << endl;
	fflush(stdout);
	Map map(10);
	return 0;
}
