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
		this->attackAmount = 2;
	}

	Attack Enemy::attackDecision()
	{
		switch (rand() % this->attackAmount)
		{
		case 0:
			return this->enAttack();
		case 1:
			return this->laAttack();
		}
	}

	Attack laAttack()
	{
		this->log = "Lamia blows a fiery kiss!\n";
		Attack a;
		a.attack = this->stats->att;
		a.elem = Element::FLAME;
		a.range = Range::MAGIC;

		return a;
	}
};





#endif // LAMIA_H
