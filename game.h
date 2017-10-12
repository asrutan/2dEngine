// game.h
// Alex Rutan
// 4/1/15

#ifndef GAME_EXIST
#define GAME_EXIST

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"
#include <string>
#include "display.h"
#include "texture.h"
#include "player.h"
#include "enemy.h"
#include "entity.h"
#include "movement.h"
#include "collision.h"

class Game
{
    private:
    Display display;
	Movement movement;
	Collision collision;
	bool quit;

    public:
        Game();
        ~Game();
		Entity* entlist[255];
		bool loadTextures();
        int run();
		int spawn(int);
		int despawn(Entity*);
		int entcount;
		int mousex;
		int mousey;
		int playercount;
		int enemycount;
        
}; //end Game

#endif //GAME_EXISTS
