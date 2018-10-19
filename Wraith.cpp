#include "Wraith.h"



Wraith::Wraith()
{
	this->stats = new Stats(7, 2, 3, 5, 4);
}


Wraith::~Wraith()
{
	//Loot destructor by parent class (do we need anything in these places?)
}

Attack Wraith::wrAttack()
{
	return Attack(this->stats->getStats[3], Element::CURSE, Range::MAGIC);
}
