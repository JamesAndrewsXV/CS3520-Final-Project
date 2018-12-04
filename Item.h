#ifndef ITEM_H
#define ITEM_H

#include "Stats.h"
#include <iostream>
#include <vector>
//#include <cstdlib>
#include <utility>
#include "Attack.h"
#include "itemInstance/AllArmor.h"
#include "itemInstance/AllWeapons.h"

using namespace std;

//Special abilities that are granted by Items, to be implemented later


class Item
{
public:
	//Constructor
	Item();
	Item(Stats *bonus, std::string name);

	//Destructor
	virtual ~Item();

	//Returns the stat boost the item gives.
	Stats getBonus();

	std::string getName();

protected:
	Stats *bonus;
	//Includes some sort of indication as to which sprite to use
	std::string name;
};

#endif