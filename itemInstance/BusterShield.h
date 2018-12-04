#ifndef BUSTERSHIELD_H
#define BUSTERSHIELD_H

#include "../Equippable.h"

class BusterShield : public Equippable
{
public:

	BusterShield()
	{
		this->bonus = new Stats(0, 15, 27, 30, 0);
		this->range = Range::CLOSE;
		this->kind = Kind::WEAPON;
		this->strength = Element::NEUTRAL;
		this->name = "Buster Shield";
	}
protected:
private:
};

#endif // !FANTASIA_H