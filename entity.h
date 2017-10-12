// entity.h
// Alex Rutan
// 1/3/16

#ifndef ENTITY_EXIST
#define ENTITY_EXIST

class Entity
{
    protected:
		int speed;
		int spriteX;
		int spriteY;
		int oldx;
		int xVelocity;
		bool dead = false;
		bool dying = false;

    public:
        Entity();
        ~Entity();
        virtual void update();
		void setXY(int, int);
		int x; // CHANGE THESE VALUES BACK TO PRIVATE
		int y; // THIS IS JUST TO TEST MOVING THE SPRITE IN Game!!!
		bool left;
		bool right;
		int height;
		int width;
		void mover(int);
		void move();
		//string sprite;
		int entityID;
		int uniqueID;
		int listID;
		void setListID(int id);
		bool getIsDead();
		void kill();
		bool collided = false;
		bool floorHit = false;
		bool wallHit = false;
		bool collideSide[4]; //1=right 2=left 3=top 4=bottom
	//void setTexture(*Display);
}; //end Entity

#endif //ENTITY_EXISTS
