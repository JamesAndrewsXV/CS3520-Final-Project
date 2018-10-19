#ifndef ATTACK_H
#define ATTACK_H

#include "Types.h"
class Attack
{
public:
	Attack(int att, Element elem, Range rng);
	int getAttack();
	Element getElem();
	Range getRange();

private:
	int attack;
	Element elem;
	Range range;
};



#endif // ATTACK_H
