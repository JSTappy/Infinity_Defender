#pragma once
/*****************************************************************//**
 * \file   Enemy.h
 * \brief  
 * 
 * \author Joas Sahetapy
 * \date   January 2023
 *********************************************************************/

#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include "City.h"

 /// @brief The MyEntity class is the Entity implementation.
class Enemy : public Entity
{
public:
	/// @brief Constructor
	Enemy(City* _city);
	/// @brief Destructor
	virtual ~Enemy();
	int health;

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
	City* _city;
	float targetangle;

};

#endif /* MYENTITY_H */
#pragma once
