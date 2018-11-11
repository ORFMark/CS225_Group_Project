/* Author  : Adam Walker
 * File    : Cell.h
 * Date    : 5 November 2018
 * Project : CS225 Group Project
 * Purpose : Header file for cells to make it obvious what each thing holds
 */
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
