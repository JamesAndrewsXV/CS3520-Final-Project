#ifndef BOSS_H
#define BOSS_H

enum BossState
{
	NORMAL,
	WEAK
};

#include "Enemy.h"

class Boss : public Enemy
{
public:
	Boss();
	
	virtual ~Boss();
	void exploitWeakness();
	void recoverWeakness();


protected:
	Element weakenElement;
	Range weakenRange;
	BossState state = BossState::NORMAL;
	std::vector<Element> staticWeaknesses;
	int recoveryTurns = 0;
};



#endif // !
