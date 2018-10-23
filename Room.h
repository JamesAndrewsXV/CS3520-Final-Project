#pragma once
#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include <iostream>
#include <string>
#include "Imp.h"
#include "Item.h"
using namespace std;

// class representing the list of rooms the player traverses through
class Room {
public:
	// constructor for a room
	Room();

	// room copy assignment operator
	Room & operator= (const Room & other);

	// room copy constructor
	Room(const Room & other);

	// room move constructor
	//Room(Room&& other);

	// room move assignment constructor
	//Room& operator=(Room&& other);

	// adds up to four rooms to this room
	void connectRoom(Room * room);

	// count adjacentRooms -> for testing!
	void countAdjacentRooms();

	// the (at most four) rooms bordering this room
	vector<Room*> adjacentRooms;

private:
	// is there a random encounter in this room
	bool encounter;

	// is there loot in this room
	bool containLoot;

	// the loot contained in the room
	Item * loot;

	// the monster in the room
	Imp * monster;

	// copies member variables of rooms
	void copyfrom(Room other);

	// moves member variables of rooms from another to this one
	//void movefrom(Room other);

	// if there is an encounter, generate an enemy in the room
	void setEncounter();

	// if this room has loot add loot
	void setLoot();
};

#endif
