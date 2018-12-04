#ifndef BURNWHIP_H
#define BURNWHIP_H

#include "../Equippable.h"

class BurningWhip : public Equippable
{
public:

	BurningWhip()
	{
		Equippable(new Stats(0, 30, 0, 2, 0), "Burning Whip", Kind::WEAPON, Range::CLOSE, Element::FLAME, Element::NONE);
	}
protected:
private:
};

#endif // !WOODSWORD_H