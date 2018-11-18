#include "Loader.h"

Loader::~Loader()
{
	SDL_DestroyWindow(gWindow);
	SDL_DestroyRenderer(gRenderer);
	displayed_text.free();
	SDL_DestroyTexture(gTexture);
	gFont = NULL;
}

bool Loader::init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("Four Right Turns", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				displayed_text.setRenderer(gRenderer);

				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}

				//Initialize SDL_ttf
				if (TTF_Init() == -1)
				{
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool Loader::loadMedia(string background, string message)
{
	//Loading success flag
	bool success = true;

	//Load texture
	gTexture = loadTexture(background);
	if (gTexture == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}

	gFont = TTF_OpenFont("assets/OpenSans.ttf", 48);
	if (gFont == NULL)
	{
		printf("Failed to load font. SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	else
	{
		SDL_Color textColor = {0, 0, 0};
		displayed_text.setFont(gFont);

		if (!displayed_text.loadFromRenderedText(message, textColor))
		{
			printf("Failed to render text texture \n");
			success = false;
		}
	}

	//Nothing to load
	return success;
}

void Loader::close()
{
	//Free loaded image
	SDL_DestroyTexture(gTexture);
	gTexture = NULL;
	displayed_text.free();
	TTF_CloseFont(gFont);
	gFont = NULL;

	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
	TTF_Quit();
}

SDL_Texture *Loader::loadTexture(std::string path)
{
	//The final texture
	SDL_Texture *newTexture = NULL;

	//Load image at specified path
	SDL_Surface *loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}

void Loader::renderScreen()
{
	//Clear screen
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(gRenderer);

	//Top viewport
	SDL_Rect topViewport;
	topViewport.x = 0;
	topViewport.y = 0;
	topViewport.w = SCREEN_WIDTH;
	topViewport.h = (3 * SCREEN_HEIGHT) / 4;
	SDL_RenderSetViewport(gRenderer, &topViewport);

	//Render texture to screen
	SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);

	//Bottom viewport
	SDL_Rect bottomViewport;
	bottomViewport.x = 0;
	bottomViewport.y = (3 * SCREEN_HEIGHT) / 4;
	bottomViewport.w = SCREEN_WIDTH;
	bottomViewport.h = SCREEN_HEIGHT / 4;
	SDL_RenderSetViewport(gRenderer, &bottomViewport);

	//Render texture to screen
	SDL_RenderCopy(gRenderer, displayed_text.getTexture(), NULL, NULL);

	//Update screen
	SDL_RenderPresent(gRenderer);
}
