#pragma once
// STD library
#include <iostream>

// SFML
#include "SFML/Audio.hpp"

// Shared variables (between different .cpp files)
#include "SharedVariables.h"

// Map / AssetLoader
#include "Bokoblin.h"
#include "Player.h"
#include "Map.hpp"
#include "AssetLoader.hpp"

class Game {
private:
	Player player;
	Map map;
	sf::RenderWindow window;
	sf::View mapView;
	sf::Event event;
	std::vector<Ennemies> ennemies;  // Liste des ennemis
	std::vector<Entity*> objects;  // Liste des objets (genre coffres, receptacles de coeurs...)

private:
	sf::Vector2f spawnPos;
	std::vector<Bokoblin> ennemies;
	float spacingBetweenMapAndBorder;
	bool isRunning;
	bool lockClick;
	bool isHomePageOn;
	bool isGameplayOn;
	bool isSaveSceneOn;

public:
	Game();
	~Game();

public:
	void run();

private:
	void pollEvents();
	void draw(Assets& assets);
	void update();
};