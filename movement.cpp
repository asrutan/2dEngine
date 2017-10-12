// movement.cpp
// Alex Rutan
// 11/21/15
#include <iostream>
#include <SDL2/SDL.h>
#include "movement.h"

using namespace std;

Movement::Movement()
{
    SDL_Event event;
    quit = false;
    left = false;
    right = false;
    jump = false;
    attack = false;
	click = false;
} //end constructor

Movement::~Movement()
{
    quit = false;
    left = false;
    right = false;
    jump = false;
    attack = false;
} //end destructor

void Movement::keyEvents()
{
    while(SDL_PollEvent(&event) != 0)
    {
		if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				setTrue(&quit);
			} //end if

			if (event.key.keysym.sym == SDLK_RIGHT)
			{
				right = true;
			} //end if
			if (event.key.keysym.sym == SDLK_LEFT)
			{
				left = true;
			} //end if
			if (event.key.keysym.sym == SDLK_SPACE)
			{
				setTrue(&jump);
			} //end if
			if (event.key.keysym.sym == SDLK_z)
			{
				setTrue(&attack);
			}
		}
		if (event.type == SDL_KEYUP)
		{
			if (event.key.keysym.sym == SDLK_RIGHT)
			{
				right = false;
			} //end if
			if (event.key.keysym.sym == SDLK_LEFT)
			{
				left = false;
			} //end if
			if (event.key.keysym.sym == SDLK_SPACE)
			{
				setFalse(&jump);
			} //end if
			if (event.key.keysym.sym == SDLK_z)
			{
				setFalse(&attack);
			}
		}

		if (event.type == SDL_MOUSEBUTTONDOWN && event.key.repeat == 0)
		{
			click = true;
			SDL_GetMouseState(&mousex, &mousey);
		}
	} //end if
	} //end while
 //end keyEvents

void Movement::setTrue(bool *action)
{
    *action = true;
} //end setTrue

void Movement::setFalse(bool *action)
{
    *action = false;
} //end setFalse

void Movement::move(Entity *entity)
{
	if (right) { entity->mover(1); }
	else if (left) { entity->mover(0); }
}

int Movement::getMouse()
{
	if (click)
	{
		click = false;
		return(mousex, mousey);
	}
	else return 0;
}