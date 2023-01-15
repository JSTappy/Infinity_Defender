/*****************************************************************//**
 * \file   myentity.cpp
 * \brief  
 * 
 * \author Joas Sahetapy
 * \date   January 2023
 *********************************************************************/

#include "myentity.h"

MyEntity::MyEntity() : Entity() 
{
	t.start();
	this->addSprite("assets/background.tga");
	this->sprite()->color = RED;
}

MyEntity::~MyEntity()
{

}

void MyEntity::update(float deltaTime)
{
	// ###############################################################
	// Rotate
	// ###############################################################
	this->rotation.z += HALF_PI * deltaTime; // 90 deg/sec
	if (this->rotation.z > TWO_PI) {
		this->rotation.z -= TWO_PI;
	}
	if (t.seconds() > 0.00333f) {
		RGBAColor color = this->sprite()->color;
		this->sprite()->color = Color::rotate(color, 0.03f);
		t.start();
	}
}
