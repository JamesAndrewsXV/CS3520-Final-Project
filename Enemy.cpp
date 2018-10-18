#include "Enemy.h"

Enemy::Enemy()
{
	this->stats = new Stats(5, 5, 5, 5, 5);
	this->currHP = this->stats->getStats[0];
}

Enemy::~Enemy()
{
	//Construct Loot Object
}

void Enemy::takeDamage(Element elem, int damage)
{
	for (Element e : this->weaknesses) 
	{
		if (e == elem) { damage = (double)damage * 1.5;}
	}
	for (Element e : this->strengths) 
	{
		if (e == elem) { damage = (double)damage * 0.5; }
	}
	currHP -= damage;
}
