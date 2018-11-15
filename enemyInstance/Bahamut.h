#ifndef BAHAMUT_H
#define BAHAMUT_H

#include "../Boss.h"
class Bahamut : public Boss
{
public:
	Bahamut::Bahamut()
	{
		this->stats = new Stats(400, 120, 70, 100, 70);
		this->currHP = this->stats->HP;
		this->strengths = { Element::FLAME, Element::ELECTRICITY, Element::WAVE, Element::NEUTRAL, Element::CURSE };
		this->weaknesses = {};
		this->weakenElement = Element::TERRA;
		this->weakenRange = Range::FAR;
		this->staticWeaknesses = { Element::ELECTRICITY, Element::ELECTRICITY, Element::NEUTRAL };
		this->name = "Bahamut";
		this->attackAmount = 4;
	}

	Attack Enemy::attackDecision()
	{
		switch (rand() % this->attackAmount)
		{
		case 0:
			return this->enAttack();
		case 1:
			return this->baAttack();
		case 2:
			return this->baAttack2();
		case 3:
			return this->baAttack3();
		}
	}

	Bahamut::~Bahamut() {}
private:
	Attack Bahamut::baAttack()
	{
		return Attack{ this->stats->wis * 1.3, Element::FLAME, Range::MAGIC };
	}

	Attack Bahamut::baAttack2()
	{
		return Attack{ this->stats->att * 1.1, Element::ELECTRICITY, Range::CLOSE };
	}

	Attack Bahamut::baAttack3()
	{
		return Attack{ this->stats->wis, Element::ELECTRICITY, Range::MAGIC };
	}

};

#endif