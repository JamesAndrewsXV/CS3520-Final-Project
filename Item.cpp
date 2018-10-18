#include Item.h
#include <iostream>
#include <vector>

using namespace std;

class Item {
	public:
	//Creates an Item using given parameter
	Item(int damage, ItemType type, vector<Element, int> bonusDamage, vector<Stat, int> buffs, vector<Ability> abilities) {
		damage = damage;
		type = type;
		bonusDamage = bonusDamage;
		buffs = buffs;
		abilities = abilities;
	}
    //Creates an Item using random parameters
	Item randomItem() {
		return new Item //Random inputs here
	}	
	//Destroys an Item
	
	//Deal damage with item
	
	private:
	int damage;
	ItemType type;
	vector<Element, int> bonusDamage;
	vector<Stat, int> buffs;
	vector<Ability> abilities;
	//Includes some sort of indication as to which sprite to use
}

enum ItemType{};

enum Element{};

enum Stat{};

enum Ability{};