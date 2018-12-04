#ifndef BREASTPLATE
#define BREASTPLATE

#include "../Equippable.h"

class Breastplate :public Equippable
{
public:
	Breastplate()
	{
		Equippable(new Stats(20, 0, 10, 0, 2), "Breastplate", Kind::CHEST, Range::NONE, Element::NONE, Element::NONE);
	}
};


#endif // !BREASTPLATE_H

