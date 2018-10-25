#ifndef PLAYER_H
#define PLAYER_H

// #include "Items.h"
#include "Stats.h"
#include "Attack.h"
#include "Types.h"
#include "Item.h"
#include <vector>
#include <string>


using namespace std;

class Player
{
public:
	Player();
	~Player();

	int getHealth();
	Stats getStats();
	vector<Item> getAllItems();
	vector<Item> getEquipped();

	//Damaged by a given attack
	void takeDamage(Attack a);
	//stat functions?  

	void addItemToBag(Item item);
	void equipItem(Item item);


private:
	Stats * stats;
	int currHP;
	vector<Item> _items;
	vector<Item> _equipped;
	vector<Element> strengths;
	vector<Element> weaknesses;

};


#endif
