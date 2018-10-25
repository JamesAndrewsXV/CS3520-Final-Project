#include "Player.h"


Player::Player()
{
	this->stats = new Stats(10, 5, 5, 5, 5);
	this->currHP = this->stats->getStats()[0];
	this->_items = *(new vector<Item>);
	this->_equipped = *(new vector<Item>);

}
Player::~Player() {}

int Player::getHealth() { return this->currHP; }
Stats Player::getStats() { return *(this->stats); }
vector<Item> Player::getAllItems() { return this->_items; }
vector<Item> Player::getEquipped() { return this->_equipped; }

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
	if (a.getRange() == Range::MAGIC) {
		this->currHP -= ((damage - this->stats->getStats()[4]) < 1) ? 1 : (damage - this->stats->getStats()[4]);
	}
	else {
		this->currHP -= ((damage - this->stats->getStats()[2]) < 1) ? 1 : (damage - this->stats->getStats()[2]);
	}
}
//stat functions?  

void Player::addItemToBag(Item item) { this->_items.push_back(item); }
void Player::equipItem(Item item)
{

	//this is extremely ugly, going to try pointer comparison for efficiency.
	try 
	{
		if (std::find(this->_items.begin(), this->_items.end(), item) != this->_items.end()) {
			this->_items.erase(std::find(this->_items.begin(), this->_items.end(), item));
			this->_equipped.push_back(item);
		}
		else { throw 11; }
		
	}
	catch (int x) 
	{
		cout << "Item not found in bag. \n Error " << x;
	}
		
}
