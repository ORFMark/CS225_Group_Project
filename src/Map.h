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
