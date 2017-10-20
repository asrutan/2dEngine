//movement.h
//Alex Rutan
//11/21/15

#ifndef MOVEMENT_EXIST
#define MOVEMENT_EXIST

#include <SDL2/SDL.h>
#include <vector>
#include "entity.h"

class Movement
{
    private:
        SDL_Event event;  

    public:
        Movement();
        ~Movement();
        bool quit;    //Try making these private.
		bool left;    //
		bool jump;    //
        bool right;   //Maybe like a list or something with pointers idk.
		bool click;
		bool attack;
		void keyEvents();
        //void setTrue(bool*);
		//void setFalse(bool*);
		void move(Entity*);
		int mousex;
		int mousey;
		int getMouse();
        
}; //end Movement

#endif //MOVEMENT_EXISTS
