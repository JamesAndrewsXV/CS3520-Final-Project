#ifndef STARSEEKER_H
#define STARSEEKER_H

#include "../Equippable.h"

class StarSeeker : public Equippable
{
public:

	StarSeeker()
	{
		this->bonus = new Stats(0, 13, 0, 19, 0);
		this->range = Range::MAGIC;
		this->kind = Kind::WEAPON;
		this->strength = Element::HOLY;
		this->name = "StarSeeker";
	}
protected:
private:
};

#endif // !STARSEEKER_H