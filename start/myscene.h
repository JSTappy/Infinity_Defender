/*****************************************************************//**
 * \file   myscene.h
 * \brief  
 * 
 * \author Joas Sahetapy
 * \date   January 2023
 *********************************************************************/

#ifndef MYSCENE_H
#define MYSCENE_H

#include <rt2d/scene.h>

#include "MyEntity.h"
#include "Player.h"
#include "Enemy.h"
#include "City.h"
#include "Rocket.h"
#include "Spawner.h"

/// @brief The MyScene class is the Scene implementation.
class MyScene : public Scene
{
public:
	/// @brief Constructor
	MyScene();
	/// @brief Destructor
	virtual ~MyScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	

private:
	/// @brief the rotating square in the middle of the screen
	std::vector <Rocket*> rockets;
	std::vector <Enemy*> enemies;
	std::vector <Spawner*> spawners;

	Player* player;
	Rocket* rocket;
	City* city;
	Spawner* rightSpawner;
	Spawner* leftSpawner;
	Spawner* topSpawner;
	Spawner* bottomSpawner;
	MyEntity* background;

	float angle;

	/// @brief a Timer to rotate the color every n seconds
	Timer t;
};

#endif /* SCENE00_H */
