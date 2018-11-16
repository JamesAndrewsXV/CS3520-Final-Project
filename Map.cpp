#include "Map.h"

Map::Map(int numberOfRooms)
{
	numOfRooms = numberOfRooms;
	for (int i = 0; i < numOfRooms; i++) {
		rooms.push_back(new Room());
	}

	firstRoom = rooms.front();
	bossRoom = rooms.back();
	playerLoc = firstRoom;
	connectRooms();
}

Room* Map::findPlayer()
{
	return playerLoc;
}

vector<Room *> Map::getRooms() {
	return rooms;
}

void Map::connectRooms() {
	for (int i = 0; i < rooms.size(); i++) {
		Room & room = *(rooms[i]);
		int numAdjacent = rand() % 3 + 2;

		for (int i = 0; i < numAdjacent; i++)
		{
			int randRoom = rand() % numOfRooms;
			Room * newAdj = rooms.at(randRoom);
			room.connectRoom(newAdj);
		}
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

string Map::movePlayer(int dir) {
	try {
//		playerLoc = playerLoc->getAdjacentRooms()->at(dir);
		return "You've entered a new room.";
	} catch (...) {
		return "You can't go that way.";
	}
//	playerLoc = (*(playerLoc->getAdjacentRooms()))[dir];
}
