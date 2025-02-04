#pragma once
// STD library
#include <iostream>
#include <thread>
#include <iomanip>
#include <sstream>
#include <ctime>

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
	Map mapDonjon;
	sf::RenderWindow window;
	sf::View mapView;
	sf::Event event;
	std::thread updateThread;
	std::vector<Entity*> objects;  // Liste des objets (genre coffres, receptacles de coeurs...)

private:
	sf::Vector2f spawnPos;
	std::vector<Bokoblin> ennemies;
	std::vector<std::unique_ptr<sf::Sprite>> toDelete;
	float spacingBetweenMapAndBorder;
	float totalPlayTime = 0.f;
	float saveTime = 0.f;
	bool isRunning;
	bool isGameOver;
	bool lockClick;
	bool isHomePageOn;
	bool isSettingsSceneOn;
	bool isGameplayOn;
	bool isSaveSceneOn;
	bool inDonjon;

public:
	Game();
	~Game();

public:
	void run();

private:
	void updateGame(sf::Event& event);
	void pollEvents();
	void draw(Assets& assets);
};