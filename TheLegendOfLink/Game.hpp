#pragma once
// STD library
#include <iostream>
#include <thread>
#include <iomanip>
#include <sstream>

// SFML
#include "SFML/Audio.hpp"

// Shared variables (between different .cpp files)
#include "SharedVariables.h"

// Map / AssetLoader
#include "Bokoblin.h"
#include "Player.h"
#include "Map.hpp"
#include "AssetLoader.hpp"
#include "Eprojectiles.h"

class Game {
private:
	Player player;
	Map map;
	sf::RenderWindow window;
	sf::View mapView;
	sf::Event event;
	std::thread renderer;

private:
	sf::Vector2f spawnPos;
	std::vector<Bokoblin> ennemies;
	float spacingBetweenMapAndBorder;
	bool isRunning;
	bool lockClick;
	bool isHomePageOn;
	bool isSettingsSceneOn;
	bool isGameplayOn;
	bool isSaveSceneOn;

public:
	Game();
	~Game();

public:
	void run();

private:
	void update();
	void pollEvents();
	void draw(Assets& assets);

};