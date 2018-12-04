#ifndef BUSTERSHIELD_H
#define BUSTERSHIELD_H

#include "../Equippable.h"

class BusterShield : public Equippable
{
public:

	BusterShield()
	{
		Equippable(new Stats(0, 15, 27, 30, 0), 
			"Buster Shield", 
			Kind::WEAPON, Range::CLOSE, Element::NEUTRAL, Element::NONE);
	}
protected:
private:
};

#endif // !FANTASIA_H