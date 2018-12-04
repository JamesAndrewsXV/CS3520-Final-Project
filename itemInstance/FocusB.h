#ifndef FOCUSB_H
#define FOCUSB_H

#include "../Equippable.h"

class FocusBand :public Equippable
{
public:
	FocusBand()
	{
		Equippable(new Stats(10, 5, 14, 0, 4), "Focus Sash", Kind::HELM, Range::NONE, Element::NONE, Element::NONE);
	}
};


#endif // !FOCUSB_H

