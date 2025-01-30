#pragma once

#include <iostream>

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Map.hpp"

class Game {
private:
	Map map;
	sf::RenderWindow window;

public:
	Game();
	~Game();

public:
	void run();
};