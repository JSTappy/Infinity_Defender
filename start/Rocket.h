/*****************************************************************//**
 * \file   Rocket.h
 * \brief  
 * 
 * \author Joas Sahetapy
 * \date   January 2023
 *********************************************************************/

#ifndef ROCKET_H
#define ROCKET_H

#include "Entity.h"
#include "Enemy.h"


 /// @brief The Rocket implementation.
class Rocket : public Entity
{
public:
	/// <summary>
	/// checks if the rocket can be deleted or not
	/// </summary>
	bool dead;
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
	Timer t;
};

#endif /* MYENTITY_H */
