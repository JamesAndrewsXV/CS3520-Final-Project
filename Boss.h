#ifndef BOSS_H
#define BOSS_H

#include "Enemy.h"
#include "enemyInstance/AllBoss.h"

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
	static int bossAmount = 2;
};

enum BossState
{
	NORMAL,
	WEAK
};

#endif // !
