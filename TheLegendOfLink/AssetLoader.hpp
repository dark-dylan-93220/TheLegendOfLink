#pragma once

#include "SharedVariables.h"

class Assets {
public:
	Assets(sf::RenderWindow& window);
public:
	sf::Texture player;
public:
	void drawHomePage(sf::RenderWindow& window);
	void color(sf::RectangleShape& element, const sf::Color& color);
	void drawGameOver(sf::RenderWindow& window);

private:
	void loadAssetsFromFiles();
	void initHomePage(sf::RenderWindow& window);
	void initGameOver(sf::RenderWindow& window);
	void initSaveSelection(sf::RenderWindow& window);
	
};