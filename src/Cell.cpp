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
			cout << it;
			Inv.push_back((&it));
		}
		else {
			Item e("random");
			cout << e;
			Inv.push_back(&e);
		}
	}
	return Inv;
}

void Cell::lootCell(Character& looter) {
	cout << "Starting loot" << endl;
	for(unsigned i = 0; i < Loot.size(); i++) {
		cout << "adding item" << (Loot.at(i)) << endl;
		looter.AddItem(Loot.at(i));
		cout << "finished adding" << endl;
	}
	Loot.clear();
	status = 'C';
	cout << "Looted cell!";

}
