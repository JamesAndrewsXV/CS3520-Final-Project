#ifndef DECEASEDGAUNTLET_H
#define DECEASEDGAUNTLET_H

#include "../Equippable.h"

class DeceasedGauntlet :public Equippable
{
public:
	DeceasedGauntlet()
	{
		Equippable(new Stats(4, 0, 2, 0, 10), 
			"Gauntlets of the Desecrated", 
			Kind::GLOVES, Range::NO, Element::CURSE, Element::HOLY);
	}
};


#endif // !DECEASEDGAUNTLET_H

