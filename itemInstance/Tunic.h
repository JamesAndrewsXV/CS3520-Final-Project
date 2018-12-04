#ifndef TUNIC_H
#define TUNIC_H

#include "../Equippable.h"

class Tunic :public Equippable
{
public:
	Tunic()
	{
		Equippable(new Stats(20, 0, 4, 0, 5), 
			"Tunic", 
			Kind::CHEST, Range::NO, Element::NONE, Element::FLAME);
	}
};


#endif // !TUNIC_H

