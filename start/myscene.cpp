/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "myscene.h"
#include "collider.h"



MyScene::MyScene() : Scene()
{
	// start the timer.
	t.start();
	background = new MyEntity();
	player = new Player();

	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.
	city = new City();
	rightSpawner = new Spawner(city);
	leftSpawner = new Spawner(city);
	topSpawner = new Spawner(city);
	bottomSpawner = new Spawner(city);

	
	player->position = Point2(SWIDTH / 3, SHEIGHT / 2);
	background->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	city->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	rightSpawner->position = Point2(1500,0);
	leftSpawner->position = Point2(-1500, 0);
	topSpawner->position = Point2(0, 1000);
	bottomSpawner->position = Point2(0, -1000);


	background->scale = Point2(2, 2);
	player->scale = Point2(0.5, 0.5);
	city->scale = Point2(2, 2); 


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
	player->line()->color = WHITE;
	city->line()->color = WHITE;

	Rectangle rect1 = Rectangle(player->position.x, player->position.y, 64,64);
	Rectangle rect2 = Rectangle(city->position.x, city->position.y, 64,64);
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}


	float mx = input()->getMouseX();
	float my = input()->getMouseY();
	Point2 mouse = Point2(mx, my);

	ddClear();
	ddLine(player->position.x, player->position.y, mx, my, GREEN);

	float angle = atan2(mouse.y - player->position.y, mouse.x - player->position.x);
	player->rotation.z = angle;

	for (int i = player->rockets.size() - 1; i >= 0; i--) { // backwards!!!
		if (player->rockets[i]->position.x > SWIDTH || player->rockets[i]->position.x < 0 || player->rockets[i]->position.y < 0 || player->rockets[i]->position.y > SHEIGHT){
			this->removeChild(player->rockets[i]);
			delete player->rockets[i];
			player->rockets.erase(player->rockets.begin() + i);
			std::cout << "delete rocket" << std::endl;
		}
	}

	if (Collider::rectangle2rectangle(rect1, rect2)) {
		player->line()->color = RED;
		city->line()->color = RED;
	}
}
