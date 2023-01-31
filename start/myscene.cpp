/*****************************************************************//**
 * \file   myscene.cpp
 * \brief  
 * 
 * \author Joas Sahetapy
 * \date   January 2023
 *********************************************************************/

#include <fstream>
#include <sstream>

#include "myscene.h"



MyScene::MyScene() : Scene()
{
	// start the timer.
	t.start();

	layer0 = new MyEntity(); //the background layer
	layer1 = new MyEntity(); //the layer of everything
	layer2 = new MyEntity(); //the layer of text


	player = new Player();
	city = new City();

	rightSpawner = new Spawner(city);
	leftSpawner = new Spawner(city);
	topSpawner = new Spawner(city);
	bottomSpawner = new Spawner(city);

	cityhealth = new Text();

	spawners.push_back(leftSpawner);
	spawners.push_back(rightSpawner);
	spawners.push_back(topSpawner);
	spawners.push_back(bottomSpawner);


	player->position = Point2(SWIDTH / 3, SHEIGHT / 2);
	city->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	rightSpawner->position = Point2(1500, 0);
	leftSpawner->position = Point2(-1500, 0);
	topSpawner->position = Point2(0, 1000);
	bottomSpawner->position = Point2(0, -1000);

	player->scale = Point2(0.5, 0.5);
	city->scale = Point2(2, 2);

	cityHealth = 0;
	city->health = 20;

	layer0->addSprite("assets/background.tga");
	layer0->scale = Point2(7, 1.5);

	cityhealth->message("City Health: 0", GREEN);
	cityhealth->scale = Point2(0.5f, 0.5f);
	cityhealth->position = Point2(20, 20);
	

	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(layer0);
	this->addChild(layer1);
	this->addChild(layer2);
	layer1->addChild(city);
	layer1->addChild(player);
	layer1->addChild(rightSpawner);
	layer1->addChild(leftSpawner);
	layer1->addChild(topSpawner);
	layer1->addChild(bottomSpawner);
	layer2->addChild(cityhealth);
}

MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(layer0);
	this->removeChild(layer1);
	this->removeChild(layer2);
	layer1->removeChild(city);
	layer1->removeChild(player);
	layer1->removeChild(rightSpawner);
	layer1->removeChild(leftSpawner);
	layer1->removeChild(topSpawner);
	layer1->removeChild(bottomSpawner);
	layer2->removeChild(cityhealth);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete layer0;
	delete layer1;
	delete layer2;
	delete player;
	delete city;
	delete rightSpawner;
	delete leftSpawner;
	delete topSpawner;
	delete bottomSpawner;
}

void MyScene::update(float deltaTime)
{
	cityHealth = city->health;


	for (int i = player->rockets.size() - 1; i >= 0; i--) { // backwards!!!
		Rocket* rocket = player->rockets[i]; // make the player rocket list into a local variable so its easier to type out
		for (int e = spawners.size() - 1; e >= 0; e--) {
			for (int i = spawners[e]->enemies.size() - 1; i >= 0; i--) {
				Enemy* enemy = spawners[e]->enemies[i]; // make a local variable from the enemies from the spawners so its easier to type out

				/*
				if the rocket is out of screen then the rocket will dissapear.
				if the enemy is not a nullptr and if the distance between the rocket and enemy position is smaller than 32 x 32
				then the rocket will dissapear and the enemy will take 1 damage.
				*/
				if (enemy != nullptr) {
					if (rocket->position.x > SWIDTH || rocket->position.x < 0 || rocket->position.y < 0 || rocket->position.y > SHEIGHT) {
						rocket->dead = true;
					}
					//make an if statement that checks if the rocket is colliding with the enemy
					if (Vector2(rocket->position.x - enemy->position.x, rocket->position.y - enemy->position.y).getLengthSquared() < 32 * 32) {
						rocket->dead = true;
						enemy->health -= 1;
					}
					if (enemy->health <= 0) { // if the enemy health is smaller than or equal to 0 then remove the enemy from the scene and from the memory
						layer1->removeChild(enemy);
						delete enemy;
						enemy = nullptr;
						spawners[e]->enemies.erase(spawners[e]->enemies.begin() + i);
					}
				}
			}
		}
		//remove the rockets from the scene and the memory
		if (rocket->dead && rocket != nullptr) {
			layer1->removeChild(rocket);
			delete rocket;
			rocket = nullptr;
			player->rockets.erase(player->rockets.begin() + i);
		}
	}
	for (int e = spawners.size() - 1; e >= 0; e--) {
		for (int i = spawners[e]->enemies.size() - 1; i >= 0; i--) {
			Enemy* enemy = spawners[e]->enemies[i];  // make the player rocket list into a local variable so its easier to type out

			std::string prefix2 = "City Health: ";
			std::ostringstream fullString2;
			fullString2 << prefix2 << cityHealth;
			cityhealth->message(fullString2.str(), GREEN);

			/*
			If the enemy touches the city, remove the enemy and make the city take 1 damage
			*/
			if (enemy != nullptr && city != nullptr) {
				if (Vector2(city->position.x - enemy->position.x, city->position.y - enemy->position.y).getLengthSquared() < 64 * 64) {
					city->health -= 1;
					layer1->removeChild(enemy);
					delete enemy;
					enemy = nullptr;
					spawners[e]->enemies.erase(spawners[e]->enemies.begin() + i);
				}
			}
		}

		//Remove the city when its HP has reached 0
		if (city != nullptr && city->health <= 0) {
			this->stop();
		}
	}
}
