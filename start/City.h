#pragma once
/*****************************************************************//**
 * \file   City.h
 * \brief  
 * 
 * \author Joas Sahetapy
 * \date   January 2023
 *********************************************************************/

#ifndef CITY_H
#define CITY_H

#include "Entity.h"

 /// @brief The City implementation.
class City : public Entity
{
public:

	/// @brief Constructor
	City();
	/// @brief Destructor
	virtual ~City();

	/// <summary>
	/// the amount of Hit oints the city has
	/// </summary>
	int health;

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
};

#endif /* MYENTITY_H */
