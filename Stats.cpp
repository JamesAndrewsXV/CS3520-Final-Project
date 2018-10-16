#include "Stats.h"

double *Stats::getStats()
{
	double stats[] = { this->att, this->def, this->wis, this->intel };
	return stats;
}
