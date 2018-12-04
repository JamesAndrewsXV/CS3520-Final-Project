#ifndef ANUBIS_H
#define ANUBIS_H

#include "../Enemy.h"

class Anubis : public Enemy
{
public:
	Anubis()
	{
		this->stats = new Stats(30, 18, 24, 26, 22);
		this->currHP = this->stats->HP;
		this->strengths = { Element::HOLY, Element::CURSE };
		this->weaknesses = {  };
		this->name = "Anubis";
	}
	~Anubis() {}

	Attack Enemy::attackDecision()
	{
		switch (std::rand() % this->attackAmount)
		{
		case 0:
			return this->enAttack();
		}
	}
};





#endif // ANUBIS_H
