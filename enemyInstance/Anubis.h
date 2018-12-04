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
		this->attackAmount = 3;
	}

	Attack Enemy::attackDecision()
	{
		switch (std::rand() % this->attackAmount)
		{
		case 0:
			return this->enAttack();
		case 1:
			return this->anAttack();
		case 2:
			return this->anAttack2();
		}
		
	}

	Attack anAttack()
	{

	}
};





#endif // ANUBIS_H
