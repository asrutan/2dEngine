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
    height = 50;
    width = 50;
	dir[0] = true;
	dir[1] = false;
	dir[2] = false;
	dir[3] = false;
	dir[4] = false;
    //end public var
} //end constructor

Entity::~Entity()
{
} //end deconstructor

void Entity::setListID(int id)
{
	listID = id;
}
int Entity::getListID()
{
	return listID;
}
int Entity::getEntityID()
{
	return entityID;
}
//end setListID

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
}

void Entity::setNewXY(int mx, int my)
{
	newX = x + mx;
	newY = y + my;
}
int Entity::getX()
{
	return x;
}
int Entity::getY()
{
	return y;
}
int Entity::getXVelocity()
{
	return xVelocity;
}
int Entity::getYVelocity()
{
	return yVelocity;
}
void Entity::setXVelocity(int xVel)
{
	xVelocity += xVel;
}
void Entity::setYVelocity(int yVel)
{
	yVelocity += yVel;
}
bool Entity::getDir(int i)
{
	return dir[i];
}
int Entity::getFriction()
{
	return friction;
}
int Entity::getSpeed()
{
	return speed;
}
int Entity::getAcceleration()
{
	return acceleration;
}
double Entity::getAngle()
{
	return angle;
}
//end setXY


void Entity::kill()
{
	dying = true;
}
