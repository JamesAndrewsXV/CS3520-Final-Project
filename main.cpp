#include "Room.h"
#include "Map.h"
#include <iostream>
#include <stdio.h>
#include <SDL2/SDL.h>
using namespace std;

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 600;

//Starts up SDL and creates window
bool init() {
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("Four Right Turns", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return success;
}

//Loads media
bool loadMedia() {
	//Loading success flag
	bool success = true;

	//Load splash image
	background = SDL_LoadIMG("dungeon_example.png");
	if (background == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "dungeon_example.png", SDL_GetError());
		success = false;
	}

	return success;
}

//Frees media and shuts down SDL
void close()
{
	//Deallocate surface
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}


int main() {
	srand(time(NULL));

	Map map(5);
	// cout << map.getRooms().size() << endl;

	// for (Room * room : map.getRooms()) {
	// 	(*room).printLoot();
	// 	(*room).countAdjacentRooms();
	// }

	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;

	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Apply the image
			SDL_BlitSurface(background, NULL, gScreenSurface, NULL);
		}
	}
}