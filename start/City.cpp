/*****************************************************************//**
 * \file   City.cpp
 * \brief  
 * 
 * \author Joas Sahetapy
 * \date   January 2023
 *********************************************************************/

#include "City.h"

City::City() : Entity()
{
	health = 1;
	this->addSprite("assets/circle.tga");
	this->sprite()->color = RED;
}

City::~City()
{

}

void City::update(float deltaTime)
{

}
