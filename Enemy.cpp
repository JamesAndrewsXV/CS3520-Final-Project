#include "Enemy.h"

Enemy::Enemy()
{
	
}

Enemy::Enemy(Stats *stats, std::vector<Element> strengths, std::vector<Element> weaknesses, string name)
{
	this->stats = stats;
	this->currHP = this->stats->HP;
	this->strengths = strengths;
	this->weaknesses = weaknesses;
	this->name = name;
}

Enemy::~Enemy()
{
	//Construct Loot Object from derived class (controls rarity perhaps?)
	delete this->stats;
}

void Enemy::takeDamage(Attack a)
{
	this->log = this->name + " takes damage!";
	int damage = a.attack;
	this->log = "";
	for (Element e : this->weaknesses)
	{
		if (e == a.elem && e != Element::NONE) { 
			damage = damage * 3 / 2; 
			log += "That's gotta hurt. \n";
		}
	}
	for (Element e : this->strengths)
	{
		if (e == a.elem && e != Element::NONE) { 
			damage /= 2; 
			log += "But it didn't hurt too much... \n";
		}
	}
	if (a.range == Range::MAGIC) {
		this->currHP -= ((damage - this->stats->intel) < 1) ? 1 : (damage - this->stats->intel);
	}
	else {
		this->currHP -= ((damage - this->stats->def) < 1) ? 1 : (damage - this->stats->def);
	}
}

Attack Enemy::attackDecision()
{
	switch (std::rand() % this->attackAmount)
	{
	case 0:
		return this->enAttack();
	}
}

std::string Enemy::getName()
{
	return this->name;
}

Attack Enemy::enAttack()
{
	this->log = this->name + " does a physical attack!\n";
	Attack a;
	a.attack = this->stats->att;
	a.elem = Element::NEUTRAL;
	a.range = Range::CLOSE;

	return a;
	
}

std::string Enemy::getLog()
{
	return this->log;
}
