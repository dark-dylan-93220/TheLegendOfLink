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

private:
	sf::Vector2f spawnPos;
	std::vector<Bokoblin> ennemies;
	bool isRunning;
	bool lockClick;
	bool isHomePageOn;
	bool isGameplayOn;

public:
	Game();
	~Game();

public:
	void run();

private:
	void pollEvents(Assets& assets);
	void draw(Assets& assets);

};