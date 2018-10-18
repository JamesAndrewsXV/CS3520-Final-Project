#ifndef STATS_H
#define STATS_H
#include "Enemy.h"
#include <vector>

//#include player character
class Stats
{
public:

	Stats(Enemy *e, int hp, int att, int def, int wis, int intel);
	double *getStats();
	void change(std::vector<Buffs> b, std::vector<int> changes);

private:
	Enemy * eEnemy;
	//Player* ePlayer;
	int HP;
	int att;
	int def;
	int wis;
	int intel;

};

//Applied towards specific stat changes, with details in item category.
enum Buffs {
	HEALTH,
	ATTACK,
	DEFENSE,
	WISDOM,
	INTELLIGENCE
};







#endif // ENEMY_H
