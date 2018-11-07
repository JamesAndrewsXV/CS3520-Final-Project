#include "Stats.h"
#include <algorithm>

using namespace std;

Stats::Stats(int hp, int att, int def, int wis, int intel)
{
	this->HP = hp;
	this->att = att;
	this->def = def;
	this->wis = wis;
	this->intel = intel;
}

Stats & Stats::operator+=(const Stats & other)
{
	this->HP += other.HP;
	this->att += other.att;
	this->def += other.def;
	this->wis += other.wis;
	this->intel += other.intel;

	return *this;
}

Stats & Stats::operator-=(const Stats & other)
{
	this->HP = std::max(this->HP - other.HP, 0);
	this->att = std::max(this->att - other.att, 0);
	this->def = std::max(this->def - other.def, 0);
	this->wis = std::max(this->def - other.wis, 0);
	this->intel = std::max(this->def - other.intel, 0);

	return *this;
}