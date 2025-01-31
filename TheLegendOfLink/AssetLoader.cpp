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

void Assets::initSaveSelection(sf::RenderWindow& window) {

}

void Assets::color(sf::RectangleShape& element, const sf::Color& color) {
	element.setFillColor(color);
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