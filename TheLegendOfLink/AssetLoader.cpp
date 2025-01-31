#include "AssetLoader.hpp"
#include "SharedVariables.h"

#include <iostream>

namespace {
	bool done = false;
}

Assets::Assets(sf::RenderWindow& window) 
{
	loadAssetsFromFiles();
	initHomePage(window);
	initGameOver(window);
	initSaveSelection(window);
}

void Assets::loadAssetsFromFiles() {
	if (!Shared::pixelNes.loadFromFile("assets/fonts/pixelNes.otf"))
		std::cerr << "Chargement de la police pixelNes impossible" << '\n';
	for (int i = 0; i < 6 ; i++)
	{
		player.loadFromFile("assets/playerSprites/zelda_front/sprite_" + std::to_string(i) + ".png");
		Shared::playerTextures.push_back(player);
	}
	for (int i = 0; i < 6 ; i++)
	{
		player.loadFromFile("assets/playerSprites/zelda_back/sprite_" + std::to_string(i) + ".png");
		Shared::playerTexturesBack.push_back(player);
	}
	Shared::backgroundTexture.loadFromFile("assets/images/mainMenuBackground.jpg");
	Shared::gameOverBackgroundTexture.loadFromFile("assets/images/GameOverBackground.jpg");
}

void Assets::initHomePage(sf::RenderWindow& window) {

	Shared::homePageBackground.setSize(sf::Vector2f(window.getSize().y, window.getSize().y));
	Shared::homePageBackground.setFillColor(sf::Color::White);
	Shared::homePageBackground.setPosition(sf::Vector2f(window.getSize().x / 2.f - Shared::homePageBackground.getSize().x / 2.f, 0.f));
	Shared::playerSprite.setTexture(Shared::playerTextures.at(0));
	Shared::homePageBackground.setTexture(&Shared::backgroundTexture);

	// Boutons menu home
	float spacingBGTohomePageBackground = ((window.getSize().x / 2.f) - (Shared::homePageBackground.getSize().x / 2.f));

	Shared::settingsButton.setSize(sf::Vector2f(Shared::homePageBackground.getSize().x / 3.f, Shared::homePageBackground.getSize().x / 12.f));
	Shared::settingsButton.setFillColor(sf::Color(155, 155, 155));
	Shared::settingsButton.setOutlineThickness(5.f);
	Shared::settingsButton.setOutlineColor(sf::Color::Black);
	Shared::settingsButton.setPosition(sf::Vector2f(window.getSize().x / 2.f - Shared::settingsButton.getSize().x / 2.f, Shared::homePageBackground.getSize().y / 2.f - Shared::settingsButton.getSize().y / 2.f));
	
	Shared::playButton.setSize(Shared::settingsButton.getSize());
	Shared::playButton.setFillColor(Shared::settingsButton.getFillColor());
	Shared::playButton.setOutlineThickness(Shared::settingsButton.getOutlineThickness());
	Shared::playButton.setOutlineColor(Shared::settingsButton.getOutlineColor());
	Shared::playButton.setPosition(Shared::settingsButton.getPosition().x, Shared::settingsButton.getPosition().y - Shared::settingsButton.getSize().y - Shared::homePageBackground.getSize().y * 0.02f);
	
	Shared::leaveButton.setSize(Shared::settingsButton.getSize());
	Shared::leaveButton.setFillColor(Shared::settingsButton.getFillColor());
	Shared::leaveButton.setOutlineThickness(Shared::settingsButton.getOutlineThickness());
	Shared::leaveButton.setOutlineColor(Shared::settingsButton.getOutlineColor());
	Shared::leaveButton.setPosition(Shared::settingsButton.getPosition().x, Shared::settingsButton.getPosition().y + Shared::settingsButton.getSize().y + Shared::homePageBackground.getSize().y * 0.02f);
	
	// Texts
	
	Shared::playButtonText.setString("Play");
	Shared::playButtonText.setFont(Shared::pixelNes);
	Shared::playButtonText.setCharacterSize(35);
	Shared::playButtonText.setFillColor(sf::Color::Black);
	Shared::playButtonText.setPosition(sf::Vector2f(window.getSize().x / 2.f - Shared::playButtonText.getLocalBounds().width / 2.f, Shared::playButton.getPosition().y + Shared::playButton.getSize().y / 2.f - Shared::playButtonText.getLocalBounds().height / 1.2f));
	
	Shared::settingsButtonText.setString("Settings");
	Shared::settingsButtonText.setFont(Shared::pixelNes);
	Shared::settingsButtonText.setCharacterSize(35);
	Shared::settingsButtonText.setFillColor(sf::Color::Black);
	Shared::settingsButtonText.setPosition(sf::Vector2f(window.getSize().x / 2.f - Shared::settingsButtonText.getLocalBounds().width / 2.f, Shared::settingsButton.getPosition().y + Shared::settingsButton.getSize().y / 2.f - Shared::settingsButtonText.getLocalBounds().height / 1.2f));
	
	Shared::leaveButtonText.setString("Leave");
	Shared::leaveButtonText.setFont(Shared::pixelNes);
	Shared::leaveButtonText.setCharacterSize(35);
	Shared::leaveButtonText.setFillColor(sf::Color::Black);
	Shared::leaveButtonText.setPosition(sf::Vector2f(window.getSize().x / 2.f - Shared::leaveButtonText.getLocalBounds().width / 2.f, Shared::leaveButton.getPosition().y + Shared::leaveButton.getSize().y / 2.f - Shared::leaveButtonText.getLocalBounds().height / 1.2f));

}

void Assets::initGameOver(sf::RenderWindow& window) {

	Shared::gameOverBackground.setSize(sf::Vector2f(window.getSize().y, window.getSize().y));
	Shared::gameOverBackground.setFillColor(sf::Color::White);
	Shared::gameOverBackground.setPosition(sf::Vector2f(window.getSize().x / 2.f - Shared::gameOverBackground.getSize().x / 2.f, 0.f));
	Shared::gameOverBackground.setTexture(&Shared::gameOverBackgroundTexture);

	// Boutons Game Over
	float spacingBGTohomePageBackground = ((window.getSize().x / 2.f) - (Shared::gameOverBackground.getSize().x / 2.f));

	Shared::retryButton.setSize(sf::Vector2f(Shared::gameOverBackground.getSize().x / 3.f, Shared::gameOverBackground.getSize().x / 12.f));
	Shared::retryButton.setFillColor(sf::Color(155, 155, 155));
	Shared::retryButton.setOutlineThickness(5.f);
	Shared::retryButton.setOutlineColor(sf::Color::Black);
	Shared::retryButton.setPosition(sf::Vector2f(window.getSize().x / 2.f - Shared::retryButton.getSize().x / 2.f, window.getSize().y / 2.f - Shared::retryButton.getSize().y / 2.f));
	
	Shared::homeButton.setSize(Shared::retryButton.getSize());
	Shared::homeButton.setFillColor(Shared::retryButton.getFillColor());
	Shared::homeButton.setOutlineThickness(Shared::retryButton.getOutlineThickness());
	Shared::homeButton.setOutlineColor(Shared::retryButton.getOutlineColor());
	Shared::homeButton.setPosition(Shared::retryButton.getPosition().x, Shared::retryButton.getPosition().y - Shared::retryButton.getSize().y - window.getSize().y * 0.02f);
	
	// Texts

	Shared::homeButtonText.setString("Return to home");
	Shared::homeButtonText.setFont(Shared::pixelNes);
	Shared::homeButtonText.setCharacterSize(35);
	Shared::homeButtonText.setFillColor(sf::Color::Black);
	Shared::homeButtonText.setPosition(sf::Vector2f(window.getSize().x / 2.f - Shared::homeButtonText.getLocalBounds().width / 2.f, Shared::homeButton.getPosition().y + Shared::homeButton.getSize().y / 2.f - Shared::homeButtonText.getLocalBounds().height / 1.2f - Shared::homeButtonText.getLocalBounds().height / 2.f));
	
	Shared::retryButtonText.setString("Retry");
	Shared::retryButtonText.setFont(Shared::pixelNes);
	Shared::retryButtonText.setCharacterSize(35);
	Shared::retryButtonText.setFillColor(sf::Color::Black);
	Shared::retryButtonText.setPosition(sf::Vector2f(window.getSize().x / 2.f - Shared::retryButtonText.getLocalBounds().width / 2.f, Shared::retryButton.getPosition().y + Shared::retryButton.getSize().y / 2.f - Shared::retryButtonText.getLocalBounds().height / 1.2f + Shared::retryButtonText.getLocalBounds().height / 2.f));
}

void Assets::initSaveSelection(sf::RenderWindow& window) {

}

void Assets::color(sf::RectangleShape& element, const sf::Color& color) {
	element.setFillColor(color);
}

void Assets::drawGameOver(sf::RenderWindow& window) {
	window.draw(Shared::gameOverBackground);

	window.draw(Shared::retryButton);
	window.draw(Shared::homeButton);

	window.draw(Shared::retryButtonText);
	window.draw(Shared::homeButtonText);
}

void Assets::drawHomePage(sf::RenderWindow& window) {

	window.draw(Shared::homePageBackground);

	window.draw(Shared::playButton);
	window.draw(Shared::settingsButton);
	window.draw(Shared::leaveButton);

	window.draw(Shared::playButtonText);
	window.draw(Shared::settingsButtonText);
	window.draw(Shared::leaveButtonText);
}
