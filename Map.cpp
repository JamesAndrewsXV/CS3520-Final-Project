#include "Map.h"
using namespace std;

Map::Map(int numberOfRooms)
{
	for (int i = 0; i < numberOfRooms; i++) {
		rooms.push_back(new Room());
	}

	firstRoom = rooms.front();
	bossRoom = rooms.back();
	//generateRooms(2); //should this differ based on the level?
	playerLoc = firstRoom;
}

// void Map::copyfrom(Map other) {
// 	rooms = other.getRooms();
// 	firstRoom = *(other.getRooms().at(0));
// 	bossRoom = *(other.getRooms().at(other.getRooms().size() - 1));
// }

// Map::Map (const Map & other) {
// 	copyfrom(other);
// }

// Map & Map::operator= (const Map & other) {
// 	if (this != &other) {
// 		copyfrom(other);
// 	}
// 	return *this;
// }

Room Map::findPlayer()
{
	return *playerLoc;
}

vector<Room*> Map::getRooms() {
	return rooms;
}

// void Map::generateRooms(int numberOfRooms) {
//   rooms.resize(numberOfRooms + 1);
//   cout << rooms.size();

//   for (int i = 0; i < numberOfRooms; i++) {
//     Room * room = new Room();
//     rooms.push_back(new Room());
//     // rooms.at(i) = Room();
// 	}


//   // // for (Room r : rooms) {
//   // //   r.setMap(*this);
//   // // }

// 	firstRoom = &rooms.front();
// 	bossRoom = &rooms.back();
// }
