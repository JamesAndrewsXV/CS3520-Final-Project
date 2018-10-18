#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

#define NUMBER_ITEM_TYPES 3
#define NUMBER_ELEMENTS 4
#define NUMBER_STATS 2
#define NUMBER_ABILITIES 5

enum ItemType{
	SWORD,
	HAMMER,
	MACE
};

enum Element{
	FIRE,
	WATER,
	EARTH,
	AIR
};

enum Stat{
	BODY,
	MIND
};

enum Ability{
	WE,
	WILL,
	DO,
	THESE,
	LATER
};

class Item {
	public:
	//Creates an Item using given parameter
	Item(int damage, ItemType type, vector<pair<Element, int> > bonusDamage, vector<pair<Stat, int> > buffs, vector<Ability> abilities) {
		damage = damage;
		type = type;
		bonusDamage = bonusDamage;
		buffs = buffs;
		abilities = abilities;
	}
    //Creates an Item using random parameters
	Item * randomItem() {
		int tempDamage = (rand() % 10) + 1;
		ItemType tempType = ItemType(rand() % NUMBER_ITEM_TYPES);
		vector< pair<Element, int> > tempBonus(NUMBER_ELEMENTS);
		
		for (int i = 0; i < (rand() % NUMBER_ELEMENTS); i++) {
			Element chosenElement = Element(rand() % NUMBER_ELEMENTS);
      //Add later: make  it so that elements cannot be dupilicated
      tempBonus.push_back(make_pair(chosenElement, rand() % 5));
		}
		
		vector<pair<Stat, int> > tempBuffs(NUMBER_STATS);

    for (int j = 0; j < (rand() % NUMBER_STATS); j++) {
      Stat chosenStat = Stat(rand() % NUMBER_STATS);
      tempBuffs.push_back(make_pair(chosenStat, rand() % 3));
    }
		vector<Ability> tempAbilities(NUMBER_ABILITIES);

    for (int k = 0; k < (rand() % NUMBER_ABILITIES); k++) {
      tempAbilities.push_back(Ability(rand() % NUMBER_ABILITIES));
    }
		return new Item(tempDamage, tempType, tempBonus, tempBuffs, tempAbilities);
	}	
	//TODO: Destroys an Item
	
	//TODO: Deal damage with item (dependent on how Player/Monsters work)
	
	private:
	int damage;
	ItemType type;
	vector<pair<Element, int> > bonusDamage;
	vector<pair <Stat, int> > buffs;
	vector<Ability> abilities;
	//Includes some sort of indication as to which sprite to use
};