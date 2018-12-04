#ifndef ENEMY_H
#define ENEMY_H

#include "Stats.h"
#include "Attack.h"
#include <vector>
#include <memory>
#include <cstdlib>

using namespace std;

//Enemy class
class Enemy
{
public:
	Enemy();
	virtual ~Enemy();

	//Calculates recieving damage based on resistance, weakness, and attack
	void takeDamage(Attack a);

	//Decides an action that the enemy takes during their turn
	virtual Attack attackDecision() = 0;

	string getName();

	string getLog();

protected:
	//Creates an attack against the player
	Attack enAttack(); // all enemies must have at least one basic attack.

	//Keeps track of stats (dynamically allocated)
	Stats * stats;

	//current HP
	int currHP;

	//Attacks available to an enemy
	int attackAmount = 1;

	//Lists of strengths and weaknesses pertaining to the enemy
	std::vector<Element> strengths;
	std::vector<Element> weaknesses;

	//Name of the enemy
	string name;

	//Log of the enemy's actions
	string log = "";
};


#endif // ENEMY_H
