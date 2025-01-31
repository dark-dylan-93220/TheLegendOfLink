#pragma once

#include "SFML/Graphics.hpp"

// HomePage
class Shared {
public:
	// Fonts
	static sf::Font pixelNes;
	// Texts
	static sf::Text playButtonText;
	static sf::Text settingsButtonText;
	static sf::Text leaveButtonText;
	// Textures & Sprites
	static sf::Texture backgroundTexture;
	static sf::Texture playerTexture;
	static sf::Sprite playerSprite;
	// RectangleShape
	static sf::RectangleShape homePageBackground;
	static sf::RectangleShape playButton;
	static sf::RectangleShape settingsButton;
	static sf::RectangleShape leaveButton; // Déclenchera la sauvegarde
};