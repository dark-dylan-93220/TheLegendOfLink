#pragma once

#include <iostream>

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

class Game {
private:
	sf::RenderWindow window;

public:
	Game();
	~Game();

public:
	void run();
};