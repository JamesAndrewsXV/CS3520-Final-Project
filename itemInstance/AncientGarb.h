#ifndef ANCIENTGARB_H
#define ANCIENTGARB_H

#include "../Equippable.h"

class AncientGarb :public Equippable
{
public:
	AncientGarb()
	{
		this->bonus = new Stats(30, 0, 26, 0, 35);
		this->name = "Garb of the Ancient";
		this->kind = Kind::CHEST;
		this->strength = Element::HOLY;
		this->weakness = Element::CURSE;
	}
};


#endif // !ANCIENTGARB_H

