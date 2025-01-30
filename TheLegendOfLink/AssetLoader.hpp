#pragma once

#include "SFML/Graphics.hpp"
#include <memory>

namespace {
	sf::Font pixelNes;
	sf::Text playButtonText("Play", pixelNes, 35);
	sf::Text settingsButtonText("Settings", pixelNes, 35);
	sf::Text leaveButtonText("Leave", pixelNes, 35);
	sf::RectangleShape whiteBackground;
	sf::RectangleShape playButton;
	sf::RectangleShape settingsButton;
	sf::RectangleShape leaveButton; // Déclenchera la sauvegarde
	sf::Texture playerTexture;
	sf::Texture backgroundTexture;
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
	if (!pixelNes.loadFromFile("assets/fonts/pixelNes.otf"))
		std::cerr << "Chargement de la police pixelNes impossible" << '\n';
	whiteBackground.setSize(sf::Vector2f(window.getSize().y, window.getSize().y));
	whiteBackground.setFillColor(sf::Color::White);
	whiteBackground.setPosition(sf::Vector2f(window.getSize().x / 2.f - whiteBackground.getSize().x / 2.f, 0.f));
	playerTexture.loadFromFile("assets/player.png");
	playerSprite.setTexture(playerTexture);
	backgroundTexture.loadFromFile("assets/images/mainMenuBackground.jpg");
	whiteBackground.setTexture(&backgroundTexture);
	// Boutons menu home
	float spacingBGTowhiteBackground = ((window.getSize().x / 2.f) - (whiteBackground.getSize().x / 2.f));
	settingsButton.setSize(sf::Vector2f(whiteBackground.getSize().x / 3.f, whiteBackground.getSize().x / 12.f));
	settingsButton.setFillColor(sf::Color(155, 155, 155));
	settingsButton.setOutlineThickness(2.f);
	settingsButton.setOutlineColor(sf::Color::Black);
	settingsButton.setPosition(sf::Vector2f(window.getSize().x / 2.f - settingsButton.getSize().x / 2.f, whiteBackground.getSize().y / 2.f - settingsButton.getSize().y / 2.f));
	playButton = settingsButton;
	playButton.setPosition(settingsButton.getPosition().x, settingsButton.getPosition().y - settingsButton.getSize().y - whiteBackground.getSize().y * 0.02f);
	leaveButton = settingsButton;
	leaveButton.setPosition(settingsButton.getPosition().x, settingsButton.getPosition().y + settingsButton.getSize().y + whiteBackground.getSize().y * 0.02f);
	playButtonText.setFillColor(sf::Color::Black);
	playButtonText.setPosition(sf::Vector2f(window.getSize().x / 2.f - playButtonText.getLocalBounds().width / 2.f, playButton.getPosition().y + playButton.getSize().y / 2.f - playButtonText.getLocalBounds().height / 1.2f));
	settingsButtonText.setFillColor(sf::Color::Black);
	settingsButtonText.setPosition(sf::Vector2f(window.getSize().x / 2.f - settingsButtonText.getLocalBounds().width / 2.f, settingsButton.getPosition().y + settingsButton.getSize().y / 2.f - settingsButtonText.getLocalBounds().height / 1.2f));
	leaveButtonText.setFillColor(sf::Color::Black);
	leaveButtonText.setPosition(sf::Vector2f(window.getSize().x / 2.f - leaveButtonText.getLocalBounds().width / 2.f, leaveButton.getPosition().y + leaveButton.getSize().y / 2.f - leaveButtonText.getLocalBounds().height / 1.2f));
}