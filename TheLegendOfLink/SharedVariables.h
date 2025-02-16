#pragma once

#include "SFML/Graphics.hpp"
#include <ctime>
#include <optional>

class Bokoblin;
class Boss;

class Shared {
//
public:
	static sf::Texture playerSwordTexture, caillouxEnMietteTexture;

// HomePage
public:
	// Fonts
	static sf::Font pixelNes;
	// Texts
	static sf::Text playButtonText;
	static sf::Text settingsButtonText;
	static sf::Text leaveButtonText;
	static sf::Text homeButtonText;
	static sf::Text retryButtonText;
	// Textures & Sprites
	static sf::Texture backgroundTexture;
	static sf::Texture playerTexture;
	static sf::Texture bokoTexture;
	static sf::Sprite bokoSprite;
	static sf::Texture bossTexture;
	static sf::Sprite bossSprite;
	static std::vector<sf::Texture> playerTextures;
	static std::vector<sf::Texture> playerTexturesBack;
	static sf::Sprite playerSprite;
	static sf::Texture gameOverBackgroundTexture;
	static sf::Texture projectileTexture;
	static sf::Sprite projectileSprite;
	// RectangleShape
	static sf::RectangleShape homePageBackground;
	static sf::RectangleShape playButton;
	static sf::RectangleShape settingsButton;
	static sf::RectangleShape leaveButton; // Déclenchera la sauvegarde
	static sf::RectangleShape gameOverBackground;
	static sf::RectangleShape retryButton;
	static sf::RectangleShape homeButton;
	//Ennemies
	static std::vector<std::unique_ptr<Bokoblin>> enemies;
	static std::vector<std::unique_ptr<Boss>> bosses;

// SaveScene / inspiration : https://maplequeensaku.weebly.com/uploads/9/5/7/9/95792838/twilight-princess-rel-loader-save-screen-no-file_orig.png
public:
	// Utils
	static float betweenSaveOneAndTwo;
	static float betweenSaveOneAndThree;
	static bool typingSaveOne;
	static bool typingSaveTwo;
	static bool typingSaveThree;
	// STD Data
	static bool saveOneExists;
	static bool saveTwoExists;
	static bool saveThreeExists;
	// Nombre de coeurs
	static int numberOfHeartsOne;
	static int numberOfHeartsTwo;
	static int numberOfHeartsThree;
	// Play time
	static std::string playTimeOne;
	static std::string playTimeTwo;
	static std::string playTimeThree;
	static sf::Text playTimeTextOne;
	static sf::Text playTimeTextTwo;
	static sf::Text playTimeTextThree;
	// Nombre de rubis
	static int numberOfRubisOne;
	static int numberOfRubisTwo;
	static int numberOfRubisThree;
	// Dernière position
	static sf::Vector2f savedPosOne;
	static sf::Vector2f savedPosTwo;
	static sf::Vector2f savedPosThree;
	// Nom du joueur
	static std::string saveNameOne;
	static std::string saveNameTwo;
	static std::string saveNameThree;
	// Dernière save
	static time_t lastSaveTimeOne;
	static time_t lastSaveTimeTwo;
	static time_t lastSaveTimeThree;
	static std::string lastSaveTimeOneString;
	static std::string lastSaveTimeTwoString;
	static std::string lastSaveTimeThreeString;
	static sf::Text lastSaveTimeTextOne;
	static sf::Text lastSaveTimeTextTwo;
	static sf::Text lastSaveTimeTextThree;
	// Présence du bocal
	static int hasBocalOne;
	static int hasBocalTwo;
	static int hasBocalThree;

	// Texts
	static sf::Text nameCreationText;
	static sf::Text saveTitleText;
	static sf::Text nonCreatedSaveText;
	static sf::Text savePlayerNameText;
	static sf::Text confirmChoiceText;
	static sf::Text cancelChoiceText;
	static sf::Text saveTimeText;
	static sf::Text totalPlayTimeText;
	static sf::Text saveRectOneText;
	static sf::Text saveRectTwoText;
	static sf::Text saveRectThreeText;

	// Textures & Sprites
	static sf::Texture heartTexture;
	static sf::Texture saveBackground;
	static sf::Texture saveIntSlot;
	static sf::Texture saveIntSlotCenter;
	static sf::Texture saveTitle;
	static sf::Texture saveSlotNumberOne;
	static sf::Texture saveSlotNumberTwo;
	static sf::Texture saveSlotNumberThree;

	// RectangleShape (commentaire -> &texture ou sf::Color associ�e)
	static sf::RectangleShape heartSprite;              // -> &heartTexture
	static sf::RectangleShape savePageBackground;       // -> &saveBackground
	static sf::RectangleShape saveSlotOne;              // -> sf::Color(255,255,255,20);
	static sf::RectangleShape saveSlotTwo;              // -> sf::Color(255,255,255,20);
	static sf::RectangleShape saveSlotThree;            // -> sf::Color(255,255,255,20);
	static sf::RectangleShape saveIntSlotOne;           // -> &saveIntSlot
	static sf::RectangleShape saveIntSlotTwo;           // -> &saveIntSlotCenter
	static sf::RectangleShape saveIntSlotThree;         // -> &saveIntSlot
	static sf::RectangleShape transparentSaveSlotLayer; // -> sf::Color(255,255,255,20);
	static sf::RectangleShape savePageTitle;            // -> &saveTitle
	static sf::RectangleShape saveNumberRectOne;        // -> &saveSlotNumberOne
	static sf::RectangleShape saveNumberRectTwo;        // -> &saveSlotNumberTwo
	static sf::RectangleShape saveNumberRectThree;      // -> &saveSlotNumberThree
	static sf::RectangleShape saveTimePlayTimeBar;      // -> sf::Color(150,100,0);
	static sf::RectangleShape confirmChoiceRect;        // -> sf::Color::Black;
	static sf::RectangleShape cancelChoiceRect;         // -> sf::Color::Black;

// SettingsScene
public:
	// Texts
	static sf::Text settingsLanguageText;
	static sf::Text frenchLanguageText;
	static sf::Text englishLanguageText;
	static sf::Text settingsVolumeText;
	static sf::Text settingsFPSText;
	static sf::Text settingsFPS60Text;
	static sf::Text settingsFPSVSyncText;
	static sf::Text settingsPlusText;
	static sf::Text settingsMinusText;

	// RectangleShape
	static sf::RectangleShape settingsBox;
	static sf::RectangleShape settingsVolumeSlider;
	static sf::RectangleShape settingsSFXSlider;
};
