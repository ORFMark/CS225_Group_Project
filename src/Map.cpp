#include "Map.h"

Map::Map(int size) {
	this->size = size; 
	map = new Cell*[size];
	for (int i = 0; i < size; i++) {
		map[i] = new Cell[size];
	}
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			Cell c((i*j) % (2*size));
			map[i][j] = c;
		}
	}
	spawn[0] = 0;
	spawn[1] = 0;
}