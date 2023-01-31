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

 /// @brief The Spawner implementation.
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

	/// <summary>
	/// list of enemies
	/// </summary>
	std::vector <Enemy*> enemies;

	/// <summary>
	/// list of spawners
	/// </summary>
	std::vector <Spawner*> spawners;

	/// <summary>
	/// the wavecount
	/// </summary>
	int wave;

	/// <summary>
	/// the amount of lobster enemies (enemy) will appear once the spawners enemy count reaches 0
	/// </summary>
	int lobstersPerSpawn;

	/// <summary>
	/// the amount of eel enemies (enemy2) will appear once the spawners enemy count reaches 0
	/// </summary>
	int eelsPerSpawn;

	/// <summary>
	/// the amount of anglerfish enemies (enemy3) will appear once the spawners enemy count reaches 0
	/// </summary>
	int anglerfishPerSpawn;

	/// <summary>
	/// function to spawn enemies 
	/// </summary>
	void SpawnEnemies();

private:
	/// <summary>
	/// the lobster enemy
	/// </summary>
	Enemy* enemy;

	/// <summary>
	/// the eel enemy
	/// </summary>
	Enemy* enemy2;

	/// <summary>
	/// the anglerfish enemy
	/// </summary>
	Enemy* enemy3;

	/// <summary>
	/// city pointer
	/// </summary>
	City* _city;

	/// @brief a Timer to rotate the color every n seconds
	Timer t;
};

#endif /* MYENTITY_H */
