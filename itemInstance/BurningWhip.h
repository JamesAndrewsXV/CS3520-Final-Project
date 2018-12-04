#ifndef BURNWHIP_H
#define BURNWHIP_H

#include "../Equippable.h"

class BurningWhip : public Equippable
{
public:

	BurningWhip()
	{

		this->bonus = new Stats(0, 30, 0, 2, 0);
		this->range = Range::CLOSE;
		this->kind = Kind::WEAPON;
		this->strength = Element::FLAME;
		this->name = "Burning Whip";
	}
protected:
private:
};

#endif // !WOODSWORD_H