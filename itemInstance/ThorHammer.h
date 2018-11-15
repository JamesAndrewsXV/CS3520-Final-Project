#ifndef THORHAMMER_H
#define THORHAMMER_H

#include "../Equippable.h"

class ThorHammer : public Equippable
{
public:

	ThorHammer()
	{
		this->bonus = new Stats(0, 13, 0, 19, 0);
		this->range = Range::CLOSE;
		this->kind = Kind::WEAPON;
		this->strength = Element::HOLY;
		this->name = "Thor's Hammer";
	}
protected:
private:
};

#endif // !THORHAMMER_H
