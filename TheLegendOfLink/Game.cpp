#include "Game.hpp"
#include "Player.h"
#include "AssetLoader.hpp"
#include "SharedVariables.h"

namespace {
	// Utilisé pour les variables souvent utilisées dans ce fichier, pour éviter les copies
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
	
	Assets assets(window);

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
				if (Shared::playButton.getGlobalBounds().contains(mouseMovePosition))
					Shared::playButton.setFillColor(sf::Color(200,200,200));
				else
					Shared::playButton.setFillColor(sf::Color(155, 155, 155));
				if (Shared::settingsButton.getGlobalBounds().contains(mouseMovePosition))
					Shared::settingsButton.setFillColor(sf::Color(200, 200, 200));
				else
					Shared::settingsButton.setFillColor(sf::Color(155, 155, 155));
				if (Shared::leaveButton.getGlobalBounds().contains(mouseMovePosition))
					Shared::leaveButton.setFillColor(sf::Color(200, 200, 200));
				else
					Shared::leaveButton.setFillColor(sf::Color(155, 155, 155));
			}
			break;

		case sf::Event::MouseButtonPressed:
			mouseButtonPosition = { (float)event.mouseButton.x, (float)event.mouseButton.y };
			if (event.mouseButton.button == sf::Mouse::Left) {
				if (!lockClick) { // Pour éviter la répétition en boucle d'une action avec un seul clic
					lockClick = true;
					if (isHomePageOn) { // Condition non nécessaire, ici pour la simplicité de compréhension du code
						if (Shared::playButton.getGlobalBounds().contains(mouseButtonPosition)) {
							isGameplayOn = true;
							isHomePageOn = false;
						}
						else if (Shared::settingsButton.getGlobalBounds().contains(mouseButtonPosition)) {
							// Ouvrir le menu settings
						}
						else if (Shared::leaveButton.getGlobalBounds().contains(mouseButtonPosition)) {
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

	// Essayez d'être le plus court possible ici, juste des appels de fonctions
	if (isGameplayOn) {
		window.setView(mapView);
		map.draw(window);
		// Plus de trucs à venir avec les ennemis, joueur, objets etc...
	}
	else if (isHomePageOn) {
		window.setView(window.getDefaultView());
		assets.drawHomePage(window);
	}

	window.display();
}