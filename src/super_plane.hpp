#ifndef SuperPlane_H
#define SuperPlane_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>
#include <vector>
#include "gametile.hpp"
#include "npc.hpp"

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

/// SuperPlane class that has more hitpoints, and speed than Plane. Spawns multiple Planes at death
class SuperPlane : public Npc
{
public:
	/// @brief Constructor for NPC sub-class SuperPlane
	///
	/// @param root_filepath Root filepath
	/// @param sLocation Spawning location for SuperPlane
    /// @param eLocation Exit location to delete SuperPlane
	/// @param rTiles Vector of tile coordinates for SuperPlane to follow
	/// @param round Counter for round amount
	SuperPlane(std::string root_filepath,sf::Vector2f sLocation,sf::Vector2f eLocation,std::vector<GameTile*>* rTiles, int round);
		
	/// @brief Destructor
	~SuperPlane();

	/// @brief Updates inputs
	///
	/// @param dt Delta time
	virtual void Update(const float& dt);
			
	/// @brief Renders SuperPlane object
	///
	/// @param target Reference to target parameter for Gaming state to handle
	virtual void Render(sf::RenderTarget* target);
			
	/// @brief Handles the logic for SuperPlane to move along road tiles
	///
	/// @param dt Delta time
	virtual void MoveTo(const float& dt);

	/// @brief Initializes SuperPlane setting movespeed, textures, spawnpoint and hitpoints
    virtual void initNpc();
			
	/// @brief Finds the direction SuperPlane has to go
	///
	/// @param nextLocation Next tile coordinate
    std::pair<int,int> FindDirection(sf::Vector2f nextLocation);
			
	/// @brief Rotates SuperPlane object while it changes direction
	///
	/// @param x Gives x direction movement
	/// @param y Gives y direction movement
	virtual void Rotate(int x,int y);
			
	/// @brief Gets current position coordinates of SuperPlane object
	sf::Vector2f getPosition();
			
	/// @brief Gets SuperPlane's current hitpoints
	int getHitpoints();
			
	/// @brief Checks if SuperPlane has reached to exit tile
	bool hasReachedEnd();
			
	/// @brief Calculates the difference of current SuperPlane hitpoints and damage of tower
	///
	/// @param damage Damage parameter of projectile
	void dealDamage(float damage);
			
	/// @brief Slows SuperPlane's movement speed with the product of movement speed and slowing parameter
	///
	/// @param slow Slowing parameter from slimeball projectile
	void slowMovement(float slow);
		
	/// @brief Gets SuperPlane's tile count 
	int getTileCount();

protected:
	/// Movement speed
	float movementSpeed;
				
	/// Temporary movement speed to use in slowing
	float movementspeedmemory_;
				
	/// Hitpoints
    float hitpoints = 1;
				
	/// Spawn location coordinates
    sf::Vector2f spawnLocation;
				
	/// Exit location coordinates
    sf::Vector2f exitLocation;
				
	/// Next location coordinates
    sf::Vector2f nextLocation;
				
	/// Vector to save road tile coordinates
    std::vector<GameTile*>* roadTiles;
				
	/// Counter to keep count on what tile SuperPlane is on
    int tileCount = 0;
				
	/// Sprite for SuperPlane class
	sf::Sprite superPlaneTexture;
				
	/// Texture parameter
    sf::Texture* texture_;

	/// Clock to slow the SuperPlane for certain amount of time
	sf::Clock slowcooldown_;
			
	/// Boolean for SuperPlane to be on exit tile
	bool end_ = false;

	/// Root filepath
	std::string root_filepath_;
private:

};

#endif
