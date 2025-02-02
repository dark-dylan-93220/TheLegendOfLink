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
	Shared::playerTexture.loadFromFile("assets/player.png");
	Shared::backgroundTexture.loadFromFile("assets/images/mainMenuBackground.jpg");
	Shared::saveBackground.loadFromFile("assets/images/saveSelectionBackground.png");
	Shared::saveTitle.loadFromFile("assets/saveSelection/saveTitlePlank.png");
	Shared::saveIntSlot.loadFromFile("assets/saveSelection/saveIntSlot.jpg");
	Shared::saveIntSlotCenter.loadFromFile("assets/saveSelection/saveIntSlotCenter.jpg");
	Shared::saveSlotNumberOne.loadFromFile("assets/saveSelection/saveSlotOneNumber.png");
	Shared::saveSlotNumberTwo.loadFromFile("assets/saveSelection/saveSlotTwoNumber.png");
	Shared::saveSlotNumberThree.loadFromFile("assets/saveSelection/saveSlotThreeNumber.png");
	Shared::heartTexture.loadFromFile("assets/saveSelection/heart.png");
}

void Assets::initHomePage(sf::RenderWindow& window) {

	Shared::homePageBackground.setSize(sf::Vector2f(window.getSize().y, window.getSize().y));
	Shared::homePageBackground.setFillColor(sf::Color::White);
	Shared::homePageBackground.setPosition(sf::Vector2f(window.getSize().x / 2.f - Shared::homePageBackground.getSize().x / 2.f, 0.f));
	Shared::playerSprite.setTexture(Shared::playerTexture);
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
	Shared::savePageBackground.setSize(sf::Vector2f(window.getSize().y, window.getSize().y));
	Shared::savePageBackground.setTexture(&Shared::saveBackground);
	Shared::savePageBackground.setPosition(window.getSize().x / 2.f - window.getSize().y / 2.f, 0.f);
	Shared::saveSlotTwo.setSize(sf::Vector2f(window.getSize().y * 0.589743f, window.getSize().y / 6.f));
	Shared::saveSlotTwo.setFillColor(sf::Color(255, 255, 200, 128));
	Shared::saveSlotTwo.setPosition(sf::Vector2f(window.getSize().x / 2.f - Shared::saveSlotTwo.getSize().x / 2.f, window.getSize().y / 2.f - Shared::saveSlotTwo.getSize().y / 2.f + window.getSize().y * 0.005f));
	Shared::saveSlotOne = Shared::saveSlotTwo;
	Shared::saveSlotOne.setSize(sf::Vector2f(Shared::saveSlotTwo.getSize().x, window.getSize().y * 0.153846f));
	Shared::saveSlotOne.move(sf::Vector2f(0.f, window.getSize().y * -0.1925f));
	Shared::saveSlotThree = Shared::saveSlotTwo;
	Shared::saveSlotThree.setSize(Shared::saveSlotOne.getSize());
	Shared::saveSlotThree.move(sf::Vector2f(0.f, window.getSize().y * 0.204f));

	// Dimensions des saves slots de 46x12 pixels, variables qui m'aident à faire des mesures.
	float saveSlotXPixel = Shared::saveSlotOne.getSize().x / 46.f;
	float saveSlotYPixel = Shared::saveSlotOne.getSize().y / 12.f;
	float saveSlotCenterY = Shared::saveSlotTwo.getSize().y / 13.f; // Exception, saveSlotTwo est en 46x13 pixels :(

	// Slot 1 Int
	Shared::saveIntSlotOne.setSize(sf::Vector2f(42.f * saveSlotXPixel, 8.f * saveSlotYPixel));
	Shared::saveIntSlotOne.setPosition(Shared::saveSlotOne.getPosition().x + 2.f * saveSlotXPixel, Shared::saveSlotOne.getPosition().y + 2.f * saveSlotYPixel);
	Shared::saveIntSlotOne.setTexture(&Shared::saveIntSlot);
	Shared::saveIntSlotOne.setFillColor(sf::Color(50,50,50));

	// Slot 2 Int
	Shared::saveIntSlotTwo.setSize(sf::Vector2f(42.f * saveSlotXPixel, 9.f * saveSlotCenterY));
	Shared::saveIntSlotTwo.setPosition(Shared::saveSlotTwo.getPosition().x + 2.f * saveSlotXPixel, Shared::saveSlotTwo.getPosition().y + 2.f * saveSlotYPixel);
	Shared::saveIntSlotTwo.setTexture(&Shared::saveIntSlotCenter);
	Shared::saveIntSlotTwo.setFillColor(sf::Color(50, 50, 50));

	// Slot 3 Int
	Shared::saveIntSlotThree.setSize(sf::Vector2f(42.f * saveSlotXPixel, 8.f * saveSlotYPixel));
	Shared::saveIntSlotThree.setPosition(Shared::saveSlotThree.getPosition().x + 2.f * saveSlotXPixel, Shared::saveSlotThree.getPosition().y + 2.f * saveSlotYPixel);
	Shared::saveIntSlotThree.setTexture(&Shared::saveIntSlot);
	Shared::saveIntSlotThree.setFillColor(sf::Color(50, 50, 50));

	// Title
	Shared::savePageTitle.setSize(sf::Vector2f(5.f * window.getSize().y / 6.f, window.getSize().y / 6.f));
	Shared::savePageTitle.setTexture(&Shared::saveTitle);
	Shared::savePageTitle.setPosition(window.getSize().x / 2.f - Shared::savePageTitle.getSize().x / 2.f, Shared::savePageBackground.getSize().y * 0.025641f);

	Shared::saveTitleText.setFont(Shared::pixelNes);
	Shared::saveTitleText.setCharacterSize(40);
	Shared::saveTitleText.setFillColor(sf::Color::Black);
	Shared::saveTitleText.setString("Choose a Quest Log");
	Shared::saveTitleText.setPosition(window.getSize().x / 2.f - Shared::saveTitleText.getLocalBounds().width / 2.f, Shared::savePageTitle.getPosition().y + Shared::savePageTitle.getSize().y / 2.f - Shared::saveTitleText.getLocalBounds().height / 2.f  - Shared::saveTitleText.getLocalBounds().top);

	// Save slot numbers
	Shared::saveNumberRectOne.setSize(sf::Vector2f(Shared::saveIntSlotOne.getSize().y * 0.80f, Shared::saveIntSlotOne.getSize().y * 0.80f));
	Shared::saveNumberRectOne.setTexture(&Shared::saveSlotNumberOne);
	Shared::saveNumberRectOne.setPosition(Shared::saveIntSlotOne.getPosition().x + (13.f / 280.f) * Shared::saveIntSlotOne.getSize().x, Shared::saveIntSlotOne.getPosition().y + 0.10f * Shared::saveIntSlotOne.getSize().y);

	Shared::saveNumberRectTwo.setSize(sf::Vector2f(Shared::saveIntSlotOne.getSize().y * 0.80f, Shared::saveIntSlotTwo.getSize().y * 0.80f));
	Shared::saveNumberRectTwo.setTexture(&Shared::saveSlotNumberTwo);
	Shared::saveNumberRectTwo.setPosition(Shared::saveIntSlotOne.getPosition().x + (13.f / 280.f) * Shared::saveIntSlotOne.getSize().x, Shared::saveIntSlotTwo.getPosition().y + 0.10f * Shared::saveIntSlotTwo.getSize().y);

	Shared::saveNumberRectThree.setSize(sf::Vector2f(Shared::saveIntSlotThree.getSize().y * 0.80f, Shared::saveIntSlotThree.getSize().y * 0.80f));
	Shared::saveNumberRectThree.setTexture(&Shared::saveSlotNumberThree);
	Shared::saveNumberRectThree.setPosition(Shared::saveIntSlotThree.getPosition().x + (13.f / 280.f)* Shared::saveIntSlotThree.getSize().x, Shared::saveIntSlotThree.getPosition().y + 0.10f * Shared::saveIntSlotThree.getSize().y);

	Shared::nonCreatedSaveText.setFont(Shared::pixelNes);
	Shared::nonCreatedSaveText.setString("New Quest Log");
	Shared::nonCreatedSaveText.setCharacterSize(30);
	Shared::nonCreatedSaveText.setFillColor(sf::Color(255,255,230));
	Shared::nonCreatedSaveText.setPosition(window.getSize().x / 2.f - Shared::nonCreatedSaveText.getLocalBounds().width / 2.f + Shared::saveIntSlotTwo.getSize().x * 0.10f, Shared::saveIntSlotTwo.getPosition().y + Shared::saveIntSlotTwo.getSize().y / 2.f - Shared::nonCreatedSaveText.getLocalBounds().height / 2.f - Shared::nonCreatedSaveText.getLocalBounds().top);

	Shared::savePlayerNameText.setFont(Shared::pixelNes);
	Shared::savePlayerNameText.setString("John Doe");
	Shared::savePlayerNameText.setCharacterSize(30);
	Shared::savePlayerNameText.setFillColor(sf::Color(255,255,230));
	Shared::savePlayerNameText.setPosition(Shared::saveIntSlotOne.getPosition().x + Shared::saveIntSlotOne.getSize().x * 0.25f, Shared::saveIntSlotOne.getPosition().y + Shared::saveIntSlotOne.getSize().y * 0.10f - Shared::savePlayerNameText.getLocalBounds().top);

	Shared::saveTimePlayTimeBar.setSize(sf::Vector2f(Shared::saveIntSlotOne.getSize().x * 0.70f, Shared::saveIntSlotOne.getSize().y * 0.015f));
	Shared::saveTimePlayTimeBar.setFillColor(sf::Color(150, 100, 0));
	Shared::saveTimePlayTimeBar.setPosition(Shared::savePlayerNameText.getPosition().x, Shared::savePlayerNameText.getPosition().y + Shared::savePlayerNameText.getLocalBounds().height + Shared::saveIntSlotOne.getSize().y * 0.20f);

	Shared::heartSprite.setSize(sf::Vector2f(0.23f * Shared::saveIntSlotOne.getSize().y, 0.23f * Shared::saveIntSlotOne.getSize().y));
	Shared::heartSprite.setTexture(&Shared::heartTexture);
	Shared::heartSprite.setPosition(Shared::savePlayerNameText.getPosition().x + Shared::savePlayerNameText.getLocalBounds().width + 0.03f * Shared::saveIntSlotOne.getSize().x, Shared::savePlayerNameText.getPosition().y);

	Shared::saveTimeText.setFont(Shared::pixelNes);
	Shared::saveTimeText.setCharacterSize(15);
	Shared::saveTimeText.setFillColor(sf::Color(147,147,255));
	Shared::saveTimeText.setString("Save time");
	Shared::saveTimeText.setPosition(Shared::savePlayerNameText.getPosition().x + (0.70f * Shared::saveIntSlotOne.getSize().x) * 0.45f - Shared::saveTimeText.getLocalBounds().width, 0.3f * Shared::saveIntSlotOne.getSize().y + Shared::savePlayerNameText.getPosition().y + Shared::savePlayerNameText.getLocalBounds().height - Shared::saveTimeText.getLocalBounds().top);

	Shared::totalPlayTimeText.setFont(Shared::pixelNes);
	Shared::totalPlayTimeText.setCharacterSize(15);
	Shared::totalPlayTimeText.setFillColor(sf::Color(83, 162, 0));
	Shared::totalPlayTimeText.setString("Total play time");
	Shared::totalPlayTimeText.setPosition(Shared::savePlayerNameText.getPosition().x + (0.70f * Shared::saveIntSlotOne.getSize().x) * 0.45f - Shared::totalPlayTimeText.getLocalBounds().width, Shared::saveNumberRectOne.getPosition().y + Shared::saveNumberRectOne.getSize().y - Shared::totalPlayTimeText.getLocalBounds().height - Shared::totalPlayTimeText.getLocalBounds().top);
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

void Assets::drawSavePage(sf::RenderWindow& window) {

	window.draw(Shared::savePageBackground);

	window.draw(Shared::savePageTitle);
	window.draw(Shared::saveTitleText);

	// Pour tester seulement
	int numberOfHearts = 3;

	// Slot 1
	window.draw(Shared::saveSlotOne);
	window.draw(Shared::saveIntSlotOne);
	window.draw(Shared::saveNumberRectOne);
	window.draw(Shared::savePlayerNameText);

	for (int i = 0; i < numberOfHearts; ++i) {
		window.draw(Shared::heartSprite);
		Shared::heartSprite.move(0.26f * Shared::saveIntSlotOne.getSize().y, 0.f);
	}
	Shared::heartSprite.setPosition(Shared::savePlayerNameText.getPosition().x + Shared::savePlayerNameText.getLocalBounds().width + 0.04f * Shared::saveIntSlotOne.getSize().x, Shared::savePlayerNameText.getPosition().y);

	window.draw(Shared::saveTimeText);
	Shared::saveTimePlayTimeBar.setPosition(Shared::savePlayerNameText.getPosition().x, Shared::savePlayerNameText.getPosition().y + Shared::savePlayerNameText.getLocalBounds().height + Shared::saveIntSlotOne.getSize().y * 0.20f);
	window.draw(Shared::saveTimePlayTimeBar);
	window.draw(Shared::totalPlayTimeText);
	Shared::saveTimePlayTimeBar.setPosition(Shared::savePlayerNameText.getPosition().x, Shared::saveTimeText.getPosition().y + Shared::saveTimeText.getLocalBounds().height + Shared::saveIntSlotOne.getSize().y * 0.13f);
	window.draw(Shared::saveTimePlayTimeBar);
	
	// Slot 2
	window.draw(Shared::saveSlotTwo);
	window.draw(Shared::saveIntSlotTwo);
	window.draw(Shared::saveNumberRectTwo);
	window.draw(Shared::nonCreatedSaveText);

	// Slot 3
	window.draw(Shared::saveSlotThree);
	window.draw(Shared::saveIntSlotThree);
	window.draw(Shared::saveNumberRectThree);
	Shared::nonCreatedSaveText.setPosition(window.getSize().x / 2.f - Shared::nonCreatedSaveText.getLocalBounds().width / 2.f + Shared::saveIntSlotThree.getSize().x * 0.10f, Shared::saveIntSlotThree.getPosition().y + Shared::saveIntSlotThree.getSize().y / 2.f - Shared::nonCreatedSaveText.getLocalBounds().height / 2.f - Shared::nonCreatedSaveText.getLocalBounds().top);
	window.draw(Shared::nonCreatedSaveText);
	Shared::nonCreatedSaveText.setPosition(window.getSize().x / 2.f - Shared::nonCreatedSaveText.getLocalBounds().width / 2.f + Shared::saveIntSlotTwo.getSize().x * 0.10f, Shared::saveIntSlotTwo.getPosition().y + Shared::saveIntSlotTwo.getSize().y / 2.f - Shared::nonCreatedSaveText.getLocalBounds().height / 2.f - Shared::nonCreatedSaveText.getLocalBounds().top);

}