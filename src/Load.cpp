/*
 * Load.cpp
 *
 *  Created on: 2011/06/26
 *      Author: abelmaio
 */
#include "Load.h"



SDL_Surface* load_image(std::string filename)
{
	//Temporary storage for the image that is loaded
	SDL_Surface* loadedImage = NULL;

	//The optimized image that will be used
	SDL_Surface* optimizedImage = NULL;

	//Load the image using SDL_image
	loadedImage = IMG_Load( filename.c_str() );

	//If the image loaded
	if( loadedImage != NULL )
	{
		//Create an Optimized image with Alpha (Transparency)
		optimizedImage = SDL_DisplayFormatAlpha( loadedImage );

		//Free the old image
		SDL_FreeSurface( loadedImage );
	}

	//Return the optimized image
	return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip)
{
	//Temporary rectangle to hold the offsets
	SDL_Rect offset;

	//Store the offset on the rectangle
	offset.x = x;
	offset.y = y;

	//Blit the surface
	SDL_BlitSurface( source, clip, destination, &offset );
}
