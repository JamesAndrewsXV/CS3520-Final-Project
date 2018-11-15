#ifndef WOODSWORD_H
#define WOODSWORD_H

#include "../Equippable.h"

class WoodSword : public Equippable
{
public:

	WoodSword()
	{
		this->bonus = new Stats(0, 5, 0, 0, 0);
		this->range = Range::CLOSE;
		this->kind = Kind::WEAPON;
		this->strength = Element::NEUTRAL;
		this->name = "Wooden Sword";
	}
protected:
private:
};

#endif // !WOODSWORD_H