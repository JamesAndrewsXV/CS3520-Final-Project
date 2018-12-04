#ifndef SPIRITARROW_H
#define SPIRITARROW_H

#include "../Equippable.h"

class SpiritArrow : public Equippable
{
public:

	SpiritArrow()
	{
		Equippable(new Stats(0, 35, 0, 40, 0),
			"Arrow of the Tree Spirit",
			Kind::WEAPON, Range::FAR, Element::TERRA, Element::NONE);
	}
protected:
private:
};

#endif // !SPIRITARROW_H
