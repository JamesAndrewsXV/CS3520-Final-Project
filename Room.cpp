#include "Room.h"

Room::Room()
{
	encounter = rand() % 2;
	containLoot = rand() % 2;
	setLoot();
}

void Room::copyfrom(Room other) {
	adjacentRooms[0] = other.adjacentRooms[0];
	encounter = other.encounter;
	containLoot = other.containLoot;
	loot = other.loot;
}

void Room::movefrom(Room other) {
	copyfrom(other);
	other.adjacentRooms[0] = nullptr;
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

//Room::Room(Room&& other) {
//	movefrom(other);
//}
//
//Room& Room::operator=(Room&& other) {
//	if (this != &other) {
//		movefrom(other);
//	}
//	return *this;
//}

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

void Room::connectRoom(Room * room) {
	for (Room* r : adjacentRooms) {
		if (r == nullptr) {
			r = room;
		}
	}
	//adjacentRooms.push_back(room);
}

int Room::countAdjacentRooms() {
	int count = 0;

	for (Room* room : adjacentRooms) {
		if (room != nullptr) {
			count++;
		}
	}

	return count;
	//return adjacentRooms.size();
}

const bool Room::getEncounter() {
	return encounter;
}

const bool Room::getLoot() {
	return containLoot;
}

Room** Room::getAdjacentRooms() {
	return adjacentRooms;
}
