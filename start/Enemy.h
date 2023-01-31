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

 /// @brief The Enemy implementation.
class Enemy : public Entity
{
public:
	/// @brief Constructor
	Enemy(City* _city);
	/// @brief Destructor
	virtual ~Enemy();

	/// <summary>
	/// the amount of Hit Points the enemy has
	/// </summary>
	int health;

	/// <summary>
	/// the travelling speed of the enemy
	/// </summary>
	Point2 speed;

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */

	/// <summary>
	/// city pointer
	/// </summary>
	City* _city;

	/// <summary>
	/// the angle the enemy is suposed to go, in this case the city
	/// </summary>
	float targetangle;

};

#endif /* MYENTITY_H */
#pragma once
