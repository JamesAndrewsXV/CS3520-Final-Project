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

void Map::connectRooms(Room * nextRoom) //BREADTH FIRST??
{
	Room * newAdj;
	int randRoomNum;
	int maxAdjacentRooms = 3;

	for (int i = 0; i < maxAdjacentRooms; i++) {
		randRoomNum = rand() % (numOfRooms - 1) + 1;
		newAdj = rooms.at(randRoomNum); //index

		if (find(connectedRooms.begin(), connectedRooms.end(), newAdj) == connectedRooms.end()) {
			nextRoom->connectRoom(newAdj);
			newAdj->connectRoom(nextRoom);
			connectedRooms.push_back(newAdj);
		}
	}

	if (nextRoom == firstRoom) {
		for (unsigned int k = 1; k < connectedRooms.size() && connectedRooms.size() < rooms.size(); k++) {
			connectRooms(connectedRooms.at(k));
		}
	}
}

/*void Map::copyfrom(Map other)
{
	rooms = other.getRooms();
	firstRoom = other.getRooms().front();
	bossRoom = other.getRooms().back();
}

Map::Map(const Map &other)
{
	copyfrom(other);
}*/

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
		playerLoc->getAdjacentRoomsMap()->at(dir);
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
		playerLoc = playerLoc->getAdjacentRoomsMap()->at(dir);
		return "You've entered a new room.";
	}
	else
	{
		return "You can't go that way.";
	}
}

void Map::findBossRoom() {
	for (unsigned int i = 0; i < rooms.size(); i++) {
		if (!(find(connectedRooms.begin(), connectedRooms.end(), rooms[i]) != connectedRooms.end())) {
			bossRoom = rooms[i];
		}
	}
}

//TESTING!!
string Map::printConnections() {
	stringstream edges;
	edges.str("edges:\n");

	for (unsigned int i = 0; i < rooms.size(); i++) {
//		for (unsigned int k = 0; k < rooms.size(); k++) {
//			if (find(rooms.at(i)->getAdjacentRooms()->begin(),
//					rooms.at(i)->getAdjacentRooms()->end(),
//					rooms.at(k)) != rooms.at(i)->getAdjacentRooms()->end()) {
//
//				vector<Room*>::iterator it = find(rooms.at(i)->getAdjacentRooms()->begin(),
//						rooms.at(i)->getAdjacentRooms()->end(),
//						rooms.at(k));
//
//				edges << "(" << i << ", " << k << ")" << std::endl;
			if (playerLoc == rooms.at(i)) {
				edges << i << endl;
			}
//		}
	}

//	edges << rooms.at(0) << " " << (rooms[0]->getAdjacentRoomsMap()->at(2)) << " ";
	//edges << rooms.at(1) << " " << (rooms[1]->getAdjacentRooms()->at(0));
	return edges.str();
}

bool Map::isFirstRoom(Room * room) {
	return room == firstRoom;
}
