#pragma once
#include "Character.h"
#include "Items.h"
class Cell {
private:
	vector<Character> Encounter;
	vector<Item*> Loot;
	int difficulty;
public:
	vector<Character> generateEncounter(int);
	vector<Item*> generateLoot(int);
	Cell(int difficulty = 1) {
		this->difficulty = difficulty;
		Encounter = generateEncounter(difficulty);
		Loot = generateLoot(difficulty);
	}
	void lootCell(Character&);
};
