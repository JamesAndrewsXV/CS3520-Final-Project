#include "Boss.h"

Boss::Boss()
{
	this->weakenElement = {};
	this->weakenRange = {};
	this->staticWeaknesses = { };
}

Boss::~Boss()
{

}

void Boss::exploitWeakness()
{
	this->log = "You stunned " + this->name + "!";
	this->weaknesses = this->staticWeaknesses;
	this->recoveryTurns = 3;
}

void Boss::recoverWeakness()
{
	if (this->recoveryTurns == 0 && this->weaknesses.size() > 0)
	{
		this->weaknesses.clear();
		this->log = this->name + " has recovered!";
	}
	else if (this->recoveryTurns > 0)
	{
		--this->recoveryTurns;
	}
}
