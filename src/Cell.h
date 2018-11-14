/* Author  : Adam Walker
 * File    : Cell.h
 * Date    : 5 November 2018
 * Project : CS225 Group Project
 * Purpose : Header file for cells to make it obvious what each thing holds
 */
#ifndef CELL_H_
#define CELL_H_
#include "Character.h"
#include "Items.h"
class Cell {
private:
	Character Encounter;
	vector<Item*> Loot;
	int difficulty;
	char status;
public:
	char getStatus() {
		return status;
	}
	void setStatus(char newStatus) {
		status = newStatus;
	}
	Character generateEncounter(int);
	vector<Item*> generateLoot(int);
	Cell(int difficulty = 1) {
		this->difficulty = difficulty;
		Encounter = generateEncounter(difficulty);
		Loot = generateLoot(difficulty);
		status = 'N';
	}
	Character& getEncounter() {
		return Encounter;
	}
	void lootCell(Character&);
};
#endif // CELL_H_
