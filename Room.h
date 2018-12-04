#ifndef ROOM_H
#define ROOM_H

#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;

// class representing the list of rooms the player traverses through
class Room {
public:
	// constructor for a room
	Room();

	//Room destructor
	~Room();

	// room copy assignment operator
	Room & operator= (const Room & other);

	// room copy constructor
	Room(const Room & other);

	// adds up to four rooms to this room. returns false if this room has no space
	bool connectRoom(Room * room);

	// if this room has loot add loot
	void setLoot(bool l);

	// prints "there's loot" if there is loot for now -> testing
	void printLoot();

	// count adjacentRooms -> for testing!
	int countAdjacentRooms();

	//return true if there is an encounter
	const bool getEncounter();

	//sets the encounter to false
	void setEncounter(bool enc);

	//return true if there is loot
	const bool getLoot();

	//return the adjacent rooms
	vector<Room*> * getAdjacentRooms();

	//sets the adjacent rooms
	void setAdjacentRooms();

	//return the map of adjacent rooms
	map<int, Room*> * getAdjacentRoomsMap();

	// set this room as the first room
	void setFirstRoom();

	// set this room as the last room
	void setBossRoom();
private:
	// the (at most four) rooms bordering this room
	map<int, Room*> * adjacentRooms;

	// the list of rooms without the directions
	vector<Room*> * adjRoomList;

	// is there a random encounter in this room
	bool encounter;

	// is there loot in this room
	bool containLoot;

	// the loot contained in the room -> placeholder
	string loot;

	// copies member variables of rooms
	void copyfrom(Room other);

	// is this the first room in a map?
	bool firstRoom;

	// is this the last room in a map?
	bool bossRoom;
};

#endif
