//movement.h
//Alex Rutan
//11/21/15

#ifndef INPUT_EXIST
#define INPUT_EXIST

#include <SDL2/SDL.h>

class Input
{
private:
	SDL_Event event;
	bool quit;
	bool click;

public:
	Input();
	~Input();

	int mousex;
	int mousey;

	void keyEvents();
	int getMouse();

}; //end Input

#endif //INPUT_EXISTS
