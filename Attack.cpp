#include "Attack.h"

Attack::Attack(int att, Element elem, Range rng)
{
	this->attack = att;
	this->elem = elem;
	this->range = rng;
}

int Attack::getAttack()
{
	return this->attack;
}

Element Attack::getElem()
{
	return this->elem;
}

Range Attack::getRange()
{
	return this->range;
}
