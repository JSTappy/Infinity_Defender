/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "City.h"

City::City() : Entity()
{
	this->addSprite("assets/circle.tga");
	this->sprite()->color = RED;
	Line s1;
	s1.addPoint(-32, -32);
	s1.addPoint(32, -32);
	s1.addPoint(32, 32);
	s1.addPoint(-32, 32);
	s1.addPoint(-32, -32);
	this->addLine(&s1);
}

City::~City()
{

}

void City::update(float deltaTime)
{
	// ###############################################################
	// Rotate
	// ###############################################################
	//this->rotation.z += HALF_PI * deltaTime; // 90 deg/sec
	//if (this->rotation.z > TWO_PI) {
	//	this->rotation.z -= TWO_PI;
	//}
}
