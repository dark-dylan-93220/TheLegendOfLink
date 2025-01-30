#pragma once

#include "SharedVariables.h"

class Assets {
public:
	Assets(sf::RenderWindow& window, SharedVariable& shared);

public:
	void drawHomePage(sf::RenderWindow& window, SharedVariable& shared);
	void color(sf::RectangleShape& element, const sf::Color& color);

private:
	void initHomePage(sf::RenderWindow& window, SharedVariable& shared);
	
};