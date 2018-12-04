#ifndef SHADKUNAI_H
#define SHADKUNAI_H

#include "../Equippable.h"

class ShadKunai : public Equippable
{
public:

	ShadKunai()
	{
		Equippable(
			new Stats(0, 35, 0, 20, 0),
			"Shadow Kunai",
			Kind::WEAPON, Range::FAR, Element::CURSE, Element::NONE);
	}
protected:
private:
};

#endif // !FANTASIA_H