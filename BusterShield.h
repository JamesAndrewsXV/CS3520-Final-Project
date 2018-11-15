#ifndef BUSTERSHIELD_H
#define BUSTERSHIELD_H

#include "Equippable.h"

class Fantasia : public Equippable
{
public:

	Fantasia()
	{
		this->bonus = new Stats(0, 15, 27, 30, 0);
		this->range = Range::CLOSE;
		this->kind = Kind::WEAPON;
		this->strength = Element::HOLY;
		this->name = "Buster Shield";
	}
protected:
private:
};

#endif // !FANTASIA_H