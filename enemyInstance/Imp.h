#ifndef IMP_H
#define IMP_H

#include "../Enemy.h"

class Imp : public Enemy
{
public:
	Imp()
	{
		this->stats = new Stats(5, 2, 3, 0, 2);
		this->currHP = this->stats->HP;
		this->strengths = { Element::TERRA };
		this->weaknesses = { Element::HOLY };
		this->name = "Imp";
	}

	Attack Enemy::attackDecision()
	{
		switch (rand() % this->attackAmount)
		{
		case 0:
			return this->enAttack();
		}
	}
};





#endif // IMP_H
