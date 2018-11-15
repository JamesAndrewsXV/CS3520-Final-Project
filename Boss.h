#ifndef BOSS_H
#define BOSS_H

#include "Enemy.h"

class Boss : public Enemy
{
public:
	Boss();
	~Boss();
	void exploitWeakness();
	void recoverWeakness();
	Attack enAttack();

protected:
	Element weakenElement;
	Range weakenRange;
	BossState state = BossState::NORMAL;
	std::vector<Element> staticWeaknesses;
	int recoveryTurns = 0;
};

enum BossState
{
	NORMAL,
	WEAK
};

#endif // !
