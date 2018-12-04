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
	}
	~Reaper() {}

	Attack Enemy::attackDecision()
	{
		switch (std::rand() % this->attackAmount)
		{
		case 0:
			return this->enAttack();
		}
	}
};





#endif // REAPER_H
