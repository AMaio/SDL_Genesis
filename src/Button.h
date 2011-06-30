#ifndef BUTTON_H
#define BUTTON_H


#include "Globals.h"






class Button
{
    private:

    //Attributes of the button
    SDL_Rect box;

    //The part of the button sprite sheet that will be shown
    SDL_Rect* clip;

    public:

    //Initialize the variables
    Button(int x, int y, int w, int h, SDL_Rect cli);

    //Handles Events and set the button sprite region
    void handle_events(SDL_Event evnt, SDL_Rect cli_arr[]);


    int getX();
    int getY();
    SDL_Rect* getClip();

};

#endif // BUTTON_H
