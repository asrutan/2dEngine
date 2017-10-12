// entity.cpp
// PA
// 1/5/16
#include <iostream>
#include <cmath>
#include "entity.h"

using namespace std;

Entity::Entity()
{
    spriteX = 0;
    spriteY = 0;
    //end private vars
    //x = 200;
   // y = 300;
    left = false;
    right = false;
    height = 50;
    width = 50;
    //end public vars
} //end constructor

Entity::~Entity()
{
} //end deconstructor

void Entity::setListID(int id)
{
	listID = id;
}//end setListID

void Entity::update()
{
} //end update

bool Entity::getIsDead()
{
	return dead;
}//end setXY

void Entity::setXY(int mx, int my)
{
	x = mx;
	y = my;
}//end setXY


void Entity::kill()
{
	dying = true;
}