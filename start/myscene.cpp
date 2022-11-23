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
	enemy = new MyEntity();
	base = new MyEntity();
	player->position = Point2(SWIDTH/3, SHEIGHT/2);
	enemy->position = Point2(SWIDTH/4, SHEIGHT/4);
	base->position = Point2(SWIDTH/2, SHEIGHT/2);
	player->scale = Point2(1, 1);
	enemy->scale = Point2(4, 1);
	base->scale = Point2(0.9, 0.9);

	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(player);
	this->addChild(enemy);
	this->addChild(base);
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(player);
	this->removeChild(enemy);
	this->removeChild(base);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete player;
	delete enemy;
	delete base;
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
	// Camera Scaling??
	// ###############################################################


	
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
		player->position -= Point3(0, 1, 0);
	}
	if (input()->getKey(KeyCode::S)) {
		player->position += Point3(0, 1, 0);
	}
	if (input()->getKey(KeyCode::A)) {
		player->position -= Point3(1, 0, 0);
	}
	if (input()->getKey(KeyCode::D)) {
		player->position += Point3(1, 0, 0);
	}

	float mx = input()->getMouseX();
	float my = input()->getMouseY();

	// clears previous Debug Draw calls
	ddClear();

	ddLine(player->position.x, player->position.y, mx, my, GREEN);
	ddLine(base->position.x, base->position.y, mx, my, YELLOW);

	// ###############################################################
	// Rotate color
	// ###############################################################
	if (t.seconds() > 0.0333f) {
		RGBAColor color = player->sprite()->color;
		player->sprite()->color = Color::rotate(color, 0.01f);
		t.start();
	}
}
