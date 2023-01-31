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
	wave = 0;
	lobstersPerWave = 1;
	eelsPerWave = 1;
	lobstersPerWave = 0;
	anglerfishPerWave = 0;
}

Spawner::~Spawner()
{
	
}

void Spawner::update(float deltaTime)
{
	/*if (enemies.size() == 0) {

		spawners[e]->spawnWave();
		spawners[e]->wave += 1;
		spawners[e]->lobstersPerWave += 1;
		spawners[e]->eelsPerWave += 2;
		spawners[e]->anglerfishPerWave += 1;

		std::cout << this->position << " Currentwave = " << spawners[e]->wave << std::endl;
		std::cout << this->position << " lobsterperwave = " << spawners[e]->lobstersPerWave << std::endl;
		std::cout << this->position << " eelsperwave = " << spawners[e]->eelsPerWave << std::endl;
		std::cout << this->position << " anglerfishperwave = " << spawners[e]->anglerfishPerWave << std::endl;
	}*/
}

void Spawner::spawnWave()
{
		for (int i = lobstersPerWave; i >= 1; i--)
		{
			enemy = new Enemy(_city);
			enemy->addSprite("assets/enemy.tga");
			enemy->scale = Point2(0.2, 0.2);
			Point2 random = Point2(rand() % SWIDTH, rand() % SHEIGHT); //Random position 
			this->parent()->addChild(enemy);
			enemy->speed = Point2(10, 10);
			enemies.push_back(enemy);
			enemy->position = this->position + random;
		}
		for (int i = eelsPerWave; i >= 1; i--)
		{
			enemy2 = new Enemy(_city);
			enemy2->addSprite("assets/enemy2.tga");
			Point2 random = Point2(rand() % SWIDTH, rand() % SHEIGHT); //Random position 
			this->parent()->addChild(enemy2);
			enemies.push_back(enemy2);
			enemy2->health = 1;
			enemy2->speed = Point2(50, 50);
			enemy2->position = this->position + random;
		}
		for (int i = anglerfishPerWave; i >= 1; i--)
		{
			enemy3 = new Enemy(_city);
			enemy3->addSprite("assets/enemy3.tga");
			enemy3->scale = Point2(0.2, 0.2);
			Point2 random = Point2(rand() % SWIDTH, rand() % SHEIGHT); //Random position 
			this->parent()->addChild(enemy3);
			enemies.push_back(enemy3);
			enemy3->health = 10;
			enemy3->speed = Point2(1, 1);
			enemy3->position = this->position + random;
		}
}