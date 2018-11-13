#include "Bahamut.h"

Bahamut::Bahamut()
{
	this->stats = new Stats(400, 85, 70, 90, 70);
	this->currHP = this->stats->HP;
	this->strengths = { Element::FLAME, Element::ELECTRICITY, Element::WAVE, Element::NEUTRAL, Element::CURSE };
	this->weaknesses = {};
	this->weakenElement = Element::TERRA;
	this->weakenRange = Range::FAR;
	this->staticWeaknesses = { Element::ELECTRICITY, Element::ELECTRICITY, Element::NEUTRAL };
}


Bahamut::~Bahamut()
{

}
