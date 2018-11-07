#ifndef STATS_H
#define STATS_H
#include <vector>

//#include player character

//Acts as a container for stats of players, item bonuses, and enemies
class Stats
{
public:

	Stats(int hp, int att, int def, int wis, int intel);
	Stats& Stats::operator+= (const Stats & other);

	Stats & operator-=(const Stats & other);

	int HP;
	int att;
	int def;
	int wis;
	int intel;

};








#endif // ENEMY_H
