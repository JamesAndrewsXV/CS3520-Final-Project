#ifndef COMBATBOOTS_H
#define COMBATBOOTS_H

#include "../Equippable.h"

class CombatBoots :public Equippable
{
public:
	CombatBoots()
	{
		this->bonus = new Stats(0, 3, 8, 0, 5);
		this->kind = Kind::SHOES;
		this->name = "Combat Boots";
	}
};


#endif // !COMBATBOOTS_H


