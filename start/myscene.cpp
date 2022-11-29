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
	// Spacebar scales myentity
	// ###############################################################

	//if (input()->getKeyDown(KeyCode::Space)) {
	//	player->scale = Point(0.5f, 0.5f);
	//}
	//if (input()->getKeyUp(KeyCode::Space)) {
	//	player->scale = Point(1.0f, 1.0f);
	//}

	// ###############################################################
	// WASD moves the cube
	// ###############################################################
	if (input()->getKey(KeyCode::W)) {
		player->position -= Point3(0, 0.2, 0);
	}
	if (input()->getKey(KeyCode::S)) {
		player->position += Point3(0, 0.2, 0);
	}
	if (input()->getKey(KeyCode::A)) {
		player->position -= Point3(0.2, 0, 0);
	}
	if (input()->getKey(KeyCode::D)) {
		player->position += Point3(0.2, 0, 0);
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
	}

}
