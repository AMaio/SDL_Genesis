#include "Load.h" //Loading Functions
#include "Event_Handler.h"


//Vars
SDL_Surface* screen = NULL; //Screen
SDL_Surface* background = NULL;
SDL_Surface* img1 = NULL;
SDL_Event event; //For event processing
SDL_Rect clip[4]; //Array for the clipping
SDL_Surface* message = NULL; //For TTF test
TTF_Font* font = NULL; //For the font used.
SDL_Color textColor = {0,0,0};
const char* SCREEN_TITLE = "SDL APPLICATION";
const char* fontFile = "img/Ubuntu-R.ttf";
const int fontSize = 30;

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

	//Initialize SDL_ttf
	if ( TTF_Init() == -1 )
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
	img1 = load_image("img/dots.png");

    //open the font
    font = TTF_OpenFont(fontFile,fontSize);

	//If there was an error in loading the image
	if( background == NULL || img1 == NULL )
	{
		return false;
	}

	//Check for errors on opening the font
	if( font == NULL )
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

	//Close the font
	TTF_CloseFont(font);

	//Quit SDL_ttf
	TTF_Quit();

	//Quit SDL
	SDL_Quit();
}

void clip_dots()
{
    clip[0].x = 0;
    clip[0].y = 0;
    clip[0].w = 100;
    clip[0].h = 100;

    clip[1].x = 100;
    clip[1].y = 0;
    clip[1].w = 100;
    clip[1].h = 100;

    clip[2].x = 0;
    clip[2].y = 100;
    clip[2].w = 100;
    clip[2].h = 100;

    clip[3].x = 100;
    clip[3].y = 100;
    clip[3].w = 100;
    clip[3].h = 100;

}

//**********************************************************//
//***********************MAIN BODY**************************//
//**********************************************************//
int main( int argc, char* args[] )
{

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


    //Clipping the dots for the example
    //clip_dots();

    //Fill the screen white
	//SDL_FillRect(screen,&screen->clip_rect,SDL_MapRGB(screen->format,0xFF,0xFF,0xFF));

    //Render the text
    message = TTF_RenderText_Solid(font,"The amazing font appears here!",textColor);

    //Apply images to the screen
    //apply_surface(0,0,img1,screen,&clip[0]);
    //apply_surface(540,380,img1,screen,&clip[3]);
	apply_surface(0,0,background,screen,NULL);
	apply_surface(50,200,message,screen,NULL);
	//apply_surface(200,200,img1,screen,NULL);

    //Update the screen
    if ( SDL_Flip( screen ) == -1 )
    {
    	return ERR_UPDATE_SCREEN;
    }


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
