
#include <Stats.h>

using namespace std;

#define NUMBER_ELEMENTS 7
#define NUMBER_STATS 5
#define NUMBER_ABILITIES 5
#define NUMBER_RANGE 3



	//Creates an Item using given parameter
	Item::Item(int damage, Range range, vector<pair<Element, int> > bonusDamage, vector<pair<Buffs, int> > buffs, vector<Ability> abilities) {
		damage = damage;
		range = range;
		bonusDamage = bonusDamage;
		buffs = buffs;
		abilities = abilities;
	}
    //Creates an Item using random parameters
	Item * Item::randomItem() {
		int tempDamage = (rand() % 10) + 1;
		Range tempRange = Range(rand() % NUMBER_RANGE);
		vector< pair<Element, int> > tempBonus(NUMBER_ELEMENTS);
		
		for (int i = 0; i < (rand() % NUMBER_ELEMENTS); i++) {
			Element chosenElement = Element(rand() % NUMBER_ELEMENTS);
      //Add later: make  it so that elements cannot be dupilicated
      tempBonus.push_back(make_pair(chosenElement, rand() % 5));
		}
		
		vector<pair<Buffs, int> > tempBuffs(NUMBER_STATS);

    for (int j = 0; j < (rand() % NUMBER_STATS); j++) {
      Buffs chosenStat = Buffs(rand() % NUMBER_STATS);
      tempBuffs.push_back(make_pair(chosenStat, rand() % 3));
    }
		vector<Ability> tempAbilities(NUMBER_ABILITIES);

    for (int k = 0; k < (rand() % NUMBER_ABILITIES); k++) {
      tempAbilities.push_back(Ability(rand() % NUMBER_ABILITIES));
    }
		return new Item(tempDamage, tempRange, tempBonus, tempBuffs, tempAbilities);
	}	
	//TODO(potentially): Destroys an Item
	
	//TODO: Deal damage with item (dependent on how Player/Monsters work
	int Item::dealDamage() {
		int tempDMG = 0;
		tempDMG += damage;
		for (int i = 0; i < bonusDamage.size; i++) {
			tempDMG += bonusDamage[i]->second;
		}
		return tempDMG;
	}
	