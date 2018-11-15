#ifndef SPIRITARROW_H
#define SPIRITARROW_H

#include "Equippable.h"

class SpiritArrow : public Equippable
{
public:

	SpiritArrow()
	{
		this->bonus = new Stats(0, 35, 0, 40, 0);
		this->range = Range::FAR;
		this->kind = Kind::WEAPON;
		this->strength = Element::TERRA;
		this->name = "Arrow of the Tree Spirit";
	}
protected:
private:
};

#endif // !SPIRITARROW_H
