#ifndef GOBLIN_H
#define GOBLIN_H

#include "../Enemy.h"

class Goblin : public Enemy
{
public:
	Goblin()
	{
		this->stats = new Stats(23, 10, 12, 3, 9);
		this->currHP = this->stats->HP;
		this->strengths = { Element::TERRA };
		this->weaknesses = {  };
		this->name = "Goblin";
	}
	~Goblin() {}

	Attack Enemy::attackDecision()
	{
		switch (rand() % this->attackAmount)
		{
		case 0:
			return this->enAttack();
		}
	}
};





#endif // GOBLIN_H
