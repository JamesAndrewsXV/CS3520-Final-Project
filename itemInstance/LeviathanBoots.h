#ifndef LEVIATHANBOOTS_H
#define LEVIATHANBOOTS_H

#include "../Equippable.h"

class LeviathanBoots :public Equippable
{
public:
	LeviathanBoots()
	{
		Equippable(new Stats(4, 0, 2, 0, 10), "Boots of Leviathan", Kind::HELM, Range::NONE, Element::WAVE, Element::ELECTRICITY);
	}
};


#endif // !HALO_H

