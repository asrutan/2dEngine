// enemy.cpp
// Alex Rutan
// 1//3/16
#include <iostream>
#include "enemy.h"
#include "entity.h"

using namespace std;

Enemy::Enemy()
{
    speed = 10;
    xVelocity = 0;
    //end protected inherited vars

    x = 0;
    y = 0;

    //end public inherited vars
    left = false;
    right = true;
    tick = 0;
    frame = 0;
    //end new vars

	entityID = 1;
} //end constructor

Enemy::Enemy(int direction)
{
	speed = 10;
	xVelocity = 0;
	//end protected inherited vars

	x = 0;
	y = 0;

	//end public inherited vars
	left = false;
	right = true;
	tick = 0;
	frame = 0;
	//end new vars

	dir = direction;

	entityID = 1;
} //end constructor

Enemy::~Enemy()
{
} //end deconstructor

void Enemy::update()
{
	if (!dying)
	{
		if (collided)kill();

		if (dir == 0)
		{
			x--;
			//y--;
			
			if (x < 0)
			{
				x = 800;
			}
			/*if (y < 0)
			{
				y = 600;
			}*/
		}
		else if (dir == 1)
		{
			//x++;
			y++;
			/*if (x > 800)
			{
				x = 0;
			}*/
			if (y > 600)
			{
				y = 0;
			}
		}
		else
		{

		}
	}
	else
	{
		if (height > 0 && width > 0)
		{
			height -= 2;
			width -= 2;
		}
		else dead = true;
	}
} //end update

void Enemy::tryMove()
{
    if(right)
    {
//	xNew = x + 5;
    }
    if(left)
    {
//	xNew = x - 5;
    }
//    if(!yCollided)
//    {
//	airbound = true;
//    } //end if
    
} //end move

void Enemy::fall()
{
    if(y < 10000)//max y dist at 800
    { 
  //      y = y - yVelocity;
       // yVelocity--;
	//if(yVelocity <= -45)
	//{
	//    yVelocity = -45;
	//}
	checkBottom();
    }
    else
    {
	y = 799;
	//yVelocity = 0;
//	airbound = false;
//	yCollided = true;
    }
} //end fall

void Enemy::checkBottom()
{
//    if(yCollided)
//        //y = bottom - height;
//	airbound = false;
//	yVelocity = 0;
 //   } //end if
} //end checkBottom

void Enemy::move()
{
 //   if(xCollided == 0)
    {
 //       x = xNew;
    }
  //  else
  //  {
	if(right)
	{
	    right = false;
	    left = true;
	}
	else
	{
	    right = true;
	    left = false;
	}
  //  }
//    if(airbound)
//    {
	//fall();
   // } //end if

}

void Enemy::hit()
{
    cout << "Enemy OW!!" << endl;
}
