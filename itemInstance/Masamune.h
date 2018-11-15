#ifndef MASAMUNE_H
#define MASAMUNE_H

#include "../Equippable.h"

class Masamune : public Equippable
{
public:

	Masamune()
	{
		this->bonus = new Stats(0, 60, 0, 45, 0);
		this->range = Range::CLOSE;
		this->kind = Kind::WEAPON;
		this->strength = Element::CURSE;
		this->name = "Masamune";
	}
protected:
private:
};

#endif // !MASAMUNE_H