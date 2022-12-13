/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef SPAWNER_H
#define SPAWNER_H

#include <cstdlib>
#include "Entity.h"
#include "Enemy.h"
#include "City.h"

 /// @brief The MyEntity class is the Entity implementation.
class Spawner : public Entity
{
public:
	/// @brief Constructor
	Spawner(City* _city);
	/// @brief Destructor
	virtual ~Spawner();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	Enemy* enemy;
	City* _city;
	/* add your private declarations */
	Timer t;
};

#endif /* MYENTITY_H */
