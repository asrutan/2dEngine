// game.cpp
// Alex Rutan
// 4/1/15
#include <iostream>
#include "game.h"

using namespace std;

/*
Game constructor 
defines the values used for the resolution of the screen
initializes values used by SDL for renderer, window, and textures
 */
Game::Game()
{
	Entity *entlist = new Entity[255];
	//entlist = new Entity[255];
	entcount = 0;
    //cout << "Game constructed" << endl;

	quit = false;

} //end constructor

Game::~Game()
{
	delete[] *entlist;
} //end destructor

bool Game::loadTextures()
{  
    return true;
} //end loadTextures

int Game::spawn(int entid)
{
	if (entid == 0)
		{ 
			entlist[entcount] = new Player();
			entlist[entcount]->setListID(entcount);
			entcount++;

			return 0;
		}
	else if (entid == 1)
	{
		entlist[entcount] = new Enemy(1);
		entlist[entcount]->setListID(entcount);
		entlist[entcount]->setXY(mousex, mousey);
		entcount++;
		return 0;
	}
	else if (entid == 2)
	{
		entlist[entcount] = new Enemy(2);
		entlist[entcount]->setListID(entcount);
		entlist[entcount]->setXY(mousex, mousey);
		entcount++;
		return 0;
	}
	else { cout << "can't spawn entity" << endl; return 0; }
} //end spawn

int Game::despawn(Entity* entity)
{
	if (entcount < 1) { cout << "nothing to despawn" << endl;  return 0; }

	int old = entity->getListID();
	int right = entcount - old;

	if (old < entcount)
	{
		delete entity;
		entity = NULL;
		for (int i = old; i < entcount-1; i++)
		{
			entlist[i] = entlist[i+1];
			entlist[i]->setListID(i);
		}
		entcount--;
		return 0;
	}
	else if(entity->getListID() == entcount)
	{
		delete entity;
		entity = NULL;
		entcount--;
		return 0;
	}
	else { cout << "can't despawn entity" << endl; return 0; }
} //end spawn

/*
First, take each of the textures and assign them to their own specific rectangles to be drawn later
Create and instance of map, map is loaded when it is constructed
Pass the map information on to player and the setEnemyMap via pointer
Create an instance of camera and send it values for number of rays and player's initial position
Create an instance of SDL_Event for player input, events change bools to "true"
 */
int Game::run()
{
	//display.loadTextures();

    if (!display.init())
    {
		cout << "Coudn't initialize" << endl;
    } //end if
   // else if (!loadTextures())
    //{
	//	cout << "Failed to load Texture(s)" << endl;
   // } //end if
    else
    {
		bool create = true;

		World *world = new World;
		world->define();

		display.loadTextures("player.bmp", 0);
		display.loadTextures("blocks.bmp", 1);
		spawn(0);
        bool keepGoing = true;
        while(keepGoing)
		{
			movement.keyEvents();
			if (movement.getMouse() != 0)
			{
				cout << "click" << endl;
				if (movement.mousex > 700 && movement.mousex < 750 && movement.mousey > 500 && movement.mousey < 550)
				{
					if(create)
					{
						create = false;
					}
					else create = true;
					//entlist[0]->kill();
				}
				else 
				{
					mousex = movement.mousex;
					mousey = movement.mousey;
					if (create)
					{
						if (mousex > 400)spawn(1);
						else(spawn(2));
					}
				}
			} //end if


			if (quit)
			{
				keepGoing = false;
			} //end if

			
			display.update(); // background and clear
			/**************/
			movement.move(entlist[0]); //move, checkbounds, update

			 //skeleton
			collision.checkBounds(entlist[0], world->horizonts[0]);
			collision.checkBounds(entlist[0], world->verts[0]);
			collision.checkBounds(entlist[0], world->verts[1]);

			//skeleton

			display.draw(world);

			for (int i = 0; i < entcount; i++)
			{
				movement.move(entlist[i]);
				if(i != 0)collision.checkBounds(entlist[0], entlist[i]);
				if (i != 0 && !create)collision.checkBounds(entlist[i], mousex, mousey);
				entlist[i]->update(); //if collide, do not update to newX/newY
				display.draw(entlist[i]);
				if (entlist[i]->getIsDead())despawn(entlist[i]);
			} //update entities
			  /**************/
			display.render(); //draw to screen

	    // end updates
		} //end while 
    } //end else 
    display.close();
    return (0);
}//end run
