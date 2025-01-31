#pragma once

#include "SFML/Graphics.hpp"


class Shared {
// HomePage
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
	static std::vector<sf::Texture> playerTextures;
	static std::vector<sf::Texture> playerTexturesBack;
	static sf::Sprite playerSprite;
	// RectangleShape
	static sf::RectangleShape homePageBackground;
	static sf::RectangleShape playButton;
	static sf::RectangleShape settingsButton;
	static sf::RectangleShape leaveButton; // D�clenchera la sauvegarde

// SaveScene
public:
	// Textures & Sprites
	static sf::Texture heartTexture;
	static sf::Sprite heartSprite;
	static sf::Texture b;
};