#ifndef SHEPHERDS_H
#define SHEPHERDS_H

#include "../Equippable.h"

class Shepherds :public Equippable
{
public:
	Shepherds()
	{
		this->bonus = new Stats(15, 0, 3, 0, 5);
		this->kind = Kind::CHEST;
		this->name = "Sheperd's Garb";
	}
};


#endif // !SHEPHERDS_H


