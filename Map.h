#pragma once
#ifndef MAP_H
#define MAP_H

#include "Room.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <sstream>
using namespace std;

// class representing the list of rooms the player traverses through
class Map
{
  public:
	Map(int numberOfRooms);

	// map copy constructor
	Map(const Map &other);

	// map copy assignment operator
	Map &operator=(const Map &other);

	// returns the room the player is currently located in
	Room *findPlayer();

	// returns all of the rooms on the map
	vector<Room *> getRooms();

	// change the player's location
	string movePlayer(int dir);

	// tests if the player can move in a certain direction
	bool canMove(int dir);

	//for testing, returns the edges between a graph of the map
	string printConnections();

	// is this the first room?
	bool isFirstRoom(Room * room);
  private:
	int numOfRooms;

	// the list of rooms in the map
	vector<Room *> rooms;

	// the room the player starts in
	Room *firstRoom;

	// the final room in the game where the player fights the boss
	Room *bossRoom;

	// the location of the player
	Room *playerLoc;

	// randomly connects up to four rooms to each room in the map
	// and at least two rooms
	// currently completely random
	void connectRooms(Room * nextRoom);

	// the rooms connected so far
	vector<Room*> connectedRooms;

	// copies Map member variables from another
	void copyfrom(Map other);

	// find the farthest room from the first room
	void findBossRoom();
};
#endif
