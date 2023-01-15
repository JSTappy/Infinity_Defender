/*****************************************************************//**
 * \file   Spawner.cpp
 * \brief  
 * 
 * \author Joas Sahetapy
 * \date   January 2023
 *********************************************************************/

#include "Spawner.h"
#include "timer.h"

Spawner::Spawner(City* city) : Entity()
{
	_city = city;
	t.start();
	srand(time(NULL));
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
		Point2 random = Point2(rand() % SWIDTH , rand() % SHEIGHT); //Random position 
		this->parent()->addChild(enemy);
		enemy->position = this->position + random;
		enemies.push_back(enemy);
	}
}
