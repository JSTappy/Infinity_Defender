/*****************************************************************//**
 * \file   Spawner.h
 * \brief  
 * 
 * \author Joas Sahetapy
 * \date   January 2023
 *********************************************************************/

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
	std::vector <Enemy*> enemies;

private:
	Enemy* enemy;
	City* _city;
	/* add your private declarations */
	Timer t;
};

#endif /* MYENTITY_H */
