/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "myscene.h"


MyScene::MyScene() : Scene()
{
	// start the timer.
	t.start();

	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.
	player = new Player();
	enemy = new Enemy();


	player->position = Point2(SWIDTH/3, SHEIGHT/2);
	enemy->position = Point2(SWIDTH/4, SHEIGHT/4);


	player->scale = Point2(1, 1);
	enemy->scale = Point2(4, 1);


	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(player);
	this->addChild(enemy);
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(player);
	this->removeChild(enemy);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete player;
	delete enemy;
}

void MyScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	// ###############################################################
	// WASD moves the cube
	// ###############################################################
	if (input()->getKey(KeyCode::W)) {
		player->position -= Point3(0, 0.4, 0);
	}
	if (input()->getKey(KeyCode::S)) {
		player->position += Point3(0, 0.4, 0);
	}
	if (input()->getKey(KeyCode::A)) {
		player->position -= Point3(0.4, 0, 0);
	}
	if (input()->getKey(KeyCode::D)) {
		player->position += Point3(0.4, 0, 0);
	}

	float mx = input()->getMouseX();
	float my = input()->getMouseY();
	Point2 mouse = Point2(mx, my);

	float angle = atan2(mouse.y - player->position.y, mouse.x - player->position.x);

	player->rotation.z = angle;

	// clears previous Debug Draw calls
	ddClear();
	ddLine(player->position.x, player->position.y, mx, my, GREEN);

	
	if (input()->getMouse(0)) {
		rocket = new Rocket();
		rocket->position = player->position;
		rocket->rotation.z = angle;
		this->addChild(rocket);
		rockets.push_back(rocket);

	}

	for (int i = rockets.size() - 1; i >= 0; i--) { // backwards!!!
		if (rockets[i]->position.x > SWIDTH || rockets[i]->position.x < 0 || rockets[i]->position.y < 0 || rockets[i]->position.y > SHEIGHT) {
			this->removeChild(rockets[i]);
			delete rockets[i];
			rockets.erase(rockets.begin() + i);
			std::cout << "delete rocket" << std::endl;
		}
	}

}
