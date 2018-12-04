#ifndef WRAITH_H
#define WRAITH_H


#include "../Enemy.h"
class Wraith : public Enemy
{
public:
	Wraith()
	{
		this->stats = new Stats(7, 2, 3, 5, 4);
		this->currHP = this->stats->HP;
		this->strengths = { Element::NEUTRAL };
		this->weaknesses = { Element::HOLY, Element::CURSE };
		this->attackAmount = 2;
		this->name = "Wraith";
	}
	~Wraith();

	Attack Enemy::attackDecision()
	{
		switch (rand() % this->attackAmount)
		{
		case 0:
			return this->enAttack();
		case 1:
			return this->wrAttack();
		}
	}
	
private:
	//Attack exclusive to wraiths (magic type)
	Attack wrAttack()
	{
		this->log = "Wraith shrieks!\n";
		Attack a;
		a.attack = this->stats->wis;
		a.elem = Element::CURSE;
		a.range = Range::MAGIC;
		return a;
	}
private:
};

#endif // !