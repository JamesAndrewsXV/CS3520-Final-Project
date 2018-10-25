#ifndef ITEM_H
#define ITEM_H

#include "Stats.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include "Types.h"
#include <utility>

using namespace std;

//Special abilities that are granted by Items, to be implemented later
enum Ability {
	WE,
	WILL,
	DO,
	THESE,
	LATER
};

class Item {
public:
	//Constructor
	Item(int damage, Range range, vector<pair<Element, int> > bonusDamage, vector<pair<Buffs, int> > buffs, vector<Ability> abilities);

	//Creates random Item 
	Item * randomItem();

	//Returns the amount of damage that an item does
	int dealDamage();


protected:
	int damage;
	Range range;
	vector<pair<Element, int> > bonusDamage; // does the multiplier cover this?
	vector<pair <Buffs, int> > buffs; 
	vector<Ability> abilities;
	//Includes some sort of indication as to which sprite to use
};

#endif