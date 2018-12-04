#ifndef FOCUSB_H
#define FOCUSB_H

#include "../Equippable.h"

class FocusBand :public Equippable
{
public:
	FocusBand()
	{
		this->bonus = new Stats(10, 5, 14, 0, 4);
		this->kind = Kind::HELM;
		this->name = "Focus Sash";
	}
};


#endif // !FOCUSB_H

