#ifndef TUNIC_H
#define TUNIC_H

#include "Equippable.h"

class Tunic :public Equippable
{
public:
	Tunic()
	{
		this->bonus = new Stats(20, 0, 4, 0, 5);
		this->kind = Kind::CHEST;
		this->weakness = Element::FLAME;
		this->name = "Tunic";
	}
};


#endif // !TUNIC_H

