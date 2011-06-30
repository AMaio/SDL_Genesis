/*
 * Globals.h
 *
 *  Created on: 2011/06/26
 *      Author: abelmaio
 */

#ifndef GLOBALS_H_
#define GLOBALS_H_

//Defines
#define ERR_INIT 1;
#define ERR_LOAD_FILES 2;
#define ERR_UPDATE_SCREEN 3;


//Includes
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"


//Screen properties
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

const int CLIP_MOUSEOVER = 0;
const int CLIP_MOUSEOUT = 1;
const int CLIP_MOUSEDOWN = 2;
const int CLIP_MOUSEUP = 3;




#endif /* GLOBALS_H_ */
