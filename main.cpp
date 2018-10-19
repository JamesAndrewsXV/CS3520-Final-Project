#include "Room.h"
#include "Map.h"
#include <iostream>
#include <stdio.h>
#include <SDL2/SDL.h>
using namespace std;

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 600;
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* background = NULL;

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
	background = SDL_LoadBMP("CS3520-Final-Project/dungeon_example.bmp");
	if (background == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "CS3520-Final-Project/dungeon_example.bmp", SDL_GetError());
		success = false;
	}

	return success;
}

//Frees media and shuts down SDL
void close()
{
	//Deallocate surface
	SDL_FreeSurface(background);
	background = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}


int main() {
	srand(time(NULL));

	//Map map(5);
	// cout << map.getRooms().size() << endl;

	// for (Room * room : map.getRooms()) {
	// 	(*room).printLoot();
	// 	(*room).countAdjacentRooms();
	// }

	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		if ( !loadMedia() ) {
			printf( "Failed to load media!\n" );
//Fill the surface white
			SDL_FillRect( gScreenSurface, 	NULL, SDL_MapRGB( gScreenSurface->format, 0x1F, 0xFF, 0xFF ) );

//Update the surface
			SDL_UpdateWindowSurface( gWindow );

			//Wait two seconds
			SDL_Delay( 2000 );
		}
		else {
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface( gWindow );

			SDL_BlitSurface( background, NULL, gScreenSurface, NULL );
			
			//Update the surface
			SDL_UpdateWindowSurface( gWindow );

			//Wait two seconds
			SDL_Delay( 2000 );
		}
	}
}
