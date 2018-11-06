#include "Map.h"

Map::Map(int size) {
	this->size = size; 
	map = new Cell*[size];
	for (int i = 0; i < size; i++) {
		map[i] = new Cell[size];
	}
	spawn = map[0][0];
}