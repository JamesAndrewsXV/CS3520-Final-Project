#ifndef FANTASIA_H
#define FANTASIA_H

#include "../Equippable.h"

class Fantasia : public Equippable
{
public:

	Fantasia()
	{
		Equippable(new Stats(0, 25, 0, 40, 0), 
			"Fantasia", 
			Kind::WEAPON, Range::FAR, Element::HOLY, Element::NONE);
	}
protected:
private:
};

#endif // !FANTASIA_H