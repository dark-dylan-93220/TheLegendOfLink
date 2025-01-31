#include "SharedVariables.h"

/* Avantage des variables statiques :  
 - Elles ne sont initialisées qu'une seule fois
 - Elles permettent d'être utilisées par plusieurs fichiers .cpp sans avoir à créer de copies ni passer d'arguments 
 */

// HomePage
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
	sf::Sprite Shared::heartSprite;
	sf::Texture Shared::saveBackground;
	sf::Texture Shared::saveTitle;

	// RectangleShape (commentaire -> &texture ou sf::Color associée)
	sf::RectangleShape Shared::savePageBackground;       // -> &saveBackground
	sf::RectangleShape Shared::saveSlot;                 // -> sf::Color(255,255,255,20);
	sf::RectangleShape Shared::saveIntSlot;              // -> sf::Color(255,255,255,20);
	sf::RectangleShape Shared::transparentSaveSlotLayer; // -> sf::Color(255,255,255,20);
	sf::RectangleShape Shared::savePageTitle;            // -> &saveTitle
	sf::RectangleShape Shared::saveNumberRect;           // -> sf::Color(beige vieux)
	sf::RectangleShape Shared::confirmChoiceRect;        // -> sf::Color::Black;
	sf::RectangleShape Shared::cancelChoiceRect;         // -> sf::Color::Black;
