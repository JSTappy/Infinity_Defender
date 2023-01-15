/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "Rocket.h"

Rocket::Rocket() : Entity()
{
	t.start();
	this->addSprite("assets/square.tga");
	this->sprite()->color = WHITE;
	this->scale = Point2(0.3, 0.3);
}

Rocket::~Rocket()
{
	
}

void Rocket::update(float deltaTime)
{
	/*Acceleration = thrustForce * new Vector2((float)Cos(Rotation), (float)Math.Sin(Rotation));*/
	this->position += Point2(200, 200) * Point2(cos(this->rotation.z), sin(this->rotation.z)) * deltaTime;

Point3 Rocket::checkClosestEnemy(std::vector<Enemy*> enemies)
{
	Vector2 length = Vector2(1000, 1000);
	Point3 targetPosition;
	for (int i = enemies.size() - 1; i >= 0; i--)
	{
		if (!(enemies[i]->position.x < 0 || enemies[i]->position.x > SWIDTH || enemies[i]->position.y < 0 || enemies[i]->position.y > SHEIGHT))
		{
			Vector2 tempLength = Vector2(this->position.x - enemies[i]->position.x, this->position.y - enemies[i]->position.y);
			if (tempLength.getLengthSquared() < length.getLengthSquared())
			{
				length = tempLength;
				targetPosition = enemies[i]->position;
				index = i;
			}
		}
	}
	return targetPosition;
}

//check collision with its target through Vector2 getLength()
int Rocket::checkCollision(Point3 target)
{
	Vector2 length = Vector2(this->position.x - target.x, this->position.y - target.y);
	if (length.getLength() < 32)
	{
		dead = true;
		hitTarget = true;
		}
}
