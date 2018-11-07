#include "Wraith.h"



Wraith::Wraith()
{
	this->stats = new Stats(7, 2, 3, 5, 4);
	this->currHP = this->stats->HP;
	this->strengths = { Element::NEUTRAL };
	this->weaknesses = { Element::HOLY, Element::CURSE };
}


Wraith::~Wraith()
{
	//Loot destructor by parent class (do we need anything in these places?)
}

Attack Wraith::wrAttack()
{
	return Attack{ this->stats->wis, Element::CURSE, Range::MAGIC };
}
