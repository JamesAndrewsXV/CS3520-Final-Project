#include "Room.h"

Room::Room()
{
	adjacentRooms = new map<int, Room*>();
	adjRoomList = new vector<Room*>();
	encounter = rand() % 2;
	containLoot = rand() % 2;
	setLoot(containLoot);
	adjRoomList = new vector<Room*>();
	firstRoom = false;
}

Room::~Room()
{
	delete adjacentRooms;
	delete adjRoomList;
}

void Room::copyfrom(Room other) {
	adjacentRooms = other.adjacentRooms;
	encounter = other.encounter;
	containLoot = other.containLoot;
	loot = other.loot;
}

Room::Room(const Room & other) {
	copyfrom(other);
}

Room & Room::operator= (const Room & other) {
	if (this != &other) {
		copyfrom(other);
	}
	return *this;
}

void Room::setLoot(bool l)
{
	containLoot = l;
}

void Room::printLoot() {
	cout << loot << endl;
}

bool Room::connectRoom(Room * room) {
	int roomKey = -1;
	int maxAdjacentRooms = 3;
	int randRoomPosn = rand() % 3 + 1;
	map<int, Room*>::iterator it = adjacentRooms->find(randRoomPosn);

	if (adjacentRooms->size() == 0 && !firstRoom) {
		roomKey = 0;
	} else {
		for (int i = 1; i < maxAdjacentRooms; i++) {
			while (it != adjacentRooms->end()) {
				randRoomPosn = rand() % 3 + 1;
				it = adjacentRooms->find(randRoomPosn);
			}
			roomKey = randRoomPosn;
			break;
		}
	}

	if (roomKey == -1) {
		return false;
	}
	else {
		adjacentRooms->insert(make_pair(roomKey, room));
		adjRoomList->push_back(room);
		return true;
	}
}

int Room::countAdjacentRooms() {
	return adjacentRooms->size();
}

const bool Room::getEncounter() {
	return encounter;
}

void Room::setEncounter(bool enc) {
	encounter = enc;
}

const bool Room::getLoot() {
	return containLoot;
}

//void Room::setAdjacentRooms() {
//	for (map<int, Room*>::iterator it = adjacentRooms->begin(); it != adjacentRooms->end(); it++) {
//		adjRoomList->push_back(it->second);
//	}
//}

vector<Room*> * Room::getAdjacentRooms() {
	return adjRoomList;
}

map<int, Room*> * Room::getAdjacentRoomsMap() {
	return adjacentRooms;
}

void Room::setFirstRoom() {
	firstRoom = true;
}

void Room::setBossRoom() {
	bossRoom = true;
}
