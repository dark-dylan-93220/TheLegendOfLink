#pragma once

#include "SFML/Graphics.hpp"

class SharedVariable {
    // HomePage
public:
	// Fonts
	sf::Font pixelNes;
	// Texts
	sf::Text playButtonText;
	sf::Text settingsButtonText;
	sf::Text leaveButtonText;
	// Textures & Sprites
	sf::Texture backgroundTexture;
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	// RectangleShape
	sf::RectangleShape homePageBackground;
	sf::RectangleShape playButton;
	sf::RectangleShape settingsButton;
	sf::RectangleShape leaveButton; // Déclenchera la sauvegarde
};