#include "Room.h"

Room::Room()
{
	this->adjacentRooms = new map<int, Room*>();
	this->adjRoomList = new vector<Room*>();
	this->encounter = rand() % 2;
	this->containLoot = rand() % 2;
	this->setLoot(containLoot);
	this->adjRoomList = new vector<Room*>();
	this->firstRoom = false;
	this->loot = buildItem().get()->getName();
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

const bool Room::thereIsLoot() {
	return containLoot;
}

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

const string Room::getLootName() {
	return loot;
}
