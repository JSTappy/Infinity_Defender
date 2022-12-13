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

		if (t.seconds() > 0.00333f) {
			RGBAColor color = this->sprite()->color;
			this->sprite()->color = Color::rotate(color, 0.01f);
			t.start();
		}
}
