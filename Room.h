#pragma once
#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
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

	// if this room has loot add loot
	void setLoot();

	// prints "there's loot" if there is loot for now -> testing
	void printLoot();

	// count adjacentRooms -> for testing!
	int countAdjacentRooms();

	//return true if there is an encounter
	const bool getEncounter();

	//return true if there is loot
	const bool getLoot();



private:
	// the (at most four) rooms bordering this room
	vector<Room*> adjacentRooms;

	// is there a random encounter in this room
	bool encounter;

	// is there loot in this room
	bool containLoot;

	// the loot contained in the room -> placeholder
	string loot;

	// copies member variables of rooms
	void copyfrom(Room other);

	// moves member variables of rooms from another to this one
	void movefrom(Room other);
};

#endif
