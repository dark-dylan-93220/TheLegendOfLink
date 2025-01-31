#pragma once

#include "SharedVariables.h"

class Assets {
public:
	Assets(sf::RenderWindow& window);

public:
	void drawHomePage(sf::RenderWindow& window);
	void color(sf::RectangleShape& element, const sf::Color& color);

private:
	void loadAssetsFromFiles();
	void initHomePage(sf::RenderWindow& window);
	void initSaveSelection(sf::RenderWindow& window);
	
};