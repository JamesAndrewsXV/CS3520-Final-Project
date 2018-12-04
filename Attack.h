#ifndef ATTACK_H
#define ATTACK_H

enum Element {
	FLAME,
	WAVE,
	ELECTRICITY,
	TERRA,
	HOLY,
	CURSE,
	NEUTRAL, 
};

enum Range {
	CLOSE,
	FAR,
	MAGIC,
	
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
