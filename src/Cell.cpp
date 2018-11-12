/* Author  : Adam Walker and Mark Burrell
 * File    : Cell.cpp
 * Date    : 5 November 2018
 * Project : CS225 Group Project
 * Purpose : To handle each individual cell of the map, including generation and destruction
 */
#include <vector>
#include "Character.h"
#include "Items.h"
#include "Cell.h"
#include "util.h"
using namespace std;

Character Cell::generateEncounter(int difficulty) {
	Character monster = Character ("Monster",  randInt(1,100) * difficulty,  randInt(1,10) * difficulty,  randInt(1,10) * difficulty);
	return monster;
}

vector<Item*> Cell::generateLoot(int difficulty) {
	vector<Item*> Inv;
	for(int i = 0; i < difficulty; i++) {
		if(randInt(0,3) == 1) {
			Enchanted_Item it("random");
			Inv.push_back((&it));
		}
		else {
			Item e("random");
			Inv.push_back(&e);
		}
	}
	return Inv;
}

void Cell::lootCell(Character& looter) {
	for(int i = 0; i < Loot.size(); i++) {
		looter.AddItem(Loot.at(i));
	}
	Loot.clear();
}
