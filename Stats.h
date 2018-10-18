#ifndef STATS_H
#define STATS_H
#include "Enemy.h"
#include <vector>

//#include player character
class Stats
{
public:

	Stats(Enemy *e, int hp, double att, double def, double wis, double intel);
	double *getStats();
	void change(std::vector<Buffs> b, std::vector<double> changes);

private:
	Enemy * eEnemy;
	//Player* ePlayer;
	int HP;
	double att;
	double def;
	double wis;
	double intel;

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
