#ifndef HALO_H
#define HALO_H

#include "Equippable.h"

class Halo :public Equippable
{
public:
	Halo()
	{
		this->bonus = new Stats(15, 0, 2, 0, 10);
		this->kind = Kind::HELM;
		this->name = "Halo";
	}
};


#endif // !HALO_H

