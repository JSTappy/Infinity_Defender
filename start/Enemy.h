#pragma once
/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

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

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	virtual void TakeDamage(int damage);

private:
	/* add your private declarations */
	City* _city;
	float cityangle;
	int health;
	int maxHealth;

};

#endif /* MYENTITY_H */
#pragma once
