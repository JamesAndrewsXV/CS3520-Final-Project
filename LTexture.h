#ifndef _LTEXTURE_H
#define _LTEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include<SDL2/SDL_mixer.h>
#include <stdio.h>
#include <string>
using namespace std;

class LTexture
						{
public:
							//Initializes variables
							LTexture();

							//Deallocates memory
							~LTexture();

							//Deallocates texture
							void free();

							//Set color modulation
							void setColor( Uint8 red, Uint8 green, Uint8 blue );

							//Set blending
							void setBlendMode( SDL_BlendMode blending );

							//Set alpha modulation
							void setAlpha( Uint8 alpha );

							//Gets image dimensions
							int getWidth();
							int getHeight();

							//Gets the contained texture
							SDL_Texture* getTexture();

							//Renders texture at given point
							 void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

							//Loads image at specified path
							 bool loadFromFile( string path );

							//Creates image from font string
							 bool loadFromRenderedText( string textureText, SDL_Color textColor );

							 void setFont(TTF_Font * font);

							 void setRenderer(SDL_Renderer * renderer);
						private:
							//The actual hardware texture
							SDL_Texture* mTexture;

							//Image dimensions
							int mWidth;
							int mHeight;

							//Font in use
							TTF_Font *gFont = NULL;

							//The window renderer
							SDL_Renderer* gRenderer = NULL;
						};
#endif
