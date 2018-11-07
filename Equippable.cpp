#include "Equippable.h"


Equippable::Equippable()
{
}

Equippable::~Equippable()
{
	delete this->bonus;
}

Kind Equippable::getKind()
{
	return this->kind;
}

Stats Item::getBonus()
{
	return *(this->bonus);
}


Element Equippable::getStrength() {return this->strength;}

Element Equippable::getWeakness(){ return this->weakness; }

Range Equippable::getRange()
{
	return this->range;
}
