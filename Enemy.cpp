#include "Enemy.h"

Enemy::Enemy()
{

}

Enemy::~Enemy()
{
	//Construct Loot Object from derived class (controls rarity perhaps?)
	delete this->stats;
}

void Enemy::takeDamage(Attack a)
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
		this->currHP -= ((damage - this->stats->intel) < 1) ? 1 : (damage - this->stats->intel);
	}
	else {
		this->currHP -= ((damage - this->stats->def) < 1) ? 1 : (damage - this->stats->def);
	}
}

Attack Enemy::enAttack()
{
	return Attack{ this->stats->att, Element::NEUTRAL, Range::CLOSE };
}

