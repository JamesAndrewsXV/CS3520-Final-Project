#ifndef REAPER_H
#define REAPER_H

#include "../Enemy.h"

class Reaper : public Enemy
{
public:
	Reaper()
	{
		this->stats = new Stats(5, 2, 3, 0, 2);
		this->currHP = this->stats->HP;
		this->strengths = { Element::CURSE };
		this->weaknesses = { Element::FLAME };
		this->name = "Reaper";
		this->attackAmount = 2;
	}

	Attack Enemy::attackDecision()
	{
		switch (std::rand() % this->attackAmount)
		{
		case 0:
			return this->enAttack();
		case 1:
			return this->reAttack();
		}
	}

	Attack reAttack()
	{
		Attack a;
		a.attack = this->stats->att;
		a.elem = Element::CURSE;
		a.range = Range::CLOSE;
	}
};





#endif // REAPER_H
