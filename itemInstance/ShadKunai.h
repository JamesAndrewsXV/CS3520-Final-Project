#ifndef SHADKUNAI_H
#define SHADKUNAI_H

#include "../Equippable.h"

class ShadKunai : public Equippable
{
public:

	ShadKunai()
	{
		this->bonus = new Stats(0, 35, 0, 20, 0);
		this->range = Range::FAR;
		this->kind = Kind::WEAPON;
		this->strength = Element::CURSE;
		this->name = "Shadow Kunai";
	}
protected:
private:
};

#endif // !FANTASIA_H