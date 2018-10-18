#pragma once
#ifndef _MAP_H
#define _MAP_H
#endif

#include "Room.h"
#include <vector>
#include <iostream>
using namespace std;

// class representing the list of rooms the player traverses through
class Map {
public:
	Map(int numberOfRooms);

	// // map copy constructor
	// Map (const Map & other);

	// // map copy assignment operator
	// Map & operator= (const Map & other);

	// returns the room the player is currently located in
	Room findPlayer();

	// returns all of the rooms on the map
	vector<Room*> getRooms();

private:
	// the list of rooms in the map
	vector<Room*> rooms;

	// the room the player starts in
	Room * firstRoom;

	// the final room in the game where the player fights the boss
	Room * bossRoom;

	// the location of the player
	Room * playerLoc;

	// copies Map member variables from another
	void copyfrom(Map other);

	//generates a set of rooms given a total number of rooms
	void generateRooms(int numberOfRooms);
};
