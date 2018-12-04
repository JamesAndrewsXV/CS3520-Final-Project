#ifndef STAFF_H
#define STAFF_H

#include "../Equippable.h"

class Staff : public Equippable
{
public:

	Staff()
	{
		Equippable(new Stats(0, 3, 0, 8, 0), 
			"Wizard's Staff", 
			Kind::WEAPON, Range::CLOSE, Element::NEUTRAL, Element::NONE);
	}
protected:
private:
};

#endif // !WOODSWORD_H
