#pragma once
#ifndef BATTLESCENE_H
#define BATTLESCENE_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;

// class representing a room where a battle is taking place
class BattleScene {
public:
	BattleScene(Room * r, Enemy * e, Player * p);
	~BattleScene();


private:
	Room * room;
	Enemy * enemy;
	Player * player;
	stringstream battleLog;
	bool isPlayerTurn;
	//destructor should deal with win/lose state
};

#endif
