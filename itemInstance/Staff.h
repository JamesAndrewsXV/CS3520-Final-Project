#ifndef STAFF_H
#define STAFF_H

#include "../Equippable.h"

class Staff : public Equippable
{
public:

	Staff()
	{
		this->bonus = new Stats(0, 3, 0, 8, 0);
		this->range = Range::MAGIC;
		this->kind = Kind::WEAPON;
		this->strength = Element::NEUTRAL;
		this->name = "Wizard's Staff";
	}
protected:
private:
};

#endif // !WOODSWORD_H
