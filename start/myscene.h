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
#include <rt2d/text.h>

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
	/// <summary>
	/// list of all rockets
	/// </summary>
	std::vector <Rocket*> rockets;
	/// <summary>
	/// list of all enemies
	/// </summary>
	std::vector <Enemy*> enemies;
	/// <summary>
	/// list of all spawners
	/// </summary>
	std::vector <Spawner*> spawners;


	/// <summary>
	/// the submarine you can control by using WASD and the mouse and left mouse click
	/// </summary>
	Player* player;

	/// <summary>
	/// the projectile your submarine fires
	/// </summary>
	Rocket* rocket;

	/// <summary>
	/// the main bas you are protecting
	/// </summary>
	City* city;

	/// <summary>
	/// the bottom right spawner
	/// </summary>
	Spawner* rightSpawner;

	/// <summary>
	/// the top left spawner
	/// </summary>
	Spawner* leftSpawner;

	/// <summary>
	/// the top right spawner
	/// </summary>
	Spawner* topSpawner;

	/// <summary>
	/// the bottom left spawner
	/// </summary>
	Spawner* bottomSpawner;

	/// <summary>
	/// the background layer
	/// </summary>
	MyEntity* layer0;

	/// <summary>
	/// the layer of everything else
	/// </summary>
	MyEntity* layer1;

	/// <summary>
	/// the layer of text
	/// </summary>
	MyEntity* layer2;

	/// <summary>
	/// the wave text
	/// </summary>
	Text* wavetext;

	/// <summary>
	/// the wave text
	/// </summary>
	Text* cityhealth;



	/// <summary>
	/// loading screen (displayed when path is generating)
	/// </summary>
	int currentWave;

	/// <summary>
	/// loading screen (displayed when path is generating)
	/// </summary>
	int cityHealth;

	/// @brief a Timer to rotate the color every n seconds
	Timer t;
};

#endif /* SCENE00_H */
