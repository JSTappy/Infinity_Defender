/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Rocket.h"

 /// @brief The MyEntity class is the Entity implementation.
class Player : public Entity
{
public:
	/// @brief Constructor
	Player();
	/// @brief Destructor
	virtual ~Player();


	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void

	virtual void update(float deltaTime);
	virtual void TakeDamage(int damage);
	std::vector <Rocket*> rockets;

private:
	Rocket* rocket;
	float angle;
	int health;
	int maxHealth;

	/* add your private declarations */
};

#endif /* MYENTITY_H */
