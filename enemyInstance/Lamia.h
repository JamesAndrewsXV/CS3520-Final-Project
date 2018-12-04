#ifndef LAMIA_H
#define LAMIA_H

#include "../Enemy.h"

class Lamia : public Enemy
{
public:
	Lamia()
	{
		this->stats = new Stats(20, 3, 8, 9, 8);
		this->currHP = this->stats->HP;
		this->strengths = { Element::FLAME };
		this->weaknesses = { Element::WAVE };
		this->name = "Lamia";
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





#endif // LAMIA_H
