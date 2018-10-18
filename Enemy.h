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
	void takeDamage(Element elem, int damage);
	int enAttack(); // all enemies must have at least one basic attack.

protected:
	Stats *stats;
	int currHP;
	std::vector<Element> strengths;
	std::vector<Element> weaknesses;
	
};





#endif // ENEMY_H
