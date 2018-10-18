#pragma once
#ifndef _ROOM_H
#define _ROOM_H
#endif

//#include "Map.h"
#include <vector>
#include <iostream>
#include <random>
#include <time.h>
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
	Room(Room&& other);

	// room move assignment constructor
	Room& operator=(Room&& other);

	// adds up to four rooms to this room
	void connectRooms();

	// if this room has loot add loot
	void setLoot();

	// prints "there's loot" if there is loot for now
	void printLoot();

	// sets the map that this room exist in
	//void setMap(Map * map);
private:
	// the (at most four) rooms bordering this room
	vector<Room> adjacent_rooms;

	// is there a random encounter in this room
	bool encounter;

	// is there loot in this room
	bool containLoot;

	// the loot contained in the room
	string loot;

	// the map this room is a part of
	//Map this_map;

	// copies member variables of rooms
	void copyfrom(Room other);

	// moves member variables of rooms from another to this one
	void movefrom(Room other);
};
