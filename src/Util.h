/* Author  : Mark Burrell
 * File    : Util.h
 * Date    : 5 Nov 2018
 * Project : CS225 Group Project
 * Purpose : Header file for the Util Class
 */
#ifndef UTIL_H_
#define UTIL_H_
#include <iostream>
#include <climits>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>
using namespace std;
int randInt(int lowerBound, int upperBound);
vector<string> stringSplit(string raw);
int inputInt(string prompt);
char inputLetter(string prompt);
#endif /* UTIL_H_ */
