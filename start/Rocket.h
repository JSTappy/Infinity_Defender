/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef ROCKET_H
#define ROCKET_H

#include "Entity.h"

 /// @brief The MyEntity class is the Entity implementation.
class Rocket : public Entity
{
public:
	/// @brief Constructor
	Rocket();
	/// @brief Destructor
	virtual ~Rocket();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
};

#endif /* MYENTITY_H */
