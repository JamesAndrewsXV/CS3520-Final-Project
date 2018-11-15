#ifndef DECEASEDGAUNTLET_H
#define DECEASEDGAUNTLET_H

#include "Equippable.h"

class DeceasedGauntlet :public Equippable
{
public:
	DeceasedGauntlet()
	{
		this->bonus = new Stats(4, 0, 2, 0, 10);
		this->kind = Kind::GLOVES;
		this->name = "Gauntlets of the Desecrated";
		this->strength = Element::CURSE;
		this->weakness = Element::HOLY;
	}
};


#endif // !DECEASEDGAUNTLET_H

