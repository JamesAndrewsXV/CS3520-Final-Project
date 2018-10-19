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
	Attack s = new Attack(this->strengths, this->stats->getStats[3]);
		return Attack(this->stats->getStats[3], this->strengths, Range::MAGIC);
}
