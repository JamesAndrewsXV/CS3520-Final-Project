#ifndef DRACULA_H
#define DRACULA_H

#include "../Boss.h"
class Dracula : public Boss
{
public:
	Dracula()
	{
		this->stats = new Stats(400, 150, 80, 110, 65);
		this->currHP = this->stats->HP;
		this->strengths = { Element::FLAME, Element::CURSE, Element::WAVE, Element::NEUTRAL, Element::CURSE };
		this->weaknesses = {};
		this->weakenElement = Element::HOLY;
		this->weakenRange = Range::MAGIC;
		this->staticWeaknesses = { Element::HOLY, Element::NEUTRAL, Element::WAVE };
		this->name = "Dracula";
		this->attackAmount = 4;
	}

	Attack Enemy::attackDecision()
	{
		switch (rand() % this->attackAmount)
		{
		case 0:
			return this->enAttack();
		case 1:
			return this->daAttack();
		case 2:
			return this->daAttack2();
		case 3:
			return this->daAttack3();
		}
	}

private:
	Attack daAttack()
	{
		this->log = "Dracula drains your blood!\n";
		Attack a;
		a.attack = this->stats->att;
		a.elem = Element::NEUTRAL;
		a.range = Range::CLOSE;
		this->currHP += 20;
		return a;
	}

	Attack daAttack2()
	{
		this->log = "Dracula hurls dark balls!\n";
		Attack a;
		a.attack = this->stats->wis * 1.2;
		a.elem = Element::CURSE;
		a.range = Range::MAGIC;
		return a;
	}

	Attack daAttack3()
	{
		this->log = "Dracula conjures dark blue flames!\n";
		Attack a;
		a.attack = this->stats->wis * 1.2;
		a.elem = Element::FLAME;
		a.range = Range::MAGIC;
		return a;
	}

};

#endif