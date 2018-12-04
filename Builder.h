#ifndef BUILDER_H
#define BUILDER_H
#include "Enemy.h"
#include "enemyInstance/AllCommon.h"
#include "enemyInstance/AllBoss.h"
#include "Item.h"
#include "itemInstance/AllArmor.h"
#include "itemInstance/AllWeapons.h"

int bossAmount = 2;
int enemyAmount = 0;
int itemAmount = 0;

static std::unique_ptr<Enemy> buildEnemy() {
	// get random number in choice
	Enemy * enemy;
	int choice = std::rand() % enemyAmount;
	switch (choice) {
	case 0: enemy = new Wraith(); break;
	case 1: enemy = new Imp(); break;
	case 2: enemy = new Lamia(); break;
	case 3: enemy = new Anubis(); break;
	case 4: enemy = new Goblin(); break;
	case 5: enemy = new Reaper(); break;
	}
	return std::unique_ptr<Enemy>(enemy);
}


static std::unique_ptr<Boss> buildBoss() {
	// get random number in choice
	Boss * enemy;
	int choice = std::rand() % bossAmount;
	switch (choice) {
	case 0: enemy = new Bahamut(); break;
	case 1: enemy = new Dracula(); break;
	}
	return std::unique_ptr<Boss>(enemy);
}

//Creates an Item using random parameters
static std::unique_ptr<Item> buildItem() {
	// get random number in choice
	Item * item;
	int choice = std::rand() % itemAmount;
	switch (choice) {
	case 0: item = new AncientGarb(); break;
	case 1: item = new Breastplate(); break;
	case 2: item = new BurningWhip(); break;
	case 3: item = new BusterShield(); break;
	case 4: item = new CombatBoots(); break;
	case 5: item = new DeceasedGauntlet(); break;
	case 6: item = new Fantasia(); break;
	case 7: item = new FocusBand(); break;
	case 8: item = new Halo(); break;
	case 9: item = new IronGreaves(); break;
	case 10: item = new KnightHelm(); break;
	case 11: item = new LeviathanBoots(); break;
	case 12: item = new Masamune(); break;
	case 13: item = new ShadKunai(); break;
	case 14: item = new Shepherds(); break;
	case 15: item = new SpiritArrow(); break;
	case 16: item = new Staff(); break;
	case 17: item = new StarSeeker; break;
	case 18: item = new ThorHammer(); break;
	case 19: item = new Tunic(); break;
	case 20: item = new WoodSword(); break;
	}
	return std::unique_ptr<Item>(item);
}

#endif // ! BUILDER_H
