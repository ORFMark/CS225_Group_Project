/*
 * UI.cpp
 *
 *  Created on: Nov 12, 2018
 *      Author: Mark
 */
#include <stdlib.h>
#include "UI.h"
using namespace std;

void displayUI(Character p, Map m) {
	//system("CLS");
	cout << "Map " << endl << m << endl << "______________________________" << endl;
	cout << "You: " << endl << p << endl << "______________________________" << endl;
	cout << "Monster" << endl << m.getCell(p.getPos()).getEncounter() << endl <<  "______________________________" << endl;
}



