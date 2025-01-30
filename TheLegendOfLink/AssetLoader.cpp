#include "AssetLoader.hpp"
#include "SharedVariables.h"

#include <iostream>

namespace {
	bool done = false;
}

Assets::Assets(sf::RenderWindow& window, SharedVariable& shared) {
	initHomePage(window, shared);
}

void Assets::initHomePage(sf::RenderWindow& window, SharedVariable& shared) {
	if (!shared.pixelNes.loadFromFile("assets/fonts/pixelNes.otf"))
		std::cerr << "Chargement de la police pixelNes impossible" << '\n';
	shared.homePageBackground.setSize(sf::Vector2f(window.getSize().y, window.getSize().y));
	shared.homePageBackground.setFillColor(sf::Color::White);
	shared.homePageBackground.setPosition(sf::Vector2f(window.getSize().x / 2.f - shared.homePageBackground.getSize().x / 2.f, 0.f));
	shared.playerTexture.loadFromFile("assets/player.png");
	shared.playerSprite.setTexture(shared.playerTexture);
	shared.backgroundTexture.loadFromFile("assets/images/mainMenuBackground.jpg");
	shared.homePageBackground.setTexture(&shared.backgroundTexture);
	// Boutons menu home
	float spacingBGTohomePageBackground = ((window.getSize().x / 2.f) - (shared.homePageBackground.getSize().x / 2.f));
	shared.settingsButton.setSize(sf::Vector2f(shared.homePageBackground.getSize().x / 3.f, shared.homePageBackground.getSize().x / 12.f));
	shared.settingsButton.setFillColor(sf::Color(155, 155, 155));
	shared.settingsButton.setOutlineThickness(5.f);
	shared.settingsButton.setOutlineColor(sf::Color::Black);
	shared.settingsButton.setPosition(sf::Vector2f(window.getSize().x / 2.f - shared.settingsButton.getSize().x / 2.f, shared.homePageBackground.getSize().y / 2.f - shared.settingsButton.getSize().y / 2.f));
	shared.playButton.setSize(shared.settingsButton.getSize());
	shared.playButton.setFillColor(shared.settingsButton.getFillColor());
	shared.playButton.setOutlineThickness(shared.settingsButton.getOutlineThickness());
	shared.playButton.setOutlineColor(shared.settingsButton.getOutlineColor());
	shared.playButton.setPosition(shared.settingsButton.getPosition().x, shared.settingsButton.getPosition().y - shared.settingsButton.getSize().y - shared.homePageBackground.getSize().y * 0.02f);
	shared.leaveButton.setSize(shared.settingsButton.getSize());
	shared.leaveButton.setFillColor(shared.settingsButton.getFillColor());
	shared.leaveButton.setOutlineThickness(shared.settingsButton.getOutlineThickness());
	shared.leaveButton.setOutlineColor(shared.settingsButton.getOutlineColor());
	shared.leaveButton.setPosition(shared.settingsButton.getPosition().x, shared.settingsButton.getPosition().y + shared.settingsButton.getSize().y + shared.homePageBackground.getSize().y * 0.02f);
	shared.playButtonText.setString("Play");
	shared.playButtonText.setFont(shared.pixelNes);
	shared.playButtonText.setCharacterSize(35);
	shared.playButtonText.setFillColor(sf::Color::Black);
	shared.playButtonText.setPosition(sf::Vector2f(window.getSize().x / 2.f - shared.playButtonText.getLocalBounds().width / 2.f, shared.playButton.getPosition().y + shared.playButton.getSize().y / 2.f - shared.playButtonText.getLocalBounds().height / 1.2f));
	shared.settingsButtonText.setString("Settings");
	shared.settingsButtonText.setFont(shared.pixelNes);
	shared.settingsButtonText.setCharacterSize(35);
	shared.settingsButtonText.setFillColor(sf::Color::Black);
	shared.settingsButtonText.setPosition(sf::Vector2f(window.getSize().x / 2.f - shared.settingsButtonText.getLocalBounds().width / 2.f, shared.settingsButton.getPosition().y + shared.settingsButton.getSize().y / 2.f - shared.settingsButtonText.getLocalBounds().height / 1.2f));
	shared.leaveButtonText.setString("Leave");
	shared.leaveButtonText.setFont(shared.pixelNes);
	shared.leaveButtonText.setCharacterSize(35);
	shared.leaveButtonText.setFillColor(sf::Color::Black);
	shared.leaveButtonText.setPosition(sf::Vector2f(window.getSize().x / 2.f - shared.leaveButtonText.getLocalBounds().width / 2.f, shared.leaveButton.getPosition().y + shared.leaveButton.getSize().y / 2.f - shared.leaveButtonText.getLocalBounds().height / 1.2f));
}

void Assets::color(sf::RectangleShape& element, const sf::Color& color) {
	element.setFillColor(color);
}

void Assets::drawHomePage(sf::RenderWindow& window, SharedVariable& shared) {

	window.draw(shared.homePageBackground);

	window.draw(shared.playButton);
	window.draw(shared.settingsButton);
	window.draw(shared.leaveButton);

	window.draw(shared.playButtonText);
	window.draw(shared.settingsButtonText);
	window.draw(shared.leaveButtonText);
}