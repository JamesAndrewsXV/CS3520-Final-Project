#ifndef THORHAMMER_H
#define THORHAMMER_H

#include "../Equippable.h"

class ThorHammer : public Equippable
{
public:

	ThorHammer()
	{
		Equippable(new Stats(0, 13, 0, 19, 0),
			"Thor's Hammer",
			Kind::WEAPON, Range::CLOSE, Element::ELECTRICITY, Element::NONE);
	}
protected:
private:
};

#endif // !THORHAMMER_H
