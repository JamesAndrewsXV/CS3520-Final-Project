#include "Player.h"


Player::Player()
{
	this->stats = new Stats(10, 5, 5, 5, 5);
	this->currHP = this->stats->getStats()[0];
	this->_items = *(new vector<string>);
	this->_equipped = *(new vector<string>);

}
Player::~Player() {}

int Player::getHealth() { return this->currHP; }
Stats Player::getStats() { return *(this->stats); }
vector<string> Player::getAllItems() { return this->_items; }
vector<string> Player::getEquipped() { return this->_equipped; }

void Player::takeDamage(Attack a)
{
	int damage = a.getAttack();
	for (Element e : this->weaknesses)
	{
		if (e == a.getElem()) { damage = (double)damage * 1.5; }
	}
	for (Element e : this->strengths)
	{
		if (e == a.getElem()) { damage = (double)damage * 0.5; }
	}
	if(a.getRange() == Range::MAGIC) { 
		this->currHP -= ((damage - this->stats->getStats()[4])<1) ? 1 : (damage - this->stats->getStats()[4]);
	}
	else {
		this->currHP -= ((damage - this->stats->getStats()[2])<1) ? 1 : (damage - this->stats->getStats()[2]);
	}
}
//stat functions?  

void Player::addItemToBag(string item) { this->_items.push_back(item); }
void Player::equipItem(string item)
{
	//logic for unequipping if it conflicts 
}
