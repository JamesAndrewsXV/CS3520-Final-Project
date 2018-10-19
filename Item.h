#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <Types.h>

enum Ability{
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
		
		
		
	private:
		int damage;
		Range range;
		vector<pair<Element, int> > bonusDamage;
		vector<pair <Buffs, int> > buffs;
		vector<Ability> abilities;
		//Includes some sort of indication as to which sprite to use
};

#endif