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
#include "Map.hpp"
#include "AssetLoader.hpp"

// Player / Ennemies related
#include "Bokoblin.h"
#include "Player.h"
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
	std::string selectedSave;
	std::vector<Bokoblin> ennemies;
	std::vector<std::unique_ptr<sf::Sprite>> toDelete;
	float spacingBetweenMapAndBorder;
	float totalPlayTime;
	float saveTime;
	bool isRunning;
	bool isGameOver;
	bool lockClick;
	// Scenes
	bool isHomePageOn;
	bool isSettingsSceneOn;
	bool isGameplayOn;
	bool isSaveSceneOn;
	bool inDonjon;
	// Name choice
	std::string nameChoice;
	bool nameChoosing;

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