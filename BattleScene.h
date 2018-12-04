#pragma once
#ifndef BATTLESCENE_H
#define BATTLESCENE_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <string>
#include "Room.h"
#include "Player.h"
#include "Enemy.h"
#include "Builder.h"
#include "Item.h"
#include <vector>
using namespace std;

// class representing a room where a battle is taking place
class BattleScene {
public:
	BattleScene(Room * room, Player * player);
	~BattleScene();
	vector<Item> openInventory();
	string promptAttack();
	string attack(string attackType);
	string displayStats();
	string displayBattleLog();

private:
	void updateStats();

	Room * room;
	Enemy * enemy;
	Player * player;
	string battleLog;
	string statsLog;
	bool isPlayerTurn;
	//destructor should deal with win/lose state
};

#endif
