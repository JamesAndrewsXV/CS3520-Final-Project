#ifndef HALO_H
#define HALO_H

#include "../Equippable.h"

class Halo :public Equippable
{
public:
	Halo()
	{
		Equippable(new Stats(15, 0, 2, 0, 10), 
			"Halo", 
			Kind::HELM, Range::NO, Element::HOLY, Element::NONE);
	}
};


#endif // !HALO_H

