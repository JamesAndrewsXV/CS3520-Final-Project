#ifndef IRONGREAVES_H
#define IRONGREAVES_H

#include "../Equippable.h"

class IronGreaves :public Equippable
{
public:
	IronGreaves()
	{
		Equippable(new Stats(0, 9, 20, 0, 8), 
			"Iron Greaves", 
			Kind::SHOES, Range::NO, Element::NEUTRAL, Element::FLAME);
	}
};


#endif // !IRONGREAVES_H

