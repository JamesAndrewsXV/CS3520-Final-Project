#ifndef BAHAMUT_H
#define BAHAMUT_H

#include "Boss.h"
class Bahamut : public Boss
{
public:
	Bahamut();
	~Bahamut();

	Attack baAttack();
	Attack baAttack2();
	Attack baAttack3();
};

#endif