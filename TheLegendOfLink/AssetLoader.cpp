#include "AssetLoader.hpp"
#include "SharedVariables.h"

#include <iostream>

Assets::Assets(sf::RenderWindow& window) 
{
	loadAssetsFromFiles();
	initHomePage(window);
	initGameOver(window);
	initSaveSelection(window);
	initSettingsPage(window);
}

void Assets::changeLanguage(const char& language) {
	switch (language) {
	case 'F': // French
		break;
	case 'E': // English
		break;
	}
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
	Shared::saveBackground.loadFromFile("assets/images/saveSelectionBackground.png");
	Shared::saveTitle.loadFromFile("assets/saveSelection/saveTitlePlank.png");
	Shared::saveIntSlot.loadFromFile("assets/saveSelection/saveIntSlot.jpg");
	Shared::saveIntSlotCenter.loadFromFile("assets/saveSelection/saveIntSlotCenter.jpg");
	Shared::saveSlotNumberOne.loadFromFile("assets/saveSelection/saveSlotOneNumber.png");
	Shared::saveSlotNumberTwo.loadFromFile("assets/saveSelection/saveSlotTwoNumber.png");
	Shared::saveSlotNumberThree.loadFromFile("assets/saveSelection/saveSlotThreeNumber.png");
	Shared::heartTexture.loadFromFile("assets/saveSelection/heart.png");
	Shared::playerSwordTexture.loadFromFile("assets/playerSprites/sword.png");
	Shared::gameOverBackgroundTexture.loadFromFile("assets/images/GameOverBackground.jpg");
	Shared::caillouxEnMietteTexture.loadFromFile("assets/tiles/caillouxEnMiette.png");
	Shared::projectileTexture.loadFromFile("assets/ennemies/projectile/rock.png");
}

void Assets::initHomePage(sf::RenderWindow& window) {

	Shared::homePageBackground.setSize(sf::Vector2f(window.getSize().y, window.getSize().y));
	Shared::homePageBackground.setFillColor(sf::Color::White);
	Shared::homePageBackground.setPosition(sf::Vector2f(window.getSize().x / 2.f - Shared::homePageBackground.getSize().x / 2.f, 0.f));
	Shared::playerSprite.setTexture(Shared::playerTextures.at(0));
	Shared::projectileSprite.setTexture(Shared::projectileTexture);
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

	// Dimensions des saves slots de 46x12 pixels, variables qui m'aident � faire des mesures.
	float saveSlotXPixel = Shared::saveSlotOne.getSize().x / 46.f;
	float saveSlotYPixel = Shared::saveSlotOne.getSize().y / 12.f;
	float saveSlotCenterY = Shared::saveSlotTwo.getSize().y / 13.f; // Exception, saveSlotTwo est en 46x13 pixels :(

	// Slot 1 Int
	Shared::saveIntSlotOne.setSize(sf::Vector2f(42.f * saveSlotXPixel, 8.f * saveSlotYPixel));
	Shared::saveIntSlotOne.setPosition(Shared::saveSlotOne.getPosition().x + 2.f * saveSlotXPixel, Shared::saveSlotOne.getPosition().y + 2.f * saveSlotYPixel);
	Shared::saveIntSlotOne.setTexture(&Shared::saveIntSlot);
	Shared::saveIntSlotOne.setFillColor(sf::Color(50, 50, 50));

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
	Shared::saveNumberRectOne.setFillColor(sf::Color(50, 50, 50));
	Shared::saveNumberRectOne.setPosition(Shared::saveIntSlotOne.getPosition().x + (13.f / 280.f) * Shared::saveIntSlotOne.getSize().x, Shared::saveIntSlotOne.getPosition().y + 0.10f * Shared::saveIntSlotOne.getSize().y);

	Shared::saveNumberRectTwo.setSize(sf::Vector2f(Shared::saveIntSlotOne.getSize().y * 0.80f, Shared::saveIntSlotTwo.getSize().y * 0.80f));
	Shared::saveNumberRectTwo.setTexture(&Shared::saveSlotNumberTwo);
	Shared::saveNumberRectTwo.setFillColor(sf::Color(50, 50, 50));
	Shared::saveNumberRectTwo.setPosition(Shared::saveIntSlotOne.getPosition().x + (13.f / 280.f) * Shared::saveIntSlotOne.getSize().x, Shared::saveIntSlotTwo.getPosition().y + 0.10f * Shared::saveIntSlotTwo.getSize().y);

	Shared::saveNumberRectThree.setSize(sf::Vector2f(Shared::saveIntSlotThree.getSize().y * 0.80f, Shared::saveIntSlotThree.getSize().y * 0.80f));
	Shared::saveNumberRectThree.setTexture(&Shared::saveSlotNumberThree);
	Shared::saveNumberRectThree.setFillColor(sf::Color(50, 50, 50));
	Shared::saveNumberRectThree.setPosition(Shared::saveIntSlotThree.getPosition().x + (13.f / 280.f)* Shared::saveIntSlotThree.getSize().x, Shared::saveIntSlotThree.getPosition().y + 0.10f * Shared::saveIntSlotThree.getSize().y);

	Shared::saveRectOneText.setFont(Shared::pixelNes);
	Shared::saveRectOneText.setCharacterSize(45);
	Shared::saveRectOneText.setFillColor(sf::Color::White);
	Shared::saveRectOneText.setString("1");
	Shared::saveRectOneText.setPosition(Shared::saveNumberRectOne.getPosition().x + Shared::saveNumberRectOne.getSize().x / 2.f - Shared::saveRectOneText.getLocalBounds().width / 2.f, Shared::saveNumberRectOne.getPosition().y + Shared::saveNumberRectOne.getSize().y / 2.f - Shared::saveRectOneText.getLocalBounds().height / 2.f - Shared::saveRectOneText.getLocalBounds().top);

	Shared::saveRectTwoText.setFont(Shared::pixelNes);
	Shared::saveRectTwoText.setCharacterSize(45);
	Shared::saveRectTwoText.setFillColor(sf::Color::White);
	Shared::saveRectTwoText.setString("2");
	Shared::saveRectTwoText.setPosition(Shared::saveNumberRectTwo.getPosition().x + Shared::saveNumberRectTwo.getSize().x / 2.f - Shared::saveRectTwoText.getLocalBounds().width / 2.f, Shared::saveNumberRectTwo.getPosition().y + Shared::saveNumberRectTwo.getSize().y / 2.f - Shared::saveRectTwoText.getLocalBounds().height / 2.f - Shared::saveRectTwoText.getLocalBounds().top);

	Shared::saveRectThreeText.setFont(Shared::pixelNes);
	Shared::saveRectThreeText.setCharacterSize(45);
	Shared::saveRectThreeText.setFillColor(sf::Color::White);
	Shared::saveRectThreeText.setString("3");
	Shared::saveRectThreeText.setPosition(Shared::saveNumberRectThree.getPosition().x + Shared::saveNumberRectThree.getSize().x / 2.f - Shared::saveRectThreeText.getLocalBounds().width / 2.f, Shared::saveNumberRectThree.getPosition().y + Shared::saveNumberRectThree.getSize().y / 2.f - Shared::saveRectThreeText.getLocalBounds().height / 2.f - Shared::saveRectThreeText.getLocalBounds().top);

	// Save non existant
	Shared::nonCreatedSaveText.setFont(Shared::pixelNes);
	Shared::nonCreatedSaveText.setString("New Quest Log");
	Shared::nonCreatedSaveText.setCharacterSize(30);
	Shared::nonCreatedSaveText.setFillColor(sf::Color(255,255,230));
	Shared::nonCreatedSaveText.setPosition(window.getSize().x / 2.f - Shared::nonCreatedSaveText.getLocalBounds().width / 2.f + Shared::saveIntSlotTwo.getSize().x * 0.10f, Shared::saveIntSlotTwo.getPosition().y + Shared::saveIntSlotTwo.getSize().y / 2.f - Shared::nonCreatedSaveText.getLocalBounds().height / 2.f - Shared::nonCreatedSaveText.getLocalBounds().top);

	// Player's name
	Shared::savePlayerNameText.setFont(Shared::pixelNes);
	Shared::savePlayerNameText.setString(Shared::saveNameOne);
	Shared::savePlayerNameText.setCharacterSize(30);
	Shared::savePlayerNameText.setFillColor(sf::Color(255,255,230));
	Shared::savePlayerNameText.setPosition(Shared::saveIntSlotOne.getPosition().x + Shared::saveIntSlotOne.getSize().x * 0.25f, Shared::saveIntSlotOne.getPosition().y + Shared::saveIntSlotOne.getSize().y * 0.10f - Shared::savePlayerNameText.getLocalBounds().top);

	// Bar separating saveTime and playTime
	Shared::saveTimePlayTimeBar.setSize(sf::Vector2f(Shared::saveIntSlotOne.getSize().x * 0.70f, Shared::saveIntSlotOne.getSize().y * 0.015f));
	Shared::saveTimePlayTimeBar.setFillColor(sf::Color(150, 100, 0));
	Shared::saveTimePlayTimeBar.setPosition(Shared::savePlayerNameText.getPosition().x, Shared::savePlayerNameText.getPosition().y + Shared::savePlayerNameText.getLocalBounds().height + Shared::saveIntSlotOne.getSize().y * 0.20f);

	// Heart sprites
	Shared::heartSprite.setSize(sf::Vector2f(0.23f * Shared::saveIntSlotOne.getSize().y, 0.23f * Shared::saveIntSlotOne.getSize().y));
	Shared::heartSprite.setTexture(&Shared::heartTexture);
	Shared::heartSprite.setPosition(Shared::savePlayerNameText.getPosition().x + Shared::savePlayerNameText.getLocalBounds().width + 0.03f * Shared::saveIntSlotOne.getSize().x, Shared::savePlayerNameText.getPosition().y);

	// Last save time
	Shared::saveTimeText.setFont(Shared::pixelNes);
	Shared::saveTimeText.setCharacterSize(15);
	Shared::saveTimeText.setFillColor(sf::Color(147,147,255));
	Shared::saveTimeText.setString("Save time");
	Shared::saveTimeText.setPosition(Shared::savePlayerNameText.getPosition().x + (0.70f * Shared::saveIntSlotOne.getSize().x) * 0.45f - Shared::saveTimeText.getLocalBounds().width, 0.3f * Shared::saveIntSlotOne.getSize().y + Shared::savePlayerNameText.getPosition().y + Shared::savePlayerNameText.getLocalBounds().height - Shared::saveTimeText.getLocalBounds().top);

	// Total playtime
	Shared::totalPlayTimeText.setFont(Shared::pixelNes);
	Shared::totalPlayTimeText.setCharacterSize(15);
	Shared::totalPlayTimeText.setFillColor(sf::Color(83, 162, 0));
	Shared::totalPlayTimeText.setString("Total play time");
	Shared::totalPlayTimeText.setPosition(Shared::savePlayerNameText.getPosition().x + (0.70f * Shared::saveIntSlotOne.getSize().x) * 0.45f - Shared::totalPlayTimeText.getLocalBounds().width, Shared::saveNumberRectOne.getPosition().y + Shared::saveNumberRectOne.getSize().y - Shared::totalPlayTimeText.getLocalBounds().height - Shared::totalPlayTimeText.getLocalBounds().top);

	// Save time value
	Shared::lastSaveTimeTextOne.setFont(Shared::pixelNes);
	Shared::lastSaveTimeTextOne.setCharacterSize(15);
	Shared::lastSaveTimeTextOne.setFillColor(Shared::saveTimeText.getFillColor());
	Shared::lastSaveTimeTextOne.setString(Shared::lastSaveTimeOneString);
	Shared::lastSaveTimeTextOne.setPosition(Shared::saveTimePlayTimeBar.getPosition().x + Shared::saveTimePlayTimeBar.getSize().x - Shared::lastSaveTimeTextOne.getLocalBounds().width, Shared::saveTimeText.getPosition().y);

	Shared::lastSaveTimeTextTwo = Shared::lastSaveTimeTextOne;
	Shared::lastSaveTimeTextTwo.setString(Shared::lastSaveTimeTwoString);

	Shared::lastSaveTimeTextThree = Shared::lastSaveTimeTextOne;
	Shared::lastSaveTimeTextThree.setString(Shared::lastSaveTimeThreeString);

	// Playtime value
	Shared::playTimeTextOne.setFont(Shared::pixelNes);
	Shared::playTimeTextOne.setCharacterSize(15);
	Shared::playTimeTextOne.setFillColor(Shared::totalPlayTimeText.getFillColor());
	Shared::playTimeTextOne.setString(Shared::playTimeOne);
	Shared::playTimeTextOne.setPosition(Shared::saveTimePlayTimeBar.getPosition().x + Shared::saveTimePlayTimeBar.getSize().x - Shared::playTimeTextOne.getLocalBounds().width, Shared::totalPlayTimeText.getPosition().y);
	
	Shared::playTimeTextTwo = Shared::playTimeTextOne;
	Shared::playTimeTextTwo.setString(Shared::playTimeTwo);

	Shared::playTimeTextThree = Shared::playTimeTextOne;
	Shared::playTimeTextThree.setString(Shared::playTimeThree);

	// Utils
	Shared::betweenSaveOneAndTwo = Shared::saveSlotTwo.getPosition().y - Shared::saveSlotOne.getPosition().y;
	Shared::betweenSaveOneAndThree = Shared::saveSlotThree.getPosition().y - Shared::saveSlotOne.getPosition().y;
	Shared::typingSaveOne = false;
	Shared::typingSaveTwo = false;
	Shared::typingSaveThree = false;

}

void Assets::initSettingsPage(sf::RenderWindow& window) {
	Shared::settingsBox.setSize(sf::Vector2f(window.getSize().y * (45.f / 78.f), window.getSize().y * (45.f / 78.f)));
	Shared::settingsBox.setPosition(window.getSize().y * (17.f / 78.f) + ((window.getSize().x - Shared::savePageBackground.getSize().x) / 2.f), (17.f / 78.f) * window.getSize().y);
	Shared::settingsBox.setFillColor(sf::Color::Black);
	Shared::settingsBox.setOutlineColor(sf::Color::White);
	Shared::settingsBox.setOutlineThickness(2.f);

	Shared::settingsFPSText.setFont(Shared::pixelNes);
	Shared::settingsFPSText.setCharacterSize(30);
	Shared::settingsFPSText.setFillColor(sf::Color::White);
	Shared::settingsFPSText.setString("FPS");
	Shared::settingsFPSText.setPosition(Shared::settingsBox.getPosition().x + Shared::settingsBox.getSize().x * 0.10f, Shared::settingsBox.getPosition().y + Shared::settingsBox.getSize().y / 2.f - Shared::settingsFPSText.getLocalBounds().height / 2.f - Shared::settingsFPSText.getLocalBounds().top - Shared::settingsBox.getSize().y / 3.f);

	Shared::settingsVolumeText = Shared::settingsFPSText;
	Shared::settingsVolumeText.setString("Volume");
	Shared::settingsVolumeText.setPosition(Shared::settingsFPSText.getPosition().x, window.getSize().y / 2.f - Shared::settingsVolumeText.getLocalBounds().height / 2.f - Shared::settingsVolumeText.getLocalBounds().top);

	Shared::settingsLanguageText = Shared::settingsFPSText;
	Shared::settingsLanguageText.setString("Language");
	Shared::settingsLanguageText.setPosition(Shared::settingsFPSText.getPosition().x, Shared::settingsBox.getPosition().y + Shared::settingsBox.getSize().y / 2.f - Shared::settingsLanguageText.getLocalBounds().height / 2.f - Shared::settingsLanguageText.getLocalBounds().top + Shared::settingsBox.getSize().y / 3.f);

	Shared::frenchLanguageText = Shared::settingsLanguageText;
	Shared::frenchLanguageText.setString("< FRANCAIS >");
	Shared::frenchLanguageText.setPosition(Shared::settingsBox.getPosition().x + Shared::settingsBox.getSize().x - Shared::frenchLanguageText.getLocalBounds().width - Shared::settingsBox.getSize().x * 0.10f, Shared::settingsLanguageText.getPosition().y);

	Shared::englishLanguageText = Shared::frenchLanguageText;
	Shared::englishLanguageText.setString("< ENGLISH >");
	Shared::englishLanguageText.setPosition(Shared::settingsBox.getPosition().x + Shared::settingsBox.getSize().x - Shared::englishLanguageText.getLocalBounds().width - Shared::settingsBox.getSize().x * 0.10f, Shared::settingsLanguageText.getPosition().y);Shared::englishLanguageText.setPosition(Shared::settingsBox.getPosition().x + Shared::settingsBox.getSize().x - Shared::englishLanguageText.getLocalBounds().width - Shared::settingsBox.getSize().x * 0.10f, Shared::settingsLanguageText.getPosition().y);

	Shared::settingsVolumeSlider.setSize(sf::Vector2f(Shared::settingsBox.getSize().x / 3.f, Shared::settingsVolumeText.getLocalBounds().height));
	Shared::settingsVolumeSlider.setPosition(Shared::settingsBox.getSize().x + Shared::settingsBox.getPosition().x - Shared::settingsVolumeSlider.getSize().x - Shared::settingsBox.getSize().x * 0.15f, Shared::settingsVolumeText.getPosition().y + Shared::settingsVolumeText.getLocalBounds().top);
	Shared::settingsVolumeSlider.setOutlineThickness(2.f);
	Shared::settingsVolumeSlider.setOutlineColor(sf::Color::White);
	Shared::settingsVolumeSlider.setFillColor(sf::Color(150,150,150));

	Shared::settingsPlusText = Shared::settingsVolumeText;
	Shared::settingsPlusText.setString("+");
	Shared::settingsPlusText.setPosition(Shared::settingsBox.getSize().x + Shared::settingsBox.getPosition().x - Shared::settingsBox.getSize().x * 0.10f - Shared::settingsPlusText.getLocalBounds().width, Shared::settingsVolumeText.getPosition().y);

	Shared::settingsMinusText = Shared::settingsPlusText;
	Shared::settingsMinusText.setString("-");
	Shared::settingsMinusText.setPosition(Shared::settingsVolumeSlider.getPosition().x + ((Shared::settingsVolumeSlider.getPosition().x + Shared::settingsVolumeSlider.getSize().x) - Shared::settingsPlusText.getPosition().x) - 0.02f * Shared::settingsBox.getSize().x, Shared::settingsPlusText.getPosition().y);

	Shared::settingsFPS60Text = Shared::frenchLanguageText;
	Shared::settingsFPS60Text.setString("< 60 FPS >");
	Shared::settingsFPS60Text.setPosition(Shared::settingsBox.getPosition().x + Shared::settingsBox.getSize().x - Shared::settingsFPS60Text.getLocalBounds().width - Shared::settingsBox.getSize().x * 0.10f, Shared::settingsFPSText.getPosition().y);

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

void Assets::drawSavePage(sf::RenderWindow& window) {

	window.draw(Shared::savePageBackground);

	window.draw(Shared::savePageTitle);
	window.draw(Shared::saveTitleText);

	// Slot 1
	window.draw(Shared::saveSlotOne);
	window.draw(Shared::saveIntSlotOne);
	window.draw(Shared::saveNumberRectOne);
	window.draw(Shared::saveRectOneText);

	if (Shared::saveOneExists) {
		Shared::savePlayerNameText.setString(Shared::saveNameOne);
		Shared::savePlayerNameText.setPosition(Shared::saveIntSlotOne.getPosition().x + Shared::saveIntSlotOne.getSize().x * 0.25f, Shared::saveIntSlotOne.getPosition().y + Shared::saveIntSlotOne.getSize().y * 0.10f - Shared::savePlayerNameText.getLocalBounds().top);
		window.draw(Shared::savePlayerNameText);
		Shared::heartSprite.setPosition(Shared::savePlayerNameText.getPosition().x + (0.70f * Shared::saveIntSlotOne.getSize().x) * 0.45f + 0.05f * Shared::saveIntSlotOne.getSize().x, Shared::savePlayerNameText.getPosition().y);
		for (int i = 0; i < Shared::numberOfHeartsOne; ++i) {
			window.draw(Shared::heartSprite);
			Shared::heartSprite.move(0.26f * Shared::saveIntSlotOne.getSize().y, 0.f);
		}
		Shared::heartSprite.setPosition(Shared::savePlayerNameText.getPosition().x + Shared::savePlayerNameText.getLocalBounds().width + 0.04f * Shared::saveIntSlotOne.getSize().x, Shared::savePlayerNameText.getPosition().y);

		Shared::saveTimeText.setPosition(Shared::savePlayerNameText.getPosition().x + (0.70f * Shared::saveIntSlotOne.getSize().x) * 0.45f - Shared::saveTimeText.getLocalBounds().width, 0.3f * Shared::saveIntSlotOne.getSize().y + Shared::savePlayerNameText.getPosition().y + Shared::savePlayerNameText.getLocalBounds().height - Shared::saveTimeText.getLocalBounds().top);
		window.draw(Shared::saveTimeText);
		window.draw(Shared::lastSaveTimeTextOne);
		Shared::saveTimePlayTimeBar.setPosition(Shared::savePlayerNameText.getPosition().x, Shared::savePlayerNameText.getPosition().y + Shared::savePlayerNameText.getLocalBounds().height + Shared::saveIntSlotOne.getSize().y * 0.20f);
		window.draw(Shared::saveTimePlayTimeBar);
		Shared::totalPlayTimeText.setPosition(Shared::savePlayerNameText.getPosition().x + (0.70f * Shared::saveIntSlotOne.getSize().x) * 0.45f - Shared::totalPlayTimeText.getLocalBounds().width, Shared::saveNumberRectOne.getPosition().y + Shared::saveNumberRectOne.getSize().y - Shared::totalPlayTimeText.getLocalBounds().height - Shared::totalPlayTimeText.getLocalBounds().top);
		window.draw(Shared::totalPlayTimeText);
		window.draw(Shared::playTimeTextOne);
		Shared::saveTimePlayTimeBar.setPosition(Shared::savePlayerNameText.getPosition().x, Shared::saveTimeText.getPosition().y + Shared::saveTimeText.getLocalBounds().height + Shared::saveIntSlotOne.getSize().y * 0.13f);
		window.draw(Shared::saveTimePlayTimeBar);
	}
	else {
		Shared::nonCreatedSaveText.move(0, -Shared::betweenSaveOneAndTwo - 1.f);
		if(!Shared::typingSaveOne)
			window.draw(Shared::nonCreatedSaveText);
		Shared::nonCreatedSaveText.move(0, Shared::betweenSaveOneAndTwo + 1.f);
	}

	// Slot 2
	window.draw(Shared::saveSlotTwo);
	window.draw(Shared::saveIntSlotTwo);
	window.draw(Shared::saveNumberRectTwo);
	window.draw(Shared::saveRectTwoText);

	if (Shared::saveTwoExists) {
		Shared::savePlayerNameText.move(0, Shared::betweenSaveOneAndTwo);
		Shared::saveTimeText.setPosition(Shared::savePlayerNameText.getPosition().x + (0.70f * Shared::saveIntSlotTwo.getSize().x) * 0.45f - Shared::saveTimeText.getLocalBounds().width, 0.3f * Shared::saveIntSlotTwo.getSize().y + Shared::savePlayerNameText.getPosition().y + Shared::savePlayerNameText.getLocalBounds().height - Shared::saveTimeText.getLocalBounds().top);
		Shared::totalPlayTimeText.setPosition(Shared::savePlayerNameText.getPosition().x + (0.70f * Shared::saveIntSlotTwo.getSize().x) * 0.45f - Shared::totalPlayTimeText.getLocalBounds().width, Shared::saveNumberRectTwo.getPosition().y + Shared::saveNumberRectTwo.getSize().y - Shared::totalPlayTimeText.getLocalBounds().height - Shared::totalPlayTimeText.getLocalBounds().top);

		Shared::savePlayerNameText.setString(Shared::saveNameTwo);
		window.draw(Shared::savePlayerNameText);

		Shared::heartSprite.setPosition(Shared::savePlayerNameText.getPosition().x + (0.70f * Shared::saveIntSlotTwo.getSize().x) * 0.45f + 0.05f * Shared::saveIntSlotTwo.getSize().x, Shared::savePlayerNameText.getPosition().y);
		for (int i = 0; i < Shared::numberOfHeartsTwo; ++i) {
			window.draw(Shared::heartSprite);
			Shared::heartSprite.move(0.26f * Shared::saveIntSlotOne.getSize().y, 0.f);
		}
		Shared::heartSprite.setPosition(Shared::savePlayerNameText.getPosition().x + Shared::savePlayerNameText.getLocalBounds().width + 0.04f * Shared::saveIntSlotOne.getSize().x, Shared::savePlayerNameText.getPosition().y);

		window.draw(Shared::saveTimeText);
		Shared::saveTimePlayTimeBar.setPosition(Shared::savePlayerNameText.getPosition().x, Shared::savePlayerNameText.getPosition().y + Shared::savePlayerNameText.getLocalBounds().height + Shared::saveIntSlotTwo.getSize().y * 0.20f);
		window.draw(Shared::saveTimePlayTimeBar);

		Shared::lastSaveTimeTextTwo.setPosition(Shared::saveTimePlayTimeBar.getPosition().x + Shared::saveTimePlayTimeBar.getSize().x - Shared::lastSaveTimeTextTwo.getLocalBounds().width, Shared::saveTimeText.getPosition().y);
		window.draw(Shared::lastSaveTimeTextTwo);

		window.draw(Shared::totalPlayTimeText);
		Shared::saveTimePlayTimeBar.setPosition(Shared::savePlayerNameText.getPosition().x, Shared::saveTimeText.getPosition().y + Shared::saveTimeText.getLocalBounds().height + Shared::saveIntSlotTwo.getSize().y * 0.13f + 0.5f);
		window.draw(Shared::saveTimePlayTimeBar);

		Shared::playTimeTextTwo.setPosition(Shared::saveTimePlayTimeBar.getPosition().x + Shared::saveTimePlayTimeBar.getSize().x - Shared::playTimeTextTwo.getLocalBounds().width, Shared::totalPlayTimeText.getPosition().y);
		window.draw(Shared::playTimeTextTwo);

		Shared::savePlayerNameText.move(0, -Shared::betweenSaveOneAndTwo);
	}
	else {
		if (!Shared::typingSaveTwo)
			window.draw(Shared::nonCreatedSaveText);
		Shared::nonCreatedSaveText.move(0, -Shared::betweenSaveOneAndTwo);
		Shared::nonCreatedSaveText.move(0, Shared::betweenSaveOneAndThree);
	}

	// Slot 3

	window.draw(Shared::saveSlotThree);
	window.draw(Shared::saveIntSlotThree);
	window.draw(Shared::saveNumberRectThree);
	window.draw(Shared::saveRectThreeText);

	if (Shared::saveThreeExists) {

		Shared::savePlayerNameText.move(0.f, Shared::betweenSaveOneAndThree);
		Shared::saveTimeText.setPosition(Shared::savePlayerNameText.getPosition().x + (0.70f * Shared::saveIntSlotThree.getSize().x) * 0.45f - Shared::saveTimeText.getLocalBounds().width, 0.3f * Shared::saveIntSlotThree.getSize().y + Shared::savePlayerNameText.getPosition().y + Shared::savePlayerNameText.getLocalBounds().height - Shared::saveTimeText.getLocalBounds().top);
		Shared::totalPlayTimeText.setPosition(Shared::savePlayerNameText.getPosition().x + (0.70f * Shared::saveIntSlotThree.getSize().x) * 0.45f - Shared::totalPlayTimeText.getLocalBounds().width, Shared::saveNumberRectThree.getPosition().y + Shared::saveNumberRectThree.getSize().y - Shared::totalPlayTimeText.getLocalBounds().height - Shared::totalPlayTimeText.getLocalBounds().top);

		Shared::savePlayerNameText.setString(Shared::saveNameThree);
		window.draw(Shared::savePlayerNameText);

		Shared::heartSprite.setPosition(Shared::savePlayerNameText.getPosition().x + (0.70f * Shared::saveIntSlotThree.getSize().x) * 0.45f + 0.05f * Shared::saveIntSlotThree.getSize().x, Shared::savePlayerNameText.getPosition().y);
		for (int i = 0; i < Shared::numberOfHeartsThree; ++i) {
			window.draw(Shared::heartSprite);
			Shared::heartSprite.move(0.26f * Shared::saveIntSlotThree.getSize().y, 0.f);
		}

		window.draw(Shared::saveTimeText);
		Shared::saveTimePlayTimeBar.setPosition(Shared::savePlayerNameText.getPosition().x, Shared::savePlayerNameText.getPosition().y + Shared::savePlayerNameText.getLocalBounds().height + Shared::saveIntSlotThree.getSize().y * 0.20f - 0.5f);
		window.draw(Shared::saveTimePlayTimeBar);

		Shared::lastSaveTimeTextThree.setPosition(Shared::saveTimePlayTimeBar.getPosition().x + Shared::saveTimePlayTimeBar.getSize().x - Shared::lastSaveTimeTextThree.getLocalBounds().width, Shared::saveTimeText.getPosition().y);
		window.draw(Shared::lastSaveTimeTextThree);

		window.draw(Shared::totalPlayTimeText);
		Shared::saveTimePlayTimeBar.setPosition(Shared::savePlayerNameText.getPosition().x, Shared::saveTimeText.getPosition().y + Shared::saveTimeText.getLocalBounds().height + Shared::saveIntSlotThree.getSize().y * 0.13f);
		window.draw(Shared::saveTimePlayTimeBar);

		Shared::playTimeTextThree.setPosition(Shared::saveTimePlayTimeBar.getPosition().x + Shared::saveTimePlayTimeBar.getSize().x - Shared::playTimeTextThree.getLocalBounds().width, Shared::totalPlayTimeText.getPosition().y);
		window.draw(Shared::playTimeTextThree);

		Shared::savePlayerNameText.setString(Shared::saveNameOne);
		Shared::savePlayerNameText.move(0.f, -Shared::betweenSaveOneAndThree);
		Shared::saveTimeText.setPosition(Shared::savePlayerNameText.getPosition().x + (0.70f * Shared::saveIntSlotOne.getSize().x) * 0.45f - Shared::saveTimeText.getLocalBounds().width, 0.3f * Shared::saveIntSlotOne.getSize().y + Shared::savePlayerNameText.getPosition().y + Shared::savePlayerNameText.getLocalBounds().height - Shared::saveTimeText.getLocalBounds().top);
		Shared::heartSprite.setPosition(Shared::savePlayerNameText.getPosition().x + Shared::savePlayerNameText.getLocalBounds().width + 0.04f * Shared::saveIntSlotOne.getSize().x, Shared::savePlayerNameText.getPosition().y);
		Shared::totalPlayTimeText.setPosition(Shared::savePlayerNameText.getPosition().x + (0.70f * Shared::saveIntSlotOne.getSize().x) * 0.45f - Shared::totalPlayTimeText.getLocalBounds().width, Shared::saveNumberRectOne.getPosition().y + Shared::saveNumberRectOne.getSize().y - Shared::totalPlayTimeText.getLocalBounds().height - Shared::totalPlayTimeText.getLocalBounds().top);
	}
	else {
		Shared::nonCreatedSaveText.setPosition(window.getSize().x / 2.f - Shared::nonCreatedSaveText.getLocalBounds().width / 2.f + Shared::saveIntSlotThree.getSize().x * 0.10f, Shared::saveIntSlotThree.getPosition().y + Shared::saveIntSlotThree.getSize().y / 2.f - Shared::nonCreatedSaveText.getLocalBounds().height / 2.f - Shared::nonCreatedSaveText.getLocalBounds().top);
		if (!Shared::typingSaveThree)
			window.draw(Shared::nonCreatedSaveText);
		Shared::nonCreatedSaveText.setPosition(window.getSize().x / 2.f - Shared::nonCreatedSaveText.getLocalBounds().width / 2.f + Shared::saveIntSlotTwo.getSize().x * 0.10f, Shared::saveIntSlotTwo.getPosition().y + Shared::saveIntSlotTwo.getSize().y / 2.f - Shared::nonCreatedSaveText.getLocalBounds().height / 2.f - Shared::nonCreatedSaveText.getLocalBounds().top);
	}
}

void Assets::drawSettingsPage(sf::RenderWindow& window) {
	window.draw(Shared::savePageBackground);

	window.draw(Shared::settingsBox);

	window.draw(Shared::settingsFPSText);
	window.draw(Shared::settingsFPS60Text);

	window.draw(Shared::settingsVolumeText);
	window.draw(Shared::settingsVolumeSlider);
	window.draw(Shared::settingsPlusText);
	window.draw(Shared::settingsMinusText);

	window.draw(Shared::settingsLanguageText);
	window.draw(Shared::englishLanguageText);
}