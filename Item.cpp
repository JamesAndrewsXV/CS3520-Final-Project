#include Item.h
#include <iostream>
#include <vector>

using namespace std;

class Item {
	public:
	//Creates an Item using given parameter
	
    //Creates an Item using random parameters
	
	//Destroys an Item
	
	//Deal damage with item
	private:
	int damage;
	ItemType type;
	vector<Element, int> bonusDamage;
	vector<Stat, int> buffs;
	vector<Ability> abilities;
}

enum ItemType{};

enum Element{};

enum Stat{};

enum Ability{};