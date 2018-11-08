#ifndef ATTACK_H
#define ATTACK_H

struct Attack {
	//Attack power
	int attack;

	//Element property
	Element elem;

	//Attack Range
	Range range;
};

enum Element {
	FLAME,
	WAVE,
	ELECTRICITY,
	TERRA,
	HOLY,
	CURSE,
	NEUTRAL
};

enum Range {
	CLOSE,
	FAR,
	MAGIC
};

#endif // ATTACK_H
