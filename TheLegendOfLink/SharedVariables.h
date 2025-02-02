#pragma once

#include "SFML/Graphics.hpp"


class Shared {
// HomePage
public:
	// Fonts
	static sf::Font pixelNes;
	// Texts
	static sf::Text playButtonText;
	static sf::Text settingsButtonText;
	static sf::Text leaveButtonText;
	// Textures & Sprites
	static sf::Texture backgroundTexture;
	static sf::Texture playerTexture;
	static sf::Sprite playerSprite;
	// RectangleShape
	static sf::RectangleShape homePageBackground;
	static sf::RectangleShape playButton;
	static sf::RectangleShape settingsButton;
	static sf::RectangleShape leaveButton; // Déclenchera la sauvegarde

// SaveScene / inspiration : https://maplequeensaku.weebly.com/uploads/9/5/7/9/95792838/twilight-princess-rel-loader-save-screen-no-file_orig.png
public:
	// STD Data
	//static int numberOfHearts;
	//static float playTime;
	// Un autre pour le moment de la dernière sauvegarde

	// Texts
	static sf::Text saveTitleText;
	static sf::Text nonCreatedSaveText;
	static sf::Text savePlayerNameText;
	static sf::Text confirmChoiceText;
	static sf::Text cancelChoiceText;
	static sf::Text saveTimeText;
	static sf::Text totalPlayTimeText;

	// Textures & Sprites
	static sf::Texture heartTexture;
	static sf::Texture saveBackground;
	static sf::Texture saveIntSlot;
	static sf::Texture saveIntSlotCenter;
	static sf::Texture saveTitle;
	static sf::Texture saveSlotNumberOne;
	static sf::Texture saveSlotNumberTwo;
	static sf::Texture saveSlotNumberThree;

	// RectangleShape (commentaire -> &texture ou sf::Color associée)
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
};