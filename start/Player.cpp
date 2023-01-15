/*****************************************************************//**
 * \file   Player.cpp
 * \brief  
 * 
 * \author Joas Sahetapy
 * \date   January 2023
 *********************************************************************/

#include "Player.h"

Player::Player() : Entity()
{
	maxHealth = 3;
	this->addSprite("assets/square.tga");
	this->sprite()->color = YELLOW;
	
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

	angle = atan2(mouse.y - this->position.y, mouse.x - this->position.x);
	this->rotation.z = angle;


	if (input()->getMouseDown(0)) {
		rocket = new Rocket();
		rocket->position = this->position;
		rocket->rotation.z = angle;
		this->addChild(rocket);
		this->parent()->addChild(rocket);
		rockets.push_back(rocket);
	}
}
