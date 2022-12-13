/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "Spawner.h"
#include "timer.h"

Spawner::Spawner(City* city) : Entity()
{
	_city = city;
	t.start();
	this->addSprite("assets/square.tga");
	this->sprite()->color = MAGENTA;
	this->scale = Point2(1, 1);
}

Spawner::~Spawner()
{
	
}

void Spawner::update(float deltaTime)
{
	if (input()->getKeyDown(KeyCode::E)) {
		enemy = new Enemy(_city);
		srand(time(NULL));
		int rand_num = rand() % 100;
		Point2 random = Point2(rand() % SWIDTH , rand() % SHEIGHT); //Random position 
		this->parent()->addChild(enemy);
		enemy->position = this->position + random;
	}
}
