#include "SharedVariables.h"

/* Avantage des variables statiques :  
 - Elles ne sont initialis�es qu'une seule fois
 - Elles permettent d'�tre utilis�es par plusieurs fichiers .cpp sans avoir � cr�er de copies ni passer d'arguments 
 */

 // Fonts
sf::Font Shared::pixelNes;
// Texts
sf::Text Shared::playButtonText;
sf::Text Shared::settingsButtonText;
sf::Text Shared::leaveButtonText;
sf::Text Shared::homeButtonText;
sf::Text Shared::retryButtonText;
// Textures & Sprites
sf::Texture Shared::backgroundTexture;
sf::Texture Shared::playerTexture;
std::vector<sf::Texture> Shared::playerTextures;
std::vector<sf::Texture> Shared::playerTexturesBack;
sf::Sprite Shared::playerSprite;
sf::Texture Shared::gameOverBackgroundTexture;
// RectangleShape
sf::RectangleShape Shared::homePageBackground;
sf::RectangleShape Shared::playButton;
sf::RectangleShape Shared::settingsButton;
sf::RectangleShape Shared::leaveButton;
sf::RectangleShape Shared::gameOverBackground;
sf::RectangleShape Shared::retryButton;
sf::RectangleShape Shared::homeButton;