#ifndef WOODSWORD_H
#define WOODSWORD_H

#include "../Equippable.h"

class WoodSword : public Equippable
{
public:

	WoodSword()
	{
		Equippable( new Stats(0, 5, 0, 0, 0), 
			"Wooden Sword", 
			Kind::WEAPON, Range::CLOSE, Element::NEUTRAL, Element::NONE);
	}
protected:
private:
};

#endif // !WOODSWORD_H