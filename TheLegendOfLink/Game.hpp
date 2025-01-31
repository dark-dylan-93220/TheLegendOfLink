#pragma once
#include "Player.h"
// STD library
#include <iostream>

// SFML
#include "SFML/Audio.hpp"

// Shared variables (between different .cpp files)
#include "SharedVariables.h"

// Map / AssetLoader
#include "Map.hpp"
#include "AssetLoader.hpp"

class Game {
private:
	Map map;
	sf::RenderWindow window;
	sf::View mapView;
	sf::Event event;

private:
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