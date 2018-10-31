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

string* stringSplit(string rawString) {
	for(int i = 0; i < rawString.length(); i++) {

	}
}



