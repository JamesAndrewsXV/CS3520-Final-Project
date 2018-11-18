#include "Four_Right_Turns.h"

FourRightTurns::FourRightTurns() {
	srand(time(NULL));
	message.str("Four Right Turns");
	game_map = new Map(10); //delete!
	queuedMessages = deque<string>();

	queuedMessages.push_back("You wake up in a dark room. ");
	queuedMessages.push_back("You don't remember how you arrived here, but based on your rucksack and flashlight you gather that this is just another one of your nightly dungeon crawls in search of the rare mythril sword rumored to be the strongest and most precious weapon to be lost to the crepuscular catacombs below the city. ");
	queuedMessages.push_back("You fear not the beasts that await you in the caves. ");
	queuedMessages.push_back("Only the thought of never claiming this sword scares you... ");
	queuedMessages.push_back("Before you lies two paths, a staircase and a treasure chest. ");

	background_image = "assets/dungeon_example.png";
	firstImage = true;
}

void FourRightTurns::changeBackground() {
	if (firstImage) {
		background_image = "assets/dungeon_example.png";
	} else {
		background_image = "assets/room2.png";
	}
}

void FourRightTurns::changeRoom(int dir) {
	message.str(game_map->movePlayer(dir));

	if (message.str() != "You can't go that way.") {
		firstImage = !firstImage;
		changeBackground();
		loader.loadMedia(background_image, message.str());

		int adjRooms = game_map->findPlayer()->countAdjacentRooms();
		message.str("");
		message << "This room is connected to " << adjRooms << " rooms";
		loader.loadMedia(background_image, message.str());
		message.str("");
	} else {
		loader.loadMedia(background_image, message.str());
	}
	queuedMessages.push_back("What would you like to do?");
}

void FourRightTurns::changeText() {
//	if (map->findPlayer().getEncounter()) {
//		messages00.push_front("What would you like to do?");
//		messages00.push_front("YOU'RE BEING ATTACKED!!");
//	}
//
	std::cout << message.str() << std::endl;

	if (message.str() == "What would you like to do?") {
		message.str("");
		// the key events don't yet catch if the player tries to enter a room that doesn't exist
		if (game_map->findPlayer()->countAdjacentRooms() >= 1) {
			queuedMessages.push_back("Check out the room to the right (RIGHT KEY)\n");
		}
		if (game_map->findPlayer()->countAdjacentRooms() >= 2) {
			queuedMessages.push_back("Check out the room ahead (UP KEY)\n");
		}
		if (game_map->findPlayer()->countAdjacentRooms() == 3) {
			queuedMessages.push_back("Check out the room to the left (LEFT KEY)\n");
		}
		queuedMessages.push_back("Look for loot (DOWN KEY)\n");
	}

	if (queuedMessages.empty()) {
		message.str("");
		queuedMessages.push_back("What would you like to do?");
	}

	while (!queuedMessages.empty()) {
		message << queuedMessages[0];
		queuedMessages.pop_front();
	}

	if (message.str() == "You search for loot.") {
		message.str("");
//		if (!(map->findPlayer().getLoot())) {
		message.str("You searched for loot, but didn't find any.");
		loader.loadMedia(background_image, message.str());
//		}
//		else {
//			messages00.push_back("You found: Need to finish");
//		}
	}

	loader.loadMedia(background_image, message.str());
}

int FourRightTurns::play()
{
	//Start up SDL and create window
	if( !loader.init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loader.loadMedia(background_image, message.str()) )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
			//Main loop flag
			bool quit = false;

			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &event ) != 0 )
				{
					//User requests quit
					if( event.type == SDL_QUIT )
					{
						quit = true;
					}
				}

					//If a key was pressed
					if (event.type == SDL_KEYDOWN)
					{
						switch (event.key.keysym.sym)
						{
						case SDLK_RETURN:
							changeText();
							break;

						case SDLK_UP:
							queuedMessages.push_front("You walk into the room ahead.");
							changeText();
							changeRoom(1);
							break;

						case SDLK_LEFT:
							queuedMessages.push_front("You walk into the room to the left.");
							changeText();
							changeRoom(0);
							break;

						case SDLK_RIGHT: queuedMessages.push_front("You walk into the room to the right.");
							queuedMessages.push_front("You walk into the room ahead.");
							changeText();
							changeRoom(2);
							break;

						case SDLK_DOWN: queuedMessages.push_front("You search for loot.");
							message.str("");
							changeText();
							break;
						}
					}

				loader.renderScreen();
			}
		}
	}

	//Free resources and close SDL
	loader.close();

	return 0;
}
