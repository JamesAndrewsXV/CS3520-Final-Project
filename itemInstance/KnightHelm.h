#ifndef KNIGHTHELM_H
#define KNIGHTHELM_H

#include "../Equippable.h"

class KnightHelm :public Equippable
{
public:
	KnightHelm()
	{
		Equippable(new Stats(25, 0, 6, 0, 1), 
			"Knight's Helm", 
			Kind::HELM, Range::NO, Element::NONE, Element::NONE);
	}
};


#endif // !KNIGHTHELM_H

