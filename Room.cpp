#include "Room.h"

Room::Room()
{
	adjacentRooms = vector<Room*>();
	encounter = rand() % 2;
	containLoot = rand() % 2;
	setLoot();
}

void Room::copyfrom(Room other) {
	adjacentRooms = other.adjacentRooms;
	encounter = other.encounter;
	containLoot = other.containLoot;
	loot = other.loot;
}

void Room::movefrom(Room other) {
	copyfrom(other);
	other.adjacentRooms.clear();
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

/*Room::Room(Room&& other) {
	movefrom(other);
}

Room& Room::operator=(Room&& other) {
	if (this != &other) {
		movefrom(other);
	}
	return *this;
}*/

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
	adjacentRooms.push_back(room);
}

void Room::countAdjacentRooms() {
	cout << adjacentRooms.size() << endl;
}
