/*****************************************************************//**
 * \file   Rocket.cpp
 * \brief  
 * 
 * \author joass
 * \date   January 2023
 *********************************************************************/

#include "Rocket.h"

Rocket::Rocket() : Entity()
{
	t.start();
	this->addSprite("assets/Rocket.tga");
	this->sprite()->color = WHITE;
	this->scale = Point2(0.4, 0.4);
	dead = false;
}

Rocket::~Rocket()
{
	
}

void Rocket::update(float deltaTime)
{
	this->position += Point2(400, 400) * Point2(cos(this->rotation.z), sin(this->rotation.z)) * deltaTime;
}
