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

void Boss::recoverWeakness()
{
	if (this->recoveryTurns == 0)
	{
		this->weaknesses.clear();
	}
	else {
		--this->recoveryTurns;
	}
}

