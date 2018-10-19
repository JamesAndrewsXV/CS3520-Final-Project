#include "Attack.h"

Attack::Attack(int att, Element elem, Range rng)
{
	this->attack = att;
	this->elem = elem;
	this->range = range;
}

int Attack::getAttack()
{
	return 0;
}

Element Attack::getElem()
{
	return Element();
}

Range Attack::getRange()
{
	return Range();
}
