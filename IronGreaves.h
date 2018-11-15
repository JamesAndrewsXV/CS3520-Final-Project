#ifndef IRONGREAVES_H
#define IRONGREAVES_H

#include "Equippable.h"

class IronGreaves :public Equippable
{
public:
	IronGreaves()
	{
		this->bonus = new Stats(0, 9, 20, 0, 8);
		this->kind = Kind::SHOES;
		this->name = "Iron Greaves";
		this->strength = Element::NEUTRAL;
		this->weakness = Element::FLAME;
	}
};


#endif // !IRONGREAVES_H

