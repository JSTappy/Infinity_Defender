/*****************************************************************//**
 * \file   Player.h
 * \brief  
 * 
 * \author Joas Sahetapy
 * \date   January 2023
 *********************************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Rocket.h"

 /// @brief The Player implementation.
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

	/// <summary>
	/// list of  rockets
	/// </summary>
	std::vector <Rocket*> rockets;

private:
	/// <summary>
	/// single rocket
	/// </summary>
	Rocket* rocket;

	/// @brief shoot will make your player create a bullet and send them in the direction of the mouse
	void Shoot();

	/// <summary>
	/// angle is the direction you are facing
	/// </summary>
	float angle;

	/* add your private declarations */
};

#endif /* MYENTITY_H */
