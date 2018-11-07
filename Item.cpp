#include "Item.h"

using namespace std;

#define NUMBER_ELEMENTS 7
#define NUMBER_STATS 5
#define NUMBER_ABILITIES 5
#define NUMBER_RANGE 3


//Creates an Item using given parameter
Item::Item() 
{

}
Item::~Item()
{
	delete this->bonus;
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

}
//TODO(potentially): Destroys an Item

//TODO: Deal damage with item (dependent on how Player/Monsters work
//int Item::dealDamage() {
//	int tempDMG = 0;
//	tempDMG += damage;
//	for (int i = 0; i < bonusDamage.size(); i++) {
//		tempDMG += bonusDamage[i].second;
//	}
//	return tempDMG;
//}


