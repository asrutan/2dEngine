// player.h
// Alex Rutan
// 11/21/15

#ifndef PLAYER_EXIST
#define PLAYER_EXIST

#include "collideBox.h"
#include "entity.h"

class Player : public Entity
{
    private:
		collideBox aBox;
		char lastMove;

		void accelerate();
    public:
        Player();
        ~Player();
        void update();
		bool quit;
		void move();

}; //end Player

#endif //PLAYER_EXISTS
