#ifndef PLAYER_H
#define PLAYER_H

// #include "Items.h"
#include "Stats.h"
#include "Attack.h"
#include "Item.h"
#include "Equippable.h"
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
	vector<Equippable> getEquipped();

	//Damaged by a given attack
	void takeDamage(Attack a);
	//stat functions?

	void addItemToBag(Item *item);
	void equipItem(Equippable *item);
	void unequipItem(Equippable *item);
	void useItem(Item *item);
	Attack physAttack();
	Attack magAttack();

  private:
	Stats *stats;
	int currHP;
	Range range;
	Element elem;
	vector<Item *> _items;
	vector<Equippable *> _equipped;
	vector<Element> strengths;
	vector<Element> weaknesses;
};

#endif
