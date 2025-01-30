#pragma once

#include "SFML/Graphics.hpp"
#include <memory>

namespace {
	sf::RectangleShape whiteBackground;
	sf::RectangleShape playButton;
	sf::RectangleShape settingsButton;
	sf::RectangleShape leaveButton; // Déclenchera la sauvegarde
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
}

class Assets {
public:
	Assets(sf::RenderWindow& window);

private:
	void initAssets(sf::RenderWindow& window);
};

Assets::Assets(sf::RenderWindow& window) {
	initAssets(window);
}

void Assets::initAssets(sf::RenderWindow& window) {
	whiteBackground.setSize(sf::Vector2f(window.getSize().y, window.getSize().y));
	whiteBackground.setFillColor(sf::Color::White);
	whiteBackground.setPosition(sf::Vector2f(window.getSize().x / 2.f - whiteBackground.getSize().x / 2.f, 0.f));
	playerTexture.loadFromFile("assets/player.png");
	playerSprite.setTexture(playerTexture);
}