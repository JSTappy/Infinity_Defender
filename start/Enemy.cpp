/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "Enemy.h"

Enemy::Enemy(City* city) : Entity()
{
	_city = city;
	maxHealth = 3;
	this->addSprite("assets/square.tga");
	this->sprite()->color = BLUE;
	Line s1;
	s1.addPoint(-32, -32);
	s1.addPoint(32, -32);
	s1.addPoint(32, 32);
	s1.addPoint(-32, 32);
	s1.addPoint(-32, -32);
	this->addLine(&s1);
	//this->position != Point2(rand() % 2000, rand() % 1100);
	this->scale = Point2(0.7, 0.7);
}

Enemy::~Enemy()
{

}

void Enemy::TakeDamage(int damage)
{
	health -= damage;
}

void Enemy::update(float deltaTime)
{
	this->line()->color = GREEN;

	if (health) {
		TakeDamage(1);
	}

	cityangle = atan2(_city->position.y - this->position.y, _city->position.x - this->position.x);
	this->rotation.z = cityangle;
	this->position += Point2(100, 100) * Point2(cos(this->rotation.z), sin(this->rotation.z)) * deltaTime;
}
