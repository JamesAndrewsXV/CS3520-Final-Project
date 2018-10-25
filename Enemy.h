#ifndef ENEMY_H
#define ENEMY_H

#include "Stats.h"
#include "Types.h"
#include "Attack.h"
#include <vector>
//#include loot table

//Enemy class
class Enemy
{
public:
	Enemy();
	~Enemy();

	//Calculates recieving damage based on resistance, weakness, and attack
	void takeDamage(Attack a);

	//Creates an attack against the player
	Attack enAttack(); // all enemies must have at least one basic attack. Implementation specific.

protected:

	//Keeps track of stats (dynamically allocated)
	Stats * stats;

	//current HP
	int currHP;

	//Lists of strengths and weaknesses pertaining to the enemy
	std::vector<Element> strengths;
	std::vector<Element> weaknesses;

};





#endif // ENEMY_H
