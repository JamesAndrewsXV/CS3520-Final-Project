#ifndef FANTASIA_H
#define FANTASIA_H

#include "Equippable.h"

class Fantasia : public Equippable
{
public:

	Fantasia()
	{
		this->bonus = new Stats(0, 25, 0, 40, 0);
		this->range = Range::MAGIC;
		this->kind = Kind::WEAPON;
		this->strength = Element::HOLY;
		this->name = "Fantasia";
	}
protected:
private:
};

#endif // !FANTASIA_H