#ifndef WRAITH_H
#define WRAITH_H


#include "Enemy.h"
#include "Attack.h"
class Wraith : Enemy
{
public:
	Wraith();
	~Wraith();
	Attack wrAttack();
protected:

private:
};

#endif // !