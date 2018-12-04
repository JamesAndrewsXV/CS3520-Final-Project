#include "Enemy.h"

Enemy::Enemy()
{
	
}

Enemy::~Enemy()
{
	
}

void Enemy::takeDamage(Attack a)
{
	this->log = this->name + " takes damage!";
	int damage = a.attack;
	this->log = "";
	for (Element e : this->weaknesses)
	{
		if (e == a.elem) { 
			damage = damage * 3 / 2; 
			log += "That's gotta hurt. ";
		}
	}
	for (Element e : this->strengths)
	{
		if (e == a.elem) { 
			damage /= 2; 
			log += "But it didn't hurt too much... ";
		}
	}

	
	if (a.range == MAGIC) {
		this->currHP -= ((damage - this->stats->intel) < 1) ? 1 : (damage - this->stats->intel);
	}
	else {
		this->currHP -= ((damage - this->stats->def) < 1) ? 1 : (damage - this->stats->def);
	}
	if (this->currHP < 0) { this->currHP = 0; }
	this->log = this->log + "Dealt " + std::to_string(damage) + " damage! ";
	this->log = this->log + this->name + "'s HP: " + std::to_string(this->currHP) + "/" + std::to_string(this->stats->HP) + "\n";
}

Attack Enemy::attackDecision()
{
	switch (rand() % this->attackAmount)
	{
	case 0:
		return this->enAttack();
	}

	return this->enAttack();
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

int Enemy::getHealth() {
	return this->currHP;
}
