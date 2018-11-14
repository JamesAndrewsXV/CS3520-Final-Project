#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include<SDL2/SDL_mixer.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include "Map.h"

//Screen dimension constants
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 600;

//Start up SDL and create window
	//The window we'll be rendering to
	SDL_Window* gWindow = NULL;

	//The surface contained by the window
	SDL_Surface* gScreenSurface = NULL;

	//The window renderer
	//SDL_Renderer* menu = NULL;

	//The image we will load and show on the screen
	SDL_Surface* current_room_image = NULL;

	SDL_Event event;

	//Texture wrapper class
//	class LTexture
//	{
//	public:
//		//Initializes variables
//		LTexture();
//
//		//Deallocates memory
//		~LTexture();
//
//		//Loads image at specified path
//		bool loadFromFile(std::string path);
//
//		//Creates image from font string
//		bool loadFromRenderedText(std::string textureText, SDL_Color textColor);
//
//		//Deallocates texture
//		void free();
//
//		//Set color modulation
//		void setColor(Uint8 red, Uint8 green, Uint8 blue);
//
//		//Set blending
//		void setBlendMode(SDL_BlendMode blending);
//
//		//Set alpha modulation
//		void setAlpha(Uint8 alpha);
//
//		//Renders texture at given point
//		void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
//
//		//Gets image dimensions
//		int getWidth();
//		int getHeight();
//
//	private:
//		//The actual hardware texture
//		SDL_Texture* mTexture;
//
//		//Image dimensions
//		int mWidth;
//		int mHeight;
//	};
//
//	//Globally used font
//	TTF_Font *gFont = NULL;
//
//	//Rendered texture
//	LTexture gTextTexture;
//
//
//	LTexture::LTexture()
//	{
//		//Initialize
//		mTexture = NULL;
//		mWidth = 0;
//		mHeight = 0;
//	}
//
//	LTexture::~LTexture()
//	{
//		//Deallocate
//		free();
//	}
//
//	bool LTexture::loadFromFile(std::string path)
//	{
//		//Get rid of preexisting texture
//		free();
//
//		//The final texture
//		SDL_Texture* newTexture = NULL;
//
//		//Load image at specified path
//		SDL_Surface* loadedSurface = IMG_Load(path.c_str());
//		if (loadedSurface == NULL)
//		{
//			printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
//		}
//		else
//		{
//			//Color key image
//			SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
//
//			//Create texture from surface pixels
//			newTexture = SDL_CreateTextureFromSurface(menu, loadedSurface);
//			if (newTexture == NULL)
//			{
//				printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
//			}
//			else
//			{
//				//Get image dimensions
//				mWidth = loadedSurface->w;
//				mHeight = loadedSurface->h;
//			}
//
//			//Get rid of old loaded surface
//			SDL_FreeSurface(loadedSurface);
//		}
//
//		//Return success
//		mTexture = newTexture;
//		return mTexture != NULL;
//	}
//
//	bool LTexture::loadFromRenderedText(std::string textureText, SDL_Color textColor)
//	{
//		//Get rid of preexisting texture
//		free();
//
//		//Render text surface
//		SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
//		if (textSurface == NULL)
//		{
//			printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
//		}
//		else
//		{
//			//Create texture from surface pixels
//			mTexture = SDL_CreateTextureFromSurface(menu, textSurface);
//			if (mTexture == NULL)
//			{
//				printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
//			}
//			else
//			{
//				//Get image dimensions
//				mWidth = textSurface->w;
//				mHeight = textSurface->h;
//			}
//
//			//Get rid of old surface
//			SDL_FreeSurface(textSurface);
//		}
//
//		//Return success
//		return mTexture != NULL;
//	}
//
//	void LTexture::free()
//	{
//		//Free texture if it exists
//		if (mTexture != NULL)
//		{
//			SDL_DestroyTexture(mTexture);
//			mTexture = NULL;
//			mWidth = 0;
//			mHeight = 0;
//		}
//	}
//
//	void LTexture::setColor(Uint8 red, Uint8 green, Uint8 blue)
//	{
//		//Modulate texture rgb
//		SDL_SetTextureColorMod(mTexture, red, green, blue);
//	}
//
//	void LTexture::setBlendMode(SDL_BlendMode blending)
//	{
//		//Set blending function
//		SDL_SetTextureBlendMode(mTexture, blending);
//	}
//
//	void LTexture::setAlpha(Uint8 alpha)
//	{
//		//Modulate texture alpha
//		SDL_SetTextureAlphaMod(mTexture, alpha);
//	}
//
//	void LTexture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
//	{
//		//Set rendering space and render to screen
//		SDL_Rect renderQuad = { x, y, mWidth, mHeight };
//
//		//Set clip rendering dimensions
//		if (clip != NULL)
//		{
//			renderQuad.w = clip->w;
//			renderQuad.h = clip->h;
//		}
//
//		//Render to screen
//		SDL_RenderCopyEx(menu, mTexture, clip, &renderQuad, angle, center, flip);
//	}
//
//	int LTexture::getWidth()
//	{
//		return mWidth;
//	}
//
//	int LTexture::getHeight()
//	{
//		return mHeight;
//	}



