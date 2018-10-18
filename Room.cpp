#include "Room.h"

Room::Room()
{
	srand(time(NULL));
	int randomLoot = rand() % 2;
	int randomEncounter = rand() % 2;

	encounter = randomEncounter;
	containLoot = randomLoot;
	setLoot();
	adjacent_rooms = vector<Room>();
}

void Room::copyfrom(Room other) {
	adjacent_rooms = other.adjacent_rooms;
	encounter = other.encounter;
	containLoot = other.containLoot;
	loot = other.loot;
	//this_map = Map(other.this_map);
}

void Room::movefrom(Room other) {
	copyfrom(other);
	other.adjacent_rooms.clear();
	//other.adjacent_rooms = nullptr;
	other.encounter = false;
	other.containLoot = false;
	other.loot = nullptr;
	// other.this_map = nullptr;
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

void Room::connectRooms()
{
	int num_of_rooms = rand() % 3 + 1;

	for (int rooms = 0; rooms < num_of_rooms; rooms++)
	{
		//int randRoom = rand() % this_map.getRooms().size();
		//adjacent_rooms.push_back(this_map.getRooms().at(num_of_rooms));
	}
}

void Room::setLoot()
{
	if (containLoot)
	{
		loot = "there's loot!";
	}
	else {
		loot = "no loot";
	}
}

void Room::printLoot() {
	if (containLoot) {
		cout << loot << endl;
	}
}

// void Room::setMap(Map * map) {
// 	this_map = *map;
// }
