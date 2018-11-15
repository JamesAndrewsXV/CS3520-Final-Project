#ifndef ENEMY_H
#define ENEMY_H

#include "Stats.h"
#include "Attack.h"
#include <vector>
#include <memory>
//#include loot table

//Enemy class
class Enemy
{
public:
	Enemy();
	~Enemy();

	//Calculates recieving damage based on resistance, weakness, and attack
	void takeDamage(Attack a);

	//Decides an action that the enemy takes during their turn
	

	static std::unique_ptr<Enemy> build_enemy() {
		// get random number in choice
		Enemy * enemy;
		int choice = 0;
		switch (choice) {
		case 0: enemy = new Wraith(); break;
		default: enemy = new Imp(); break;
		}
		return std::unique_ptr(enemy);
	}

protected:
	//Creates an attack against the player
	Attack enAttack(); // all enemies must have at least one basic attack.

	//Keeps track of stats (dynamically allocated)
	Stats * stats;

	//current HP
	int currHP;

	//Lists of strengths and weaknesses pertaining to the enemy
	std::vector<Element> strengths;
	std::vector<Element> weaknesses;

};





#endif // ENEMY_H
