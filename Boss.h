#ifndef BOSS_H
#define BOSS_H

#include "Enemy.h"
#include "enemyInstance/AllBoss.h"

class Boss : public Enemy
{
public:
	Boss();
	Boss(
		Stats *stats, std::vector<Element> strengths,
		std::vector<Element> weaknesses, string name,
		Element weakenElement, Range weakenRange,
		std::vector<Element> staticWeaknesses) : Enemy(stats, strengths, weaknesses, name);
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

enum BossState
{
	NORMAL,
	WEAK
};

#endif // !
