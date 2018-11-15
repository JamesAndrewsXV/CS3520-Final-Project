#ifndef KNIGHTHELM_H
#define KNIGHTHELM_H

#include "Equippable.h"

class KnightHelm :public Equippable
{
public:
	KnightHelm()
	{
		this->bonus = new Stats(25, 0, 6, 0, 1);
		this->kind = Kind::HELM;
		this->name = "Knight's Helm";
	}
};


#endif // !KNIGHTHELM_H

