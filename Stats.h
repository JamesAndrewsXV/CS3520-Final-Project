#ifndef STATS_H
#define STATS_H
//#include "Enemy.h"
#include <vector>

//Applied towards specific stat changes, with details in item category.
//(moved to top because of use in change method)
enum Buffs {
	HEALTH,
	ATTACK,
	DEFENSE,
	WISDOM,
	INTELLIGENCE
};


//#include player character
class Stats
{
public:

	Stats(int hp, int att, int def, int wis, int intel);
	double *getStats();
	void change(std::vector<Buffs> b, std::vector<int> changes);

private:
	int HP;
	int att;
	int def;
	int wis;
	int intel;

};








#endif // ENEMY_H
