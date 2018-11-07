#include "Imp.h"

Imp::Imp()
{
	this->stats = new Stats(5, 2, 3, 0, 2);
	this->currHP = this->stats->HP;
	this->strengths = { Element::TERRA };
	this->weaknesses = { Element::HOLY };
}

Imp::~Imp()
{
	//"Imp defeated!" (loot dropped by parent class)
}
