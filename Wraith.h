#ifndef WRAITH_H
#define WRAITH_H


#include "Enemy.h"
class Wraith : Enemy
{
public:
	Wraith();
	~Wraith();

	//Attack exclusive to wraiths (magic type)
	Attack wrAttack();
protected:

private:
};

#endif // !