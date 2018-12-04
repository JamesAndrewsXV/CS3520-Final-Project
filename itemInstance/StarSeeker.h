#ifndef STARSEEKER_H
#define STARSEEKER_H

#include "../Equippable.h"

class StarSeeker : public Equippable
{
public:

	StarSeeker()
	{
		Equippable(new Stats(0, 13, 0, 19, 0),
			"StarSeeker", 
			Kind::WEAPON, Range::CLOSE, Element::HOLY, Element::NONE);
	}
protected:
private:
};

#endif // !STARSEEKER_H