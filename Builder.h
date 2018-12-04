#ifndef BUILDER_H
#define BUILDER_H
#include "enemyInstance/AllCommon.h"
#include "enemyInstance/AllBoss.h"
#include "itemInstance/AllArmor.h"
#include "itemInstance/AllWeapons.h"




static std::unique_ptr<Enemy> buildEnemy() {
	// get random number in choice
	int choice = std::rand() % 6;

	switch (choice) {
	case 0: return std::unique_ptr<Enemy>(new Wraith()); break;
	case 1: return std::unique_ptr<Enemy>(new Imp()); break;
	case 2: return std::unique_ptr<Enemy>(new Lamia()); break;
	case 3: return std::unique_ptr<Enemy>(new Anubis()); break;
	case 4: return std::unique_ptr<Enemy>(new Goblin()); break;
	case 5: return std::unique_ptr<Enemy>(new Reaper()); break;
	default: return std::unique_ptr<Enemy>(new Wraith()); break;
	}
}


static std::unique_ptr<Boss> buildBoss() {
	// get random number in choice
	int choice = std::rand() % 2;

	switch (choice) {
	case 0: return std::unique_ptr<Boss>(new Bahamut()); break;
	case 1: return std::unique_ptr<Boss>(new Dracula()); break;
	default: return std::unique_ptr<Boss>(new Bahamut()); break;
	}

}

//Creates an Item using random parameters
static std::unique_ptr<Item> buildItem() {
	// get random number in choice
	int choice = std::rand() % 21;
	switch (choice) {
	case 0: return std::unique_ptr<Item>(new AncientGarb()); break;
	case 1: return std::unique_ptr<Item>(new Breastplate()); break;
	case 2: return std::unique_ptr<Item>(new BurningWhip()); break;
	case 3: return std::unique_ptr<Item>(new BusterShield()); break;
	case 4: return std::unique_ptr<Item>(new CombatBoots()); break;
	case 5: return std::unique_ptr<Item>(new DeceasedGauntlet()); break;
	case 6: return std::unique_ptr<Item>(new Fantasia()); break;
	case 7: return std::unique_ptr<Item>(new FocusBand()); break;
	case 8: return std::unique_ptr<Item>(new Halo()); break;
	case 9: return std::unique_ptr<Item>(new IronGreaves()); break;
	case 10: return std::unique_ptr<Item>(new KnightHelm()); break;
	case 11: return std::unique_ptr<Item>(new LeviathanBoots()); break;
	case 12: return std::unique_ptr<Item>(new Masamune()); break;
	case 13: return std::unique_ptr<Item>(new ShadKunai()); break;
	case 14: return std::unique_ptr<Item>(new Shepherds()); break;
	case 15: return std::unique_ptr<Item>(new SpiritArrow()); break;
	case 16: return std::unique_ptr<Item>(new Staff()); break;
	case 17: return std::unique_ptr<Item>(new StarSeeker); break;
	case 18: return std::unique_ptr<Item>(new ThorHammer()); break;
	case 19: return std::unique_ptr<Item>(new Tunic()); break;
	case 20: return std::unique_ptr<Item>(new WoodSword()); break;
	default: return std::unique_ptr<Item>(new AncientGarb()); break;
	}

	

}



#endif // ! BUILDER_H
