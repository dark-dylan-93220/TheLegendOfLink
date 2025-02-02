#pragma once

#include "SharedVariables.h"

class Assets {
public:
	Assets(sf::RenderWindow& window);
public:
	sf::Texture player;
public:
	void drawHomePage(sf::RenderWindow& window);
	void drawSavePage(sf::RenderWindow& window);

private:
	void loadAssetsFromFiles();
	void initHomePage(sf::RenderWindow& window);
	void initSaveSelection(sf::RenderWindow& window);
	
};