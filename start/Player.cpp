/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "Player.h"

Player::Player() : Entity()
{
	maxHealth = 3;
	this->addSprite("assets/square.tga");
	this->sprite()->color = YELLOW;
	Line s1;
	s1.addPoint(-32, -32);
	s1.addPoint(32, -32);
	s1.addPoint(32, 32);
	s1.addPoint(-32, 32);
	s1.addPoint(-32, -32);
	this->addLine(&s1);
}

Player::~Player()
{
 
}

void Player::update(float deltaTime)
{
// ###############################################################
// WASD moves the player
// ###############################################################
	if (input()->getKey(KeyCode::W)) {
		this->position -= Point2(0, 0.3);
	}
	if (input()->getKey(KeyCode::S)) {
		this->position += Point2(0, 0.3);
	}
	if (input()->getKey(KeyCode::A)) {
		this->position -= Point2(0.3, 0);
	}
	if (input()->getKey(KeyCode::D)) {
		this->position += Point2(0.3, 0);
	}
	float mx = input()->getMouseX();
	float my = input()->getMouseY();
	Point2 mouse = Point2(mx, my);

	float angle = atan2(mouse.y - this->position.y, mouse.x - this->position.x);
	this->rotation.z = angle;

// ###############################################################
// Left Mouse click fires rocket
// ###############################################################
	if (input()->getMouseDown(0)) {
		rocket = new Rocket();
		rocket->position = this->position;
		/*Line s1;
		s1.addPoint(-16, -16); 
		s1.addPoint(16, -16);
		s1.addPoint(16, 16);
		s1.addPoint(-16, 16);
		s1.addPoint(-16, -16);
		rocket->addLine(&s1);*/
		rocket->rotation.z = angle;
		this->addChild(rocket);
		this->parent()->addChild(rocket);
		rockets.push_back(rocket);
	}

//	for (int i = rockets.size() - 1; i >= 0; i--) { // backwards!!!
//		if (rockets[i]->position.x > SWIDTH || rockets[i]->position.x < 0 || rockets[i]->position.y < 0 || rockets[i]->position.y > SHEIGHT) {
//			this->removeChild(rockets[i]);
//			delete rockets[i];
//			rockets.erase(rockets.begin() + i);
//			std::cout << "delete rocket" << std::endl;
//		}
//	}
//
}