bool init()
{
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		gWindow = SDL_CreateWindow( "Four Right Turns", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface( gWindow );

//			//Create vsynced renderer for window
//			menu = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
//			if (menu == NULL)
//			{
//				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
//				success = false;
//			}
//			else
//			{
//				//Initialize renderer color
//				SDL_SetRenderDrawColor(menu, 0xFF, 0xFF, 0xFF, 0xFF);
//
//				//Initialize PNG loading
//				int imgFlags = IMG_INIT_PNG;
//				if (!(IMG_Init(imgFlags) & imgFlags))
//				{
//					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
//					success = false;
//				}
//
//				//Initialize SDL_ttf
//				if (TTF_Init() == -1)
//				{
//					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
//					success = false;
//				}
//			}
		}
	}

	return success;
}

// change to be load room
bool loadMedia()
{
	bool success = true;
	current_room_image = SDL_LoadBMP( "assets/dungeon_example.bmp" );

	if( current_room_image == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", "assets/dungeon_example.bmp", SDL_GetError() );
		success = false;
	}

//	//https://www.fontsquirrel.com/fonts/list/hot
//	gFont = TTF_OpenFont("Raleway-Regular.ttf", 28);
//	if (gFont == NULL)
//	{
//		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
//		success = false;
//	}
//	else
//	{
//		//Render text
//		SDL_Color textColor = { 0, 0, 0 };
//		if (!gTextTexture.loadFromRenderedText("The quick brown fox jumps over the lazy dog", textColor))
//		{
//			printf("Failed to render text texture!\n");
//			success = false;
//		}
//	}

	return success;
}

void close()
{
	//Free loaded images
	//gTextTexture.free();
	SDL_FreeSurface(current_room_image);
	current_room_image = NULL;

	//Free global font
	//TTF_CloseFont(gFont);
	//gFont = NULL;

	//Destroy window
	//SDL_DestroyRenderer(menu);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	//menu = NULL;

	//Quit SDL subsystems
	//TTF_Quit();
	IMG_Quit();
	SDL_Quit();

}

int main( int argc, char* args[] )
{
	srand(time(NULL));

	Map map(5);
	//Make sure the program waits for a quit
			bool quit = false;

			//Start up SDL and create window
			if (!init())
			{
				printf("Failed to initialize!\n");
			}

			else
			{
				if (!loadMedia())
				{
					gScreenSurface = SDL_GetWindowSurface(gWindow);
					SDL_FillRect(gScreenSurface, NULL, SDL_MapRGB(gScreenSurface->format, 0xFF, 0xFF, 0xFF));
					SDL_UpdateWindowSurface(gWindow);
					SDL_Delay(2000);
					printf("Failed to load media!\n");
				}

				else
				{
					SDL_BlitSurface(current_room_image, NULL, gScreenSurface, NULL);
					SDL_UpdateWindowSurface(gWindow);
					SDL_Delay(2000);
				}
			}



			while (quit == false)
			{
				while (SDL_PollEvent(&event))
				{
					if (event.type == SDL_QUIT)
					{
						quit = true;
					}

					//If a key was pressed
		//			if (event.type == SDL_KEYDOWN)
		//			{
		//				//Set the proper message surface
		//				switch (event.key.keysym.sym)
		//				{
		//				case SDLK_UP: message = upMessage; break;
		//				case SDLK_DOWN: message = downMessage; break;
		//				case SDLK_LEFT: message = leftMessage; break;
		//				case SDLK_RIGHT: message = rightMessage; break;
		//				}
		//			}

				}

				//Clear screen
				//SDL_SetRenderDrawColor(menu, 0xFF, 0xFF, 0xFF, 0xFF);
				//SDL_RenderClear(menu);

				//Render current frame
				//gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, (SCREEN_HEIGHT - gTextTexture.getHeight()) / 2);

				//Update screen
				//SDL_RenderPresent(menu);
			}

			//Free resources and close SDL
			close();

			return 0;
}
