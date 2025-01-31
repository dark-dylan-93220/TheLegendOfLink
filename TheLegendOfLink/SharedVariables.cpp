#include "SharedVariables.h"

/* Avantage des variables statiques :  
 - Elles ne sont initialisées qu'une seule fois
 - Elles permettent d'être utilisées par plusieurs fichiers .cpp sans avoir à créer de copies ni passer d'arguments 
 */

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