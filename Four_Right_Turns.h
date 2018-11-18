#ifndef _FOUR_RIGHT_TURNS_H
#define _FOUR_RIGHT_TURNS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include<SDL2/SDL_mixer.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <deque>
#include <sstream>
#include "Map.h"
#include "Room.h"
#include "Loader.h"

// class representing graphical display and front end logic of game
class FourRightTurns {
public:
	// initializes a game
	FourRightTurns();

	void changeBackground();

	void changeRoom(int dir);

	void changeText();

	int play();

private:
		//The text to be displayed
		stringstream message;

		//alt representation of text
		deque<string> queuedMessages;

		//The background being displayed
		string background_image;

		// The map of the dungeon
		Map * game_map;

		//Event handler
		SDL_Event event;

		// which room is on screen
		bool firstImage;

		Loader loader;
};

#endif
