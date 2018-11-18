#include "Map.h"

Map::Map(int numberOfRooms)
{
	numOfRooms = numberOfRooms;
	for (int i = 0; i < numOfRooms; i++)
	{
		rooms.push_back(new Room());
	}

	firstRoom = rooms.front();
	firstRoom->setEncounter(false);
	firstRoom->setFirstRoom();
	findBossRoom();
	bossRoom->setEncounter(true);
	bossRoom->setBossRoom();
	playerLoc = firstRoom;
	connectedRooms = vector<Room*>();
	connectedRooms.push_back(firstRoom);
	connectRooms(firstRoom);
}

Room *Map::findPlayer()
{
	return playerLoc;
}

vector<Room *> Map::getRooms()
{
	return rooms;
}

void Map::connectRooms(Room * nextRoom) //DEPTH FIRST??
{
	Room * newAdj;
	int randRoomNum;
	int maxAdjacentRooms = 3;

	for (int i = 0; i < maxAdjacentRooms; i++) {
		randRoomNum = rand() % numOfRooms + 1;
		newAdj = rooms.at(randRoomNum);

		if (!(std::find(connectedRooms.begin(), connectedRooms.end(), newAdj) != connectedRooms.end())) {
			nextRoom->connectRoom(newAdj);
			newAdj->connectRoom(nextRoom);
			connectedRooms.push_back(newAdj);
			connectRooms(newAdj);
		}
	}
}

void Map::copyfrom(Map other)
{
	rooms = other.getRooms();
	firstRoom = other.getRooms().front();
	bossRoom = other.getRooms().back();
}

Map::Map(const Map &other)
{
	copyfrom(other);
}

Map &Map::operator=(const Map &other)
{
	if (this != &other)
	{
		copyfrom(other);
	}
	return *this;
}


bool Map::canMove(int dir) {
	try
	{
		playerLoc = playerLoc->getAdjacentRooms()->at(dir);
		return true;
	}
	catch (...)
	{
		return false;
	}
}

string Map::movePlayer(int dir)
{
	if (canMove(dir))
	{
		return "You've entered a new room.";
	}
	else
	{
		return "You can't go that way.";
	}
}

void Map::findBossRoom() {
	// int leastRooms = INFINITY;

	// for (Room* room : rooms) {
	// 	if (room->getAdjacentRooms()->size() < leastRooms) {
	// 		leastRooms = room->getAdjacentRooms()->size();
	// 		bossRoom = room;
	// 	}
	// }
	for (Room* room : rooms) {
		if (!(std::find(connectedRooms.begin(), connectedRooms.end(), room) != connectedRooms.end())) {
			bossRoom = room;
		}
	}
}
