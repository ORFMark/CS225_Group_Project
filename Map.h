#pragma once
#include "Cell.h"
class Map {
private:
	int size;
	Cell** map;
	Cell spawn;
public:
	Map(int size);
};