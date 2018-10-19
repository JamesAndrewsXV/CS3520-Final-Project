#include "Enemy.h"

Enemy::Enemy()
{
	this->stats = new Stats(5, 5, 5, 5, 5);
	this->currHP = this->stats->getStats()[0];
}

Enemy::~Enemy()
{
	//Construct Loot Object
	delete this->stats;
}

void Enemy::takeDamage(Attack a)
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

Attack Enemy::enAttack()
{
	return Attack(this->stats->getStats()[1], Element::NEUTRAL, Range::CLOSE);
}

