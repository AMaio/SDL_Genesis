#include "Load.h" //Loading Functions
#include "Event_Handler.h"
#include <stdlib.h>

//Vars
SDL_Surface* screen = NULL; //Screen
SDL_Surface* background = NULL;
SDL_Surface* img1 = NULL;
SDL_Event event; //For event processing
const char* SCREEN_TITLE = "SDL APPLICATION";


//************************************************************//
//******************** LOADING FUNCTIONS ********************//
//************************************************************//
bool init()
{
	//Initialize all SDL subsystems
	if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
	{
		return false;
	}

	//Set up the screen
	screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

	//Check for errors on setting up the screen
	if( screen == NULL )
	{
		return false;
	}

	//Set the window caption
	SDL_WM_SetCaption( SCREEN_TITLE, NULL );

	//If it is here so everything is OK
	return true;
}

bool load_files()
{
	//Load images
	background = load_image("img/background.png");
	img1 = load_image("img/blast.png");

	//If there was an error in loading the image
	if( background == NULL || img1 == NULL )
	{
		return false;
	}

	//If everything OK
	return true;
}

void clean_up()
{
	//Free the images
	SDL_FreeSurface( background );
	SDL_FreeSurface( img1 );

	//Quit SDL
	SDL_Quit();
}

//**********************************************************//
//***********************MAIN BODY**************************//
//**********************************************************//
int main( int argc, char* args[] )
{

    system("pwd");
	//Vars
	bool quit = false;

	//Initialize
	if( init() == false )
	{
		return ERR_INIT;
	}

	//Load the files
	if( load_files() == false )
	{
		return ERR_LOAD_FILES;
	}

	apply_surface(0,0,background,screen);
	apply_surface(200,200,img1,screen);

	//Main LOOP - The Magic Happens Here
	while(!quit)
	{
		if( SDL_PollEvent( &event ) )
		{
			if( event.type == SDL_QUIT )
			{
				quit = true;
			}
		}
	}


	//Free the surface and quit
	clean_up();
	return 0;

}
