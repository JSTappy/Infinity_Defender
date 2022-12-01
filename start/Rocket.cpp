/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "Rocket.h"

Rocket::Rocket() : Entity()
{
	t.start();
	this->addSprite("assets/Rocket.tga");
	this->sprite()->color = RED;
	this->scale = Point2(5, 5);
}

Rocket::~Rocket()
{

}

void Rocket::update(float deltaTime)
{
	/*Acceleration = thrustForce * new Vector2((float)Cos(Rotation), (float)Math.Sin(Rotation));*/
	this->position += Point2(500, 500) * Point2(cos(this->rotation.z), sin(this->rotation.z)) * deltaTime;

		if (t.seconds() > 0.00333f) {
			RGBAColor color = this->sprite()->color;
			this->sprite()->color = Color::rotate(color, 0.01f);
			t.start();
		}
}
