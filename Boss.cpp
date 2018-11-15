#include "Boss.h"

Boss::Boss()
{

}


Boss::~Boss()
{

}

void Boss::exploitWeakness()
{
	this->weaknesses = this->staticWeaknesses;
	this->recoveryTurns = 3;
}

Attack Boss::enAttack()
{
	if (this->recoveryTurns == 0 && this->weaknesses.size() > 0)
	{
		this->weaknesses.clear();
	}
	else if(this->recoveryTurns > 0) 
	{
		--this->recoveryTurns;
	}
	return Attack{ this->stats->att, Element::NEUTRAL, Range::CLOSE };
}