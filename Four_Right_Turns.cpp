#include "Four_Right_Turns.h"

FourRightTurns::FourRightTurns()
{
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
	gameState = Explore;
}

FourRightTurns::~FourRightTurns()
{
	delete game_map;
}

void FourRightTurns::changeBackground()
{
	if (firstImage)
	{
		background_image = "assets/dungeon_example.png";
	}
	else
	{
		background_image = "assets/room2.png";
	}
}

void FourRightTurns::changeRoom(int dir)
{
	message.str(game_map->movePlayer(dir));

	if (message.str() != "You can't go that way.")
	{
		firstImage = !firstImage;
		changeBackground();
		loader.loadMedia(background_image, message.str());

		int adjRooms = game_map->findPlayer()->countAdjacentRooms();
		message.str("");
		message << "This room is connected to " << adjRooms << " rooms";
		loader.loadMedia(background_image, message.str());
		message.str("");
	}
	else
	{
		loader.loadMedia(background_image, message.str());
	}
}

void FourRightTurns::changeText()
{
	std::cout << message.str() << std::endl;
	std::cout << gameState << std::endl;

	if (queuedMessages.empty())
	{
		message.str("");
		queuedMessages.push_back("What would you like to do? ");
	}

	while (!queuedMessages.empty())
	{
		message << queuedMessages[0];
		queuedMessages.pop_front();
	}

	if (gameState == Explore)
	{
		if (message.str() == "What would you like to do? ")
		{
			message << "\n";
			if (!(game_map->isFirstRoom(game_map->findPlayer()))) {
				queuedMessages.push_back("Return the previous room (S KEY)\n");
			}
			if (game_map->canMove(1))
			{
				queuedMessages.push_back("Check out the room to the left (A KEY)\n");
			}
			if (game_map->canMove(2))
			{
				queuedMessages.push_back("Check out the room ahead (W KEY)\n");
			}
			if (game_map->canMove(3))
			{
				queuedMessages.push_back("Check out the room to the right (D KEY)\n");
			}
			queuedMessages.push_back("Look for loot (SPACE KEY)\n");
		}
	}

	if (gameState == Battle)
	{
		BattleScene battle(game_map->findPlayer(), player);
		queuedMessages.push_back(battle.displayBattleLog());

		//int randDrop = rand() % 2;
		//game_map->findPlayer()->setLoot(randDrop);
		gameState = Explore;
	}

	if (gameState == Loot)
	{
		if (!(game_map->findPlayer()->thereIsLoot()))
		{
			message.str("You searched for loot, but didn't find any.");
		}
		else
		{
			message.str("You found: " + game_map->findPlayer()->getLootName());
			game_map->findPlayer()->setLoot(false);
		}
		gameState = Explore;
	}

	if (game_map->findPlayer()->getEncounter())
	{
		gameState = Battle;
		message.str("YOU'RE BEING ATTACKED!!"); // delete
		game_map->findPlayer()->setEncounter(false);
	}

	loader.loadMedia(background_image, message.str());
}

int FourRightTurns::play()
{
	//Start up SDL and create window
	if (!loader.init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loader.loadMedia(background_image, message.str()))
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Main loop flag
			bool quit = false;

			//While application is running
			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&event))
				{
					//User requests quit
					if (event.type == SDL_QUIT)
					{
						quit = true;
					}


				//If a key was pressed
				if (event.type == SDL_KEYDOWN)
				{
					switch (event.key.keysym.sym)
					{

						if (gameState == Explore)
						{
						case SDLK_RETURN:
							changeText();
							break;

						case SDLK_s:
							queuedMessages.push_front("You go back.");
							changeText();
							changeRoom(0);
							break;

						case SDLK_a:
							queuedMessages.push_front("You walk into the room to the left.");
							changeText();
							changeRoom(1);
							break;

						case SDLK_w:
							queuedMessages.push_front("You walk into the room ahead.");
							changeText();
							changeRoom(2);
							break;

						case SDLK_d:
							queuedMessages.push_front("You walk into the room to the right.");
							queuedMessages.push_front("You walk into the room ahead.");
							changeText();
							changeRoom(3);
							break;

						case SDLK_SPACE:
							queuedMessages.push_front("You search for loot.");
							message.str("");
							gameState = Loot;
							changeText();
							break;
						}
					}
					}
				}

				if (gameState = GameMode::Explore) {
					loader.renderExploreScreen();
				}
				if (gameState = GameMode::Battle) {
					loader.renderBattleScreen();
				}
			}
		}
	}

	//Free resources and close SDL
	loader.close();

	return 0;
}
