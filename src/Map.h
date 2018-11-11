/* Author  : Adam Walker
 * File    : Map.cpp
 * Date    : 5 Nov 2018
 * Project : CS225 Group Project
 * Purpose : Header File to abstract map
 */
#pragma once
#include "Cell.h"
class Map {
private:
	int size;
	Cell** map;
	int spawn[2];
public:
	Map(int size);
};
