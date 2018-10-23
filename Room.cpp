#include "Room.h"
#include "Item.h"

Room::Room()
{
	adjacentRooms = vector<Room*>();
	encounter = rand() % 2;
	containLoot = rand() % 2;
	setLoot();
	setEncounter();
}

void Room::copyfrom(Room other) {
	adjacentRooms = other.adjacentRooms;
	encounter = other.encounter;
	containLoot = other.containLoot;
	loot = other.loot;
}

/*void Room::movefrom(Room other) {
	copyfrom(other);
	other.adjacentRooms.clear();
	other.encounter = false;
	other.containLoot = false;
	other.loot = nullptr;
}*/

Room::Room(const Room & other) {
	copyfrom(other);
}

Room & Room::operator= (const Room & other) {
	if (this != &other) {
		copyfrom(other);
	}
	return *this;
}

// these don't seem to work with SDL, but I don't think we actually need these functions
/*Room::Room(Room&& other) {
	movefrom(other);
}

Room& Room::operator=(Room&& other) {
	if (this != &other) {
		movefrom(other);
	}
	return *this;
}*/

void Room::connectRoom(Room * room) {
	adjacentRooms.push_back(room);
}

void Room::countAdjacentRooms() {
	cout << adjacentRooms.size() << endl;
}

void setEncounter() {
	if (encounter)
	{
		monster = new Imp();
	}
	else {
		monster = NULL;
	}
}

void setLoot() {
	if (containLoot)
	{
		loot = randomItem();
	}
	else {
		loot = NULL;
	}
}
