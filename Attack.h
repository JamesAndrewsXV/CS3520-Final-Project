#ifndef ATTACK_H
#define ATTACK_H

#include "Types.h"
class Attack
{
public:
	//Constructs an attack, with properties given to either the player or the enemy class.
	Attack(int att, Element elem, Range rng);

	//Gets the strength of the attack
	int getAttack();

	//Gets the attack's elemental value
	Element getElem();

	//Gets the attack's range
	Range getRange();

private:

	//Attack power
	int attack;

	//Element property
	Element elem;

	//Attack Range
	Range range;
};



#endif // ATTACK_H
