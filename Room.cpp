#include "Room.h"

Room::Room()
{
	adjacentRooms = new map<int, Room*>();
	adjRoomList = new vector<Room*>();
	encounter = rand() % 2;
	containLoot = rand() % 2;
	setLoot();
	adjRoomList = getAdjacentRooms();
}

Room::~Room()
{
	adjRoomList = NULL;
	delete adjacentRooms;
}

void Room::copyfrom(Room other) {
	adjacentRooms = other.adjacentRooms;
	encounter = other.encounter;
	containLoot = other.containLoot;
	loot = other.loot;
}

void Room::movefrom(Room other) {
	copyfrom(other);
	other.adjacentRooms = NULL;
	other.encounter = false;
	other.containLoot = false;
	other.loot = nullptr;
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

Room::Room(Room&& other) {
	movefrom(other);
}

Room& Room::operator=(Room&& other) {
	if (this != &other) {
		movefrom(other);
	}
	return *this;
}

void Room::setLoot()
{
	if (containLoot)
	{
		loot = "there's loot!";
	}
	else {
		loot = "no loot.";
	}
}

void Room::printLoot() {
	cout << loot << endl;
}

bool Room::connectRoom(Room * room) {
	int roomKey = -1;

	for (int i = 0; i < 3; i++) {
		if (adjacentRooms->count(i) == 0) {
			roomKey = i;
			break;
		}
	}

	if (roomKey == -1) {
		return false;
	}
	else {
		adjacentRooms->insert(make_pair(roomKey, room));
		return true;
	}
}

int Room::countAdjacentRooms() {
	return adjacentRooms->size();
}

const bool Room::getEncounter() {
	return encounter;
}

const bool Room::getLoot() {
	return containLoot;
}

vector<Room*> * Room::getAdjacentRooms() {
	for (map<int, Room*>::iterator it = adjacentRooms->begin(); it != adjacentRooms->end(); it++) {
		adjRoomList->push_back(it->second);
	}
	return adjRoomList;
}
