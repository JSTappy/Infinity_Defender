/*****************************************************************//**
 * \file   Enemy.cpp
 * \brief  
 * 
 * \author Joas Sahetapy
 * \date   January 2023
 *********************************************************************/

#include "Enemy.h"

Enemy::Enemy(City* city) : Entity()
{
	_city = city;
	this->addSprite("assets/Lobster.tga");
	this->sprite()->color = WHITE;
	this->scale = Point2(0.2, 0.2);
	health = 2;

}

Enemy::~Enemy()
{
	
}

void Enemy::update(float deltaTime)
{
	targetangle = atan2(_city->position.y - this->position.y, _city->position.x - this->position.x);
	this->rotation.z = targetangle;
	Point2 random = Point2(rand() % 60, rand() % 60);
	this->position += (random + Point2(30, 30))* Point2(cos(this->rotation.z), sin(this->rotation.z))* deltaTime;
}
