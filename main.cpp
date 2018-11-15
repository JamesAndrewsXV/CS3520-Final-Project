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

//Screen dimension constants
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 600;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Texture wrapper class
class LTexture
{
	public:
		//Initializes variables
		LTexture();

		//Deallocates memory
		~LTexture();

		//Loads image at specified path
		bool loadFromFile( std::string path );

		//Creates image from font string
		bool loadFromRenderedText( std::string textureText, SDL_Color textColor );

		//Deallocates texture
		void free();

		//Set color modulation
		void setColor( Uint8 red, Uint8 green, Uint8 blue );

		//Set blending
		void setBlendMode( SDL_BlendMode blending );

		//Set alpha modulation
		void setAlpha( Uint8 alpha );

		//Renders texture at given point
		void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

		//Gets image dimensions
		int getWidth();
		int getHeight();

		//Gets the contained texture
		SDL_Texture* getTexture();

	private:
		//The actual hardware texture
		SDL_Texture* mTexture;

		//Image dimensions
		int mWidth;
		int mHeight;
};


//Loads individual image as texture
SDL_Texture* loadTexture( std::string path );

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//The text in the message bar
LTexture displayed_text;

//The inventory display
LTexture inventory;

//The text to be displayed
stringstream message;

//alt representation of text
deque<std::string> messages00 = { "You wake up in a dark room.",
		"You don't remember how you arrived here, but based on your rucksack and flashlight you gather that this is just another one of your nightly dungeon crawls in search of the rare mythril sword rumored to be the strongest and most precious weapon to be lost to the crepuscular catacombs below the city. ",
		"You fear not the beasts that await you in the caves. ",
		"Only the thought of never claiming this sword scares you... ",
		"Before you lies two paths, a staircase and a treasure chest. " };

//The background being displayed
string background_location = "assets/dungeon_example.png";

//Current displayed texture
SDL_Texture* gTexture = NULL;

//Font in use
TTF_Font *gFont = NULL;

// The map of the dungeon
Map * map;

//Event handler
SDL_Event event;

SDL_Texture * LTexture::getTexture() {
	return mTexture;
}

LTexture::LTexture()
{
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture()
{
	//Deallocate
	free();
}

bool LTexture::loadFromFile( std::string path )
{
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

bool LTexture::loadFromRenderedText( std::string textureText, SDL_Color textColor )
{
	//Get rid of preexisting texture
	free();

	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Blended_Wrapped( gFont, textureText.c_str(), textColor, 2400);
	if( textSurface == NULL )
	{
		printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );
		if( mTexture == NULL )
		{
			printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface( textSurface );
	}

	//Return success
	return mTexture != NULL;
}

void LTexture::free()
{
	//Free texture if it exists
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
	//Modulate texture rgb
	SDL_SetTextureColorMod( mTexture, red, green, blue );
}

void LTexture::setBlendMode( SDL_BlendMode blending )
{
	//Set blending function
	SDL_SetTextureBlendMode( mTexture, blending );
}

void LTexture::setAlpha( Uint8 alpha )
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod( mTexture, alpha );
}

void LTexture::render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx( gRenderer, mTexture, clip, &renderQuad, angle, center, flip );
}

int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "Four Right Turns", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}

				//Initialize SDL_ttf
				if( TTF_Init() == -1 )
				{
					printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
					success = false;					}
				}
			}
		}

		return success;
	}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load texture
	gTexture = loadTexture( background_location );
	if( gTexture == NULL )
	{
		printf( "Failed to load texture image!\n" );
		success = false;
	}

	gFont = TTF_OpenFont("assets/OpenSans.ttf", 48);
	if (gFont == NULL)
	{
		printf("Failed to load font. SDL_ttf Error: %s\n", TTF_GetError() );
		success = false;
	}
	else
	{
		SDL_Color textColor = { 0, 0, 0 };
		if (!displayed_text.loadFromRenderedText(message.str(), textColor ) )
		{
			printf("Failed to render text texture \n");
			success = false;
		}
	}

	//Nothing to load
	return success;
}

void close()
{
	//Free loaded image
	SDL_DestroyTexture( gTexture );
	gTexture = NULL;
	displayed_text.free();
	TTF_CloseFont( gFont );
	gFont = NULL;

	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
	TTF_Quit();

	delete map;
}

SDL_Texture* loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}

void changeRoom(int direction) {
	map->movePlayer(direction);
	message.str("You've entered a new room.");
	background_location = "assets/room2.png";
	loadMedia();
	//int adjRooms = map->findPlayer()->countAdjacentRooms();
	//message.str("");
	//message << "This room is connected to " << adjRooms << "rooms";
	//loadMedia();
	messages00.push_back("What would you like to do?");
}

void changeText() {
//	if (map->findPlayer().getEncounter()) {
//		messages00.push_front("What would you like to do?");
//		messages00.push_front("YOU'RE BEING ATTACKED!!");
//	}
//
	std::cout << message.str() << std::endl;

	if (message.str() == "What would you like to do?") {
		message.str("");
		//if (map->findPlayer().countAdjacentRooms() >= 1) {
			messages00.push_back("Check out the room to the right (RIGHT KEY)\n");
		//}
//		if (map->findPlayer().countAdjacentRooms() >= 2) {
			messages00.push_back("Check out the room ahead (UP KEY)\n");
//		}
//		if (map->findPlayer().countAdjacentRooms() == 3) {
			messages00.push_back("Check out the room to the left (LEFT KEY)\n");
//		}
		messages00.push_back("Look for loot (DOWN KEY)\n");
	}

	if (messages00.empty()) {
		message.str("");
		messages00.push_back("What would you like to do?");
	}

	while (!messages00.empty()) {
		message << messages00[0];
		messages00.pop_front();
	}

	if (message.str() == "You search for loot.") {
		message.str("");
//		if (!(map->findPlayer().getLoot())) {
		message.str("You searched for loot, but didn't find any.");
		loadMedia();
//		}
//		else {
//			messages00.push_back("You found: Need to finish");
//		}
	}

	loadMedia();
}

int main()
{
	srand(time(NULL));
	map = new Map(5);
	map->findPlayer();
	changeText();

	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
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
							messages00.push_front("You walk into the room ahead.");
							changeText();
							changeRoom(1);
							break;

						case SDLK_LEFT:
							messages00.push_front("You walk into the room to the left.");
							changeText();
							changeRoom(0);
							break;

						case SDLK_RIGHT: messages00.push_front("You walk into the room to the right.");
							messages00.push_front("You walk into the room ahead.");
							changeText();
							changeRoom(2);
							break;

						case SDLK_DOWN: messages00.push_front("You search for loot.");
							message.str("");
							changeText();
							break;
						}
					}

				//Clear screen
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );

				//Top viewport
				SDL_Rect topViewport;
				topViewport.x = 0;
				topViewport.y = 0;
				topViewport.w = SCREEN_WIDTH;
				topViewport.h = (3 * SCREEN_HEIGHT) / 4;
				SDL_RenderSetViewport( gRenderer, &topViewport );

				//Render texture to screen
				SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );


				//Bottom viewport
				SDL_Rect bottomViewport;
				bottomViewport.x = 0;
				bottomViewport.y = (3 * SCREEN_HEIGHT) / 4;
				bottomViewport.w = SCREEN_WIDTH;
				bottomViewport.h = SCREEN_HEIGHT / 4;
				SDL_RenderSetViewport( gRenderer, &bottomViewport );


				//Render texture to screen
				SDL_RenderCopy( gRenderer, displayed_text.getTexture(), NULL, NULL );


				//Update screen
				SDL_RenderPresent( gRenderer );
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}
