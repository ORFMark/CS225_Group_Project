#include <vector>
#include "Character.h"
#include "Items.h"
#include "Cell.h"
using namespace std;

vector<Character> Cell::generateEncounter(int difficulty) {
	// Take random characters(monsters), if any, and return to Cell
	// Depends on difficulty of cell

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
