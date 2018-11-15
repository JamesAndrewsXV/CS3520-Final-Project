#ifndef LEVIATHANBOOTS_H
#define LEVIATHANBOOTS_H

#include "Equippable.h"

class LeviathanBoots :public Equippable
{
public:
	LeviathanBoots()
	{
		this->bonus = new Stats(4, 0, 2, 0, 10);
		this->kind = Kind::HELM;
		this->name = "Boots of Leviathan";
		this->strength = Element::WAVE;
		this->weakness = Element::ELECTRICITY;
	}
};


#endif // !HALO_H

