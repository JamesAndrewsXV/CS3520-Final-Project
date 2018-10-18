#ifndef ENEMY_H
#define ENEMY_H

#include "Stats.h"
#include "Types.h"
#include <vector>
//#include loot table

//Enemy class
class Enemy
{
public:
	Enemy();
	~Enemy();

protected:
	Stats *stats;
	std::vector<Element> strengths;
	std::vector<Element> weaknesses;
	int enAttack(); // all enemies must have at least one basic attack.
};





#endif // ENEMY_H
