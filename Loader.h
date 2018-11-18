#ifndef _LOADER_H
#define _LOADER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <deque>
#include <sstream>
#include "LTexture.h"
using namespace std;

// class representing graphical display and front end logic of game
class Loader
{
  public:
	//Starts up SDL and creates window
	bool init();

	//Loads media
	bool loadMedia(string background, string message);

	//Frees media and shuts down SDL
	void close();

	SDL_Texture *loadTexture(std::string path);

	void renderScreen();

  private:
	friend class FourRightTurns;

	//Screen dimension constants
	const int SCREEN_WIDTH = 1024;
	const int SCREEN_HEIGHT = 600;

	//The window we'll be rendering to
	SDL_Window *gWindow = NULL;

	//The window renderer
	SDL_Renderer *gRenderer = NULL;

	//The text in the message bar
	LTexture displayed_text;

	//The inventory display
	//		LTexture inventory;

	//Current displayed texture
	SDL_Texture *gTexture = NULL;

	//Font in use
	TTF_Font *gFont = NULL;
};

#endif
