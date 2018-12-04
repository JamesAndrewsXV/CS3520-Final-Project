#ifndef MASAMUNE_H
#define MASAMUNE_H

#include "../Equippable.h"

class Masamune : public Equippable
{
public:

	Masamune()
	{
		Equippable(new Stats(0, 60, 0, 45, 0), "Masamune", Kind::WEAPON, Range::CLOSE, Element::CURSE, Element::NONE);
	}
protected:
private:
};

#endif // !MASAMUNE_H