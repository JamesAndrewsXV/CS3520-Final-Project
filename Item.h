#ifndef ITEM_H
#define ITEM_H

#include "Stats.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <utility>
#include "Attack.h"

using namespace std;

//Special abilities that are granted by Items, to be implemented later
enum Ability 
{
	WE,
	WILL,
	DO,
	THESE,
	LATER
};

class Item 
{
public:
	//Constructor
	Item();

	//Destructor
	virtual ~Item();

	//Creates random Item 
	Item * randomItem();

	//Returns the stat boost the item gives.
	Stats getBonus();

protected:
	Stats *bonus;
	Range range;
	vector<pair<Element, int>> bonusDamage; // does the multiplier cover this?
	vector<Ability> abilities;
	//Includes some sort of indication as to which sprite to use
};

#endif