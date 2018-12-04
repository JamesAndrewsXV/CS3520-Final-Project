#ifndef ATTACK_H
#define ATTACK_H

using namespace std;

enum Element {
	FLAME,
	WAVE,
	ELECTRICITY,
	TERRA,
	HOLY,
	CURSE,
	NEUTRAL, 
	NONE
};

enum Range {
	CLOSE,
	FAR,
	MAGIC,
	NONE
};
struct Attack {
	//Attack power
	int attack;

	//Element property
	Element elem;

	//Attack Range
	Range range;
};



#endif // ATTACK_H
