#include "SharedVariables.h"

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
	// RectangleShape
	sf::RectangleShape Shared::homePageBackground;
	sf::RectangleShape Shared::playButton;
	sf::RectangleShape Shared::settingsButton;
	sf::RectangleShape Shared::leaveButton;

// SavePage
	sf::Text Shared::saveTitleText;
	sf::Text Shared::nonCreatedSaveText;
	sf::Text Shared::savePlayerNameText;
	sf::Text Shared::confirmChoiceText;
	sf::Text Shared::cancelChoiceText;
	sf::Text Shared::saveTimeText;
	sf::Text Shared::totalPlayTimeText;

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

// Player
	std::vector<sf::Texture> Shared::playerTextures;
	std::vector<sf::Texture> Shared::playerTexturesBack;