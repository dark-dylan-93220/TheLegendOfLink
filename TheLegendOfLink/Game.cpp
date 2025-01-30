#include "Game.hpp"
#include "Player.h"
#include "AssetLoader.hpp"
#include "SharedVariables.h"

namespace {
	// Utilis� pour les variables souvent utilis�es dans ce fichier, pour �viter les copies
	sf::Vector2f mouseMovePosition;
	sf::Vector2f mouseButtonPosition;
}

Game::Game() : 
	window(sf::VideoMode::getDesktopMode(), "The Legend Of Link", sf::Style::Fullscreen)
{
	event = {};
	mapView = window.getDefaultView();
	float spacingBetweenMapAndBorder = 1.0f / (window.getSize().x / ((window.getSize().x - window.getSize().y) / 2.0f));
	// Exemple : pour une dimension de 1920x1080 pixels
	// 1 / (1920 / ((1920 - 1080) / 2)) = 0.21875f ~ 21.875%
	mapView.setViewport(sf::FloatRect(spacingBetweenMapAndBorder, 0.0f, 1.0f, 1.0f));
	window.setFramerateLimit(60);
	map.loadFromFile("assets/tiles/map.txt");
	// Boolean members
	isHomePageOn = true;
	isGameplayOn = false;
	lockClick = false;
	isRunning = true;
}

Game::~Game() {

}

void Game::run() {
	
	Assets assets(window, shared);

	while (window.isOpen() && isRunning) {

		pollEvents(assets);
		draw(assets);

	}

	std::cout << "Programme termine" << '\n';
	window.close();
}

void Game::pollEvents(Assets& assets) {
	while (window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			isRunning = false;
			break;

		case sf::Event::MouseMoved:
			mouseMovePosition = { (float)event.mouseMove.x, (float)event.mouseMove.y };
			if (isHomePageOn) {
				if (shared.playButton.getGlobalBounds().contains(mouseMovePosition))
					shared.playButton.setFillColor(sf::Color(200,200,200));
				else
					shared.playButton.setFillColor(sf::Color(155, 155, 155));
				if (shared.settingsButton.getGlobalBounds().contains(mouseMovePosition))
					shared.settingsButton.setFillColor(sf::Color(200, 200, 200));
				else
					shared.settingsButton.setFillColor(sf::Color(155, 155, 155));
				if (shared.leaveButton.getGlobalBounds().contains(mouseMovePosition))
					shared.leaveButton.setFillColor(sf::Color(200, 200, 200));
				else
					shared.leaveButton.setFillColor(sf::Color(155, 155, 155));
			}
			break;

		case sf::Event::MouseButtonPressed:
			mouseButtonPosition = { (float)event.mouseButton.x, (float)event.mouseButton.y };
			if (event.mouseButton.button == sf::Mouse::Left) {
				if (!lockClick) { // Pour �viter la r�p�tition en boucle d'une action avec un seul clic
					lockClick = true;
					if (isHomePageOn) { // Condition non n�cessaire, ici pour la simplicit� de compr�hension du code
						if (shared.playButton.getGlobalBounds().contains(mouseButtonPosition)) {
							isGameplayOn = true;
							isHomePageOn = false;
						}
						else if (shared.settingsButton.getGlobalBounds().contains(mouseButtonPosition)) {
							// Ouvrir le menu settings
						}
						else if (shared.leaveButton.getGlobalBounds().contains(mouseButtonPosition)) {
							// Sauvegarder la progression et quitter le jeu
							isRunning = false;
						}
					}
				}
			}
			break;

		case sf::Event::MouseButtonReleased:
			lockClick = false;
			break;

		default:
			break;
		}
	}
}

void Game::draw(Assets& assets) {
	window.clear(sf::Color::Black);

	// Essayez d'�tre le plus court possible ici, juste des appels de fonctions
	if (isGameplayOn) {
		window.setView(mapView);
		map.draw(window);
		// Plus de trucs � venir avec les ennemis, joueur, objets etc...
	}
	else if (isHomePageOn) {
		window.setView(window.getDefaultView());
		assets.drawHomePage(window, shared);
	}

	window.display();
}