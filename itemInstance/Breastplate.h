#ifndef BREASTPLATE
#define BREASTPLATE

#include "../Equippable.h"

class Breastplate :public Equippable
{
public:
	Breastplate()
	{
		this->bonus = new Stats(20, 0, 10, 0, 2);
		this->kind = Kind::CHEST;
		this->name = "Breastplate";
	}
};


#endif // !BREASTPLATE_H

