#include "Player.h"
#include <algorithm>

Player::Player()
{
	this->stats = new Stats(10, 5, 5, 5, 5);
	this->currHP = this->stats->HP;
	this->_items = {};
	this->_equipped = {};
	this->strengths = {};
	this->weaknesses = {};

	//Starts out bare handed
	this->range = Range::CLOSE;
	this->elem = Element::NEUTRAL;
}
Player::~Player()
{
	for (Item *i : this->_items) { delete i; }
	for(Equippable *e: this->_equipped){delete e;}
	delete this->stats; // clear stats object from memory
}

int Player::getHealth() { return this->currHP; }
Stats Player::getStats() { return *(this->stats); }
vector<Item> Player::getAllItems() 
{
	vector<Item> items = {};
	for (Item* i : this->_items) 
	{
		items.push_back(*i);
	}
	return items; 
}
vector<Equippable> Player::getEquipped() 
{
	vector<Equippable> equipped = {};
	for (Equippable* e : this->_equipped)
	{
		equipped.push_back(*e);
	}
	return equipped;
}

void Player::takeDamage(Attack a)
{
	int damage = a.attack;
	for (Element e : this->weaknesses)
	{
		if (e == a.elem) { damage = (double)damage * 1.5; }
	}
	for (Element e : this->strengths)
	{
		if (e == a.elem) { damage = (double)damage * 0.5; }
	}
	if (a.range == Range::MAGIC) {
		this->currHP -= ((damage - this->stats->intel) < 0) ? 0 : (damage - this->stats->intel); // 0 HP, otherwise whatever damage is done.
	}
	else {
		this->currHP -= ((damage - this->stats->def) < 0) ? 0 : (damage - this->stats->def); // 0 HP, otherwise whatever damage is done.
	}
}
//stat functions?  

void Player::addItemToBag(Item *item) { this->_items.push_back(item); }
void Player::equipItem(Equippable *item)
{
	//this is extremely ugly, going to try pointer comparison for efficiency.
	try
	{
		//Check if the item is in the bag
		if (std::find(this->_items.begin(), this->_items.end(), item) != this->_items.end())
		{
			this->_items.erase(std::find(this->_items.begin(), this->_items.end(), item));
			this->_equipped.push_back(item);
			*(this->stats) += (*item).getBonus();

		}
		else { throw 11; }

		//Apply buffs
		if (item->getStrength() != NULL && item->getKind != Kind::WEAPON) //It must be in the list of strengths if non null, only on armor
		{
			this->strengths.push_back(item->getStrength()); //add an instance of the strength
		}

		if (item->getWeakness() != NULL && item->getKind != Kind::WEAPON) //It must be in the list of weaknesses if non null, only on armor
		{
			this->weaknesses.push_back(item->getWeakness()); //add an instance of the weakness
		}

		if (item->getKind == Kind::WEAPON)
		{
			this->elem = item->getStrength();
			this->range = item->getRange();
		}
	}
	catch (int x)
	{
		cout << "Item not found in bag. \nError: " << x;
	}
}
void Player::unequipItem(Equippable *item)
{
	//this is extremely ugly, going to try pointer comparison for efficiency.
	try
	{
		//Check if the item is equipped 
		if (std::find(this->_equipped.begin(), this->_equipped.end(), item) != this->_equipped.end())
		{
			this->_equipped.erase(std::find(this->_equipped.begin(), this->_equipped.end(), item));
			this->_items.push_back(item);
			*(this->stats) -= (*item).getBonus();

			//Remove buffs
			if (item->getStrength() != NULL && item->getKind != Kind::WEAPON) //It must be in the list of strengths if non null, only on armor
			{ 
				this->strengths.erase(std::find(this->strengths.begin(), this->strengths.end(), item->getStrength)); //erase an instance of the strength
			}

			if (item->getWeakness() != NULL && item->getKind != Kind::WEAPON) //It must be in the list of weaknesses if non null, only on armor
			{ 
				this->weaknesses.erase(std::find(this->weaknesses.begin(), this->weaknesses.end(), item->getWeakness)); //erase an instance of the weakness
			}

			if (item->getKind == Kind::WEAPON)
			{
				this->elem = Element::NEUTRAL;
				this->range = Range::CLOSE;
			}
		}
		else { throw 12; }
	}
	catch (int x)
	{
		cout << "Item not equipped. Some sort of call error? \nError: " << x;
	}
}


Attack Player::physAttack()
{
	return Attack{ this->stats->att, this->elem, this->range };
}

Attack Player::magAttack()
{
	return Attack{ this->stats->wis, this->elem, Range::MAGIC };
}


