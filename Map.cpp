#include "Map.h"
#include <algorithm>

Map::Map(int numberOfRooms)
{
	numOfRooms = numberOfRooms;
	for (int i = 0; i < numOfRooms; i++) {
		rooms.push_back(new Room());
	}

	firstRoom = rooms.front();
	bossRoom = rooms.back();
	setUpBossRoom();
	playerLoc = firstRoom;
	connectRooms();
}

Room Map::findPlayer()
{
	return *playerLoc;
}

vector<Room *> Map::getRooms() {
	return rooms;
}

void Map::connectRooms() {
	vector<Room *> tempList{ firstRoom };
	vector<Room *> roomsOnLevel;
	int level = 0;

	for (int i = 0; i < numOfRooms - 2; i++) {
		Room & room = rooms.at(i);
		tempList.push_back(room);
		roomsOnLevel.push_back(room);

		int numAdjacent = rand() % 3 + 1;
		for (int i = 0; i < numAdjacent; i++)
		{
			int randRoom = rand() % numOfRooms;

			if (find(roomsOnLevel.begin, roomsOnLevel.end(), randRoom) != roomsOnLevel.end() || 
				find(tempList.begin, tempList.end(), randRoom) != tempList.end()) { // contains
				Room * newAdj = rooms.at(randRoom);
				room.connectRoom(newAdj);
				tempList.push_back(newAdj);
				roomsOnLevel.push_back(newAdj);
			}
			else {
				i = i - 1;
			}
		}
		level++;
	}
}

void Map::copyfrom(Map other) {
	rooms = other.getRooms();
	firstRoom = other.getRooms().front();
	bossRoom = other.getRooms().back();
}

Map::Map(const Map & other) {
	copyfrom(other);
}

Map & Map::operator= (const Map & other) {
	if (this != &other) {
		copyfrom(other);
	}
	return *this;
}

void setUpBossRoom() {
	bossRoom.encounter = true;
	bossRoom.containLoot = true;

	queue<Room> Q = firstRoom;
	vector<Room> distVect;

	while (Q.size() > 0) {
		Room * u = queue.pop();

		for (Room * r : u.adjacentRooms) {
			if (!u.contains(r)) {

			}
		}
	}
}