#ifndef SHEPHERDS_H
#define SHEPHERDS_H

#include "../Equippable.h"

class Shepherds :public Equippable
{
public:
	Shepherds()
	{
		Equippable(
			new Stats(15, 0, 3, 0, 5), 
			"Sheperd's Garb", 
			Kind::CHEST, Range::NO, Element::NONE, Element::FLAME);
	}
};


#endif // !SHEPHERDS_H


