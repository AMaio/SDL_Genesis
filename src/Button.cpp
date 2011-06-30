#include "Button.h"

Button::Button(int x, int y, int w, int h, SDL_Rect cli)
{
    box.x = x;
    box.y = y;
    box.w = w;
    box.h = h;

    clip = &cli;

}

//Handles Events and set the button sprite region
void Button::handle_events(SDL_Event evnt, SDL_Rect cli_arr[])
{
    //The mouse offsets
    int x = 0;
    int y = 0;

    //If mouse moved
    if (evnt.type == SDL_MOUSEMOTION)
    {
        //Get the mouse offsets
        x = evnt.motion.x;
        y = evnt.motion.y;

        //if the mouse is over the button
        if ( (x > box.x) && (x < box.x + box.w) && (y > box.y) && (y < box.y + box.h) )
        {
            //Change the button sprite
            clip = &cli_arr[CLIP_MOUSEOVER];
        }
        else
        {
            clip = &cli_arr[CLIP_MOUSEOUT];
        }
    }
}


int Button::getX()
{
    return box.x;
}

int Button::getY()
{
    return box.y;
}

SDL_Rect* Button::getClip()
{
    return clip;
}
