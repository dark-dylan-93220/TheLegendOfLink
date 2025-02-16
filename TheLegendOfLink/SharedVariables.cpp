#include "SharedVariables.h"
#include "Bokoblin.h"
#include "Boss.hpp"

/* Avantage des variables statiques :  
 - Elles ne sont initialis�es qu'une seule fois
 - Elles permettent d'�tre utilis�es par plusieurs fichiers .cpp sans avoir � cr�er de copies ni passer d'arguments 
 */

// HomePage
sf::Texture Shared::playerSwordTexture;
sf::Texture Shared::caillouxEnMietteTexture;
	 // Fonts
	sf::Font Shared::pixelNes;
	// Texts
	sf::Text Shared::playButtonText;
	sf::Text Shared::settingsButtonText;
	sf::Text Shared::leaveButtonText;
	// Textures & Sprites
	sf::Texture Shared::backgroundTexture;
	sf::Texture Shared::playerTexture;
	sf::Sprite Shared::playerSprite;
	sf::Texture Shared::bokoTexture;
	sf::Sprite Shared::bokoSprite;
	sf::Texture Shared::bossTexture;
	sf::Sprite Shared::bossSprite;
	sf::Texture Shared::projectileTexture;
	sf::Sprite Shared::projectileSprite;
	// RectangleShape
	sf::RectangleShape Shared::homePageBackground;
	sf::RectangleShape Shared::playButton;
	sf::RectangleShape Shared::settingsButton;
	sf::RectangleShape Shared::leaveButton;
	// Ennemies
	std::vector<std::unique_ptr<Bokoblin>> Shared::enemies;
	std::vector<std::unique_ptr<Boss>> Shared::bosses;
// SavePage
	// Utils
	float Shared::betweenSaveOneAndTwo;
	float Shared::betweenSaveOneAndThree;
	bool Shared::typingSaveOne;
	bool Shared::typingSaveTwo;
	bool Shared::typingSaveThree;
	// STD Data
	bool Shared::saveOneExists;
	bool Shared::saveTwoExists;
	bool Shared::saveThreeExists;
	// Nom du joueur
	std::string Shared::saveNameOne;
	std::string Shared::saveNameTwo;
	std::string Shared::saveNameThree;
	// Nombre de coeurs
	int Shared::numberOfHeartsOne;
	int Shared::numberOfHeartsTwo;
	int Shared::numberOfHeartsThree;
	// Nombre de rubis
	int Shared::numberOfRubisOne;
	int Shared::numberOfRubisTwo;
	int Shared::numberOfRubisThree;
	// Présence du bocal
	int Shared::hasBocalOne;
	int Shared::hasBocalTwo;
	int Shared::hasBocalThree;
	// Play time
	sf::Text Shared::playTimeTextOne;
	sf::Text Shared::playTimeTextTwo;
	sf::Text Shared::playTimeTextThree;

	std::string Shared::playTimeOne;
	std::string Shared::playTimeTwo;
	std::string Shared::playTimeThree;
	// Dernière position
	sf::Vector2f Shared::savedPosOne;
	sf::Vector2f Shared::savedPosTwo;
	sf::Vector2f Shared::savedPosThree;
	// Dernière save
	time_t Shared::lastSaveTimeOne;
	time_t Shared::lastSaveTimeTwo;
	time_t Shared::lastSaveTimeThree;

	std::string Shared::lastSaveTimeOneString;
	std::string Shared::lastSaveTimeTwoString;
	std::string Shared::lastSaveTimeThreeString;
	
	// Texts
	sf::Text Shared::nameCreationText;
	sf::Text Shared::saveTitleText;
	sf::Text Shared::nonCreatedSaveText;
	sf::Text Shared::savePlayerNameText;
	sf::Text Shared::confirmChoiceText;
	sf::Text Shared::cancelChoiceText;
	sf::Text Shared::saveTimeText;
	sf::Text Shared::totalPlayTimeText;
	sf::Text Shared::saveRectOneText;
	sf::Text Shared::saveRectTwoText;
	sf::Text Shared::saveRectThreeText;

	sf::Text Shared::lastSaveTimeTextOne;
	sf::Text Shared::lastSaveTimeTextTwo;
	sf::Text Shared::lastSaveTimeTextThree;

	// Textures & Sprites
	sf::Texture Shared::heartTexture;
	sf::Texture Shared::saveIntSlot;
	sf::Texture Shared::saveIntSlotCenter;
	sf::Texture Shared::saveBackground;
	sf::Texture Shared::saveTitle;
	sf::Texture Shared::saveSlotNumberOne;
	sf::Texture Shared::saveSlotNumberTwo;
	sf::Texture Shared::saveSlotNumberThree;

	// RectangleShape (commentaire -> &texture ou sf::Color associée)
	sf::RectangleShape Shared::heartSprite;              // -> &heartTexture
	sf::RectangleShape Shared::savePageBackground;       // -> &saveBackground
	sf::RectangleShape Shared::saveSlotOne;              // -> sf::Color(255,255,255,20);
	sf::RectangleShape Shared::saveSlotTwo;              // -> sf::Color(255,255,255,20);
	sf::RectangleShape Shared::saveSlotThree;            // -> sf::Color(255,255,255,20);
	sf::RectangleShape Shared::saveIntSlotOne;           // -> sf::Color(255,255,255,20);
	sf::RectangleShape Shared::saveIntSlotTwo;           // -> sf::Color(255,255,255,20);
	sf::RectangleShape Shared::saveIntSlotThree;         // -> sf::Color(255,255,255,20);
	sf::RectangleShape Shared::transparentSaveSlotLayer; // -> sf::Color(255,255,255,20);
	sf::RectangleShape Shared::savePageTitle;            // -> &saveTitle
	sf::RectangleShape Shared::saveNumberRectOne;        // -> sf::Color(beige vieux)
	sf::RectangleShape Shared::saveNumberRectTwo;        // -> sf::Color(beige vieux)
	sf::RectangleShape Shared::saveNumberRectThree;      // -> sf::Color(beige vieux)
	sf::RectangleShape Shared::saveTimePlayTimeBar;		 // -> sf::Color(150,100,0);
	sf::RectangleShape Shared::confirmChoiceRect;        // -> sf::Color::Black;
	sf::RectangleShape Shared::cancelChoiceRect;         // -> sf::Color::Black;

// SettingsScene
	sf::Text Shared::settingsLanguageText;
	sf::Text Shared::frenchLanguageText;
	sf::Text Shared::englishLanguageText;
	sf::Text Shared::settingsVolumeText;
	sf::Text Shared::settingsFPSText;
	sf::Text Shared::settingsFPS60Text;
	sf::Text Shared::settingsFPSVSyncText;
	sf::Text Shared::settingsPlusText;
	sf::Text Shared::settingsMinusText;

	// RectangleShape
	sf::RectangleShape Shared::settingsBox;
	sf::RectangleShape Shared::settingsVolumeSlider;
	sf::RectangleShape Shared::settingsSFXSlider;

	// Player
	std::vector<sf::Texture> Shared::playerTextures;
	std::vector<sf::Texture> Shared::playerTexturesBack;

// GameOverScreen
	// Fonts
	sf::Text Shared::homeButtonText;
	sf::Text Shared::retryButtonText;
	// Textures
	sf::Texture Shared::gameOverBackgroundTexture;
	// RectangleShape
	sf::RectangleShape Shared::gameOverBackground;
	sf::RectangleShape Shared::retryButton;
	sf::RectangleShape Shared::homeButton;