#ifndef EQUIPPABLE_H
#define EQUIPPABLE_H



#include "Item.h"
#include "Attack.h"
#include <string>
#include <cstdlib>

//Kind of equippable
enum Kind
{
	WEAPON,
	HELM,
	CHEST,
	GLOVES,
	SHOES
};
class Equippable : public Item {
public:
	//Constructor
	Equippable();
	Equippable(Stats *bonus, std::string name, Kind kind, Range range, Element strength, Element weakness);

	//Destructor
	virtual ~Equippable();

	//Returns the kind of item this is.
	Kind getKind();

	//Returns strength of the given item
	Element getStrength();

	//Returns the weakness of the given item.
	Element getWeakness();

	//Returns the range of the given item.
	Range getRange();

protected:
	Kind kind;
	Range range;
	Element strength; // does the multiplier cover this?
	Element weakness; // does the multiplier cover this?
	//Includes some sort of indication as to which sprite to use
};
#endif // !EQUIPPABLE_H
