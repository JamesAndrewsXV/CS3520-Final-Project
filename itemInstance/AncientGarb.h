#ifndef ANCIENTGARB_H
#define ANCIENTGARB_H

#include "../Equippable.h"

class AncientGarb :public Equippable
{
public:
	AncientGarb()
	{
		Equippable(new Stats(30, 0, 26, 0, 35), "Garb of the Ancient", Kind::CHEST, Range::NONE, Element::HOLY, Element::CURSE);
	}
};


#endif // !ANCIENTGARB_H

