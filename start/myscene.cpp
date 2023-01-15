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
#include "collider.h"



MyScene::MyScene() : Scene()
{
	// start the timer.
	t.start();

	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.
	background = new MyEntity();
	player = new Player();
	city = new City();
	rightSpawner = new Spawner(city);
	leftSpawner = new Spawner(city);
	topSpawner = new Spawner(city);
	bottomSpawner = new Spawner(city);

	spawners.push_back(leftSpawner);
	spawners.push_back(rightSpawner);
	spawners.push_back(topSpawner);
	spawners.push_back(bottomSpawner);


	player->position = Point2(SWIDTH / 3, SHEIGHT / 2);
	background->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	city->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	rightSpawner->position = Point2(1500, 0);
	leftSpawner->position = Point2(-1500, 0);
	topSpawner->position = Point2(0, 1000);
	bottomSpawner->position = Point2(0, -1000);


	background->scale = Point2(2, 2);
	player->scale = Point2(0.5, 0.5);
	city->scale = Point2(2, 2);

	city->health = 20;


	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(background);
	this->addChild(player);
	this->addChild(city);
	this->addChild(rightSpawner);
	this->addChild(leftSpawner);
	this->addChild(topSpawner);
	this->addChild(bottomSpawner);
}

MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(player);
	this->removeChild(background);
	this->removeChild(city);
	this->removeChild(rightSpawner);
	this->removeChild(leftSpawner);
	this->removeChild(topSpawner);
	this->removeChild(bottomSpawner);

	// delete myentity from the heap (there was a 'new' in the constructor)

	delete player;
	delete city;
	delete rightSpawner;
	delete background;
	delete leftSpawner;
	delete topSpawner;
	delete bottomSpawner;
}

void MyScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	//for loop that makes i go down from player rockets size to zero
	for (int i = player->rockets.size() - 1; i >= 0; i--) { // backwards!!!
		Rocket* rocket = player->rockets[i]; // make the player rocket list into a local variable so its easier to type out
		for (int e = spawners.size() - 1; e >= 0; e--) { //for loop that makes i go down from player rockets sixe to zero
			for (int i = spawners[e]->enemies.size() - 1; i >= 0; i--) { //for loop that makes i go down from player rockets sixe to zero
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
					if (Vector2(rocket->position.x - enemy->position.x, rocket->position.y - enemy->position.y).getLengthSquared() < 32 * 32) {
						enemy->health -= 1;
						rocket->dead = true;
					}
					if (enemy->health <= 0){ // if the enemy health is smaller than or equal to 0 then remove the enemy from the scene and from the memory
						this->removeChild(enemy);
						delete enemy;
						enemy = nullptr;
						spawners[e]->enemies.erase(spawners[e]->enemies.begin() + i);
					}
				}
			}
		}
		//remove the rockets from the scene and the memory
			if (rocket->dead && rocket != nullptr) {
				this->removeChild(rocket);
				delete rocket;
				rocket = nullptr;
				player->rockets.erase(player->rockets.begin() + i);
				std::cout << "delete rockets" << std::endl;
			}
	}
	for (int e = spawners.size() - 1; e >= 0; e--) { //for loop that makes i go down from player rockets size to zero
		for (int i = spawners[e]->enemies.size() - 1; i >= 0; i--) { //for loop that makes i go down from player rockets size to zero
			Enemy* enemy = spawners[e]->enemies[i];  // make the player rocket list into a local variable so its easier to type out
			if (enemy != nullptr && city != nullptr) { //if the enemy is there and if the city is there
				if (Vector2(city->position.x - enemy->position.x, city->position.y - enemy->position.y).getLengthSquared() < 64 * 64) {
					city->health -= 1;
					this->removeChild(enemy);
					delete enemy;
					enemy = nullptr;
					spawners[e]->enemies.erase(spawners[e]->enemies.begin() + i);
				}
			}
		}
	}
	if (city != nullptr && city->health <= 0) {
		this->removeChild(city);
		delete city;
		city = nullptr;
	}
}
