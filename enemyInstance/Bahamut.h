#ifndef BAHAMUT_H
#define BAHAMUT_H

#include "../Boss.h"
class Bahamut : public Boss
{
public:
	Bahamut()
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
		this->recoverWeakness();
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

private:
	Attack baAttack()
	{
		this->log = "Bahamut charges a flaming inferno!\n";
		Attack a;
		a.attack = this->stats->wis * 1.3;
		a.elem = Element::FLAME;
		a.range = Range::MAGIC;
		return a;
	}

	Attack baAttack2()
	{
		this->log = "Bahamut hits with a charged claw!\n";
		Attack a;
		a.attack = this->stats->att * 1.1;
		a.elem = Element::ELECTRICITY;
		a.range = Range::CLOSE;
		return a;
	}

	Attack baAttack3()
	{
		this->log = "Bahamut blasts with shocking breath!\n";
		Attack a;
		a.attack = this->stats->wis;
		a.elem = Element::ELECTRICITY;
		a.range = Range::MAGIC;
		return a;
	}

};

#endif