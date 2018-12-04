#ifndef COMBATBOOTS_H
#define COMBATBOOTS_H

#include "../Equippable.h"

class CombatBoots :public Equippable
{
public:
	CombatBoots()
	{
		Equippable(new Stats(0, 3, 8, 0, 5),
			"Combat Boots", 
			Kind::SHOES, Range::NO, Element::NONE, Element::NONE);
	}
};


#endif // !COMBATBOOTS_H


