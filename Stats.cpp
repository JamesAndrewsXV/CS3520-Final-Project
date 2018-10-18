#include "Stats.h"
#include "Enemy.h"



Stats::Stats(Enemy *e, int hp, double att, double def, double wis, double intel)
{
	this->eEnemy = e;
	this->HP = hp;
	this->att = att;
	this->def = def;
	this->wis = wis;
	this->intel = intel;
}

double *Stats::getStats()
{
	double stats[] = { this->HP, this->att, this->def, this->wis, this->intel };
	return stats;
}

//void Stats::change(std::vector<Buffs> b)
//{
//	for (Buffs buff : b) {
//		switch (buff)
//		{
//		case HEALTH:
//			this->HP = 
//		case ATTACK:
//		case DEFENSE:
//		case WISDOM:
//		case INTELLIGENCE:
//		}
//	}
