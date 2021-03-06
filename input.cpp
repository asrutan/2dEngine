// input.cpp
// Alex Rutan
// 10/19/17
#include <iostream>
#include "input.h"

using namespace std;

Input::Input()
{
	SDL_Event event;
	quit = false;
} //end constructor

Input::~Input()
{
} //end destructor

void Input::keyEvents()
{
	while (SDL_PollEvent(&event) != 0)
	{
		if (event.type == SDL_MOUSEBUTTONDOWN && event.key.repeat == 0)
		{
			click = true;
			SDL_GetMouseState(&mousex, &mousey);
		}
	} //end if
} //end while
  //end keyEvents

int Input::getMouse()
{
	if (click)
	{
		click = false;
		return(mousex, mousey);
	}
	else return 0;
}