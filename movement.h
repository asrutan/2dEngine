//movement.h
//Alex Rutan
//11/21/15

#ifndef MOVEMENT_EXIST
#define MOVEMENT_EXIST

#include "entity.h"

class Movement
{
    private:  

    public:
        Movement();
        ~Movement();
		void move(Entity*);
		void move(Entity * entity, double angle);
		//void move(Entity*, int); //movement by angle rather than u/d/l/r
        
}; //end Movement

#endif //MOVEMENT_EXISTS
