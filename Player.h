#ifndef PLAYER_H
#define PLAYER_H

// #include "Items.h"
#include "Stats.h"
#include "Attack.h"
#include "Types.h"
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
	vector<string> getAllItems();
	vector<string> getEquipped();

	void takeDamage(Attack a);
	//stat functions?  

	void addItemToBag(string item);
	void equipItem(string item);


private:
	Stats * stats;
	int currHP;
	vector<string> _items;
	vector<string> _equipped;
	vector<Element> strengths;
	vector<Element> weaknesses;

};


#endif
