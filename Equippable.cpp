#include "Equippable.h"

Equippable::Equippable() {}

Equippable::Equippable(Stats * bonus, std::string name, Kind kind, Range range, Element strength, Element weakness)
{
	Item(bonus, name);
	this->kind = kind;
	this->range = range;
	this->strength = strength;
	this->weakness = weakness;
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

std::string Item::getName()
{
	return this->name;
}


Element Equippable::getStrength() {return this->strength;}

Element Equippable::getWeakness(){ return this->weakness; }

Range Equippable::getRange()
{
	return this->range;
}
