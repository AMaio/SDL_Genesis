/*
 * Load.h
 *
 *  Created on: 2011/06/26
 *      Author: abelmaio
 */

#ifndef LOAD_H_
#define LOAD_H_

#include "Globals.h"
#include <string>

SDL_Surface* load_image(std::string filename);

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );

#endif /* LOAD_H_ */
