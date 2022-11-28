/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "Enemy.h"

Enemy::Enemy() : Entity()
{
	this->addSprite("assets/square.tga");
	this->sprite()->color = BLUE;
}

Enemy::~Enemy()
{

}

void Enemy::update(float deltaTime)
{
	// ###############################################################
	// Rotate
	// ###############################################################
	//this->rotation.z += HALF_PI * deltaTime; // 90 deg/sec
	//if (this->rotation.z > TWO_PI) {
	//	this->rotation.z -= TWO_PI;
	//}
}
