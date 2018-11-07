#include "WoodSword.h"

WoodSword::WoodSword()
{
	this->bonus = new Stats(0, 5, 0, 0, 0);
	this->range = Range::CLOSE;
	this->kind = Kind::WEAPON;
	this->strength = Element::NEUTRAL;
}
