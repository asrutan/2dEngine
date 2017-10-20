// movement.cpp
// Alex Rutan
// 11/21/15
#include <iostream>
#include "movement.h"

using namespace std;

Movement::Movement()
{
    SDL_Event event;
} //end constructor

Movement::~Movement()
{
    quit = false;
} //end destructor

void Movement::keyEvents()
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

void Movement::move(Entity *entity)
{
	//0 = stopped
	//1 = right
	//2 = left
	//3 = up
	//4 = down
	if (entity->getDir(0))
	{
		if (entity->getXVelocity() != 0)
		{
			if (entity->getXVelocity() > 0) entity->setXVelocity(entity->getFriction()*-1); //increment by friction

			else if (entity->getXVelocity() < 0) entity->setXVelocity(entity->getFriction());
		}
		if (entity->getYVelocity() != 0)
		{
			if (entity->getYVelocity() > 0) entity->setYVelocity(entity->getFriction()*-1); //increment by friction

			else if (entity->getYVelocity() < 0) entity->setYVelocity(entity->getFriction());
		}
	}
	else
	{
		if (entity->getDir(1)) // move right
		{
			if (entity->getXVelocity() < entity->getSpeed())
			{
				entity->setXVelocity(entity->getAcceleration());
			}
			//entity->setNewXY(entity->getXVelocity, 0);
		}
		if (entity->getDir(2)) // move left
		{
			if (entity->getXVelocity() > entity->getSpeed()*-1)
			{
				entity->setXVelocity(entity->getAcceleration()*-1);
			}
			//entity->setNewXY(entity->getXVelocity, 0);
		}
		if (entity->getDir(3)) // move up
		{

		}
		if (entity->getDir(4)) // move down
		{

		}
	}

	entity->setNewXY
	(
		entity->getXVelocity(),
		entity->getYVelocity()
	);
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