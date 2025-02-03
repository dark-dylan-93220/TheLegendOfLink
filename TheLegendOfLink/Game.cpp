#include "Game.hpp"
#include "AssetLoader.hpp"
#include "SharedVariables.h"
#include "Bokoblin.h"
#include "HearthContainer.hpp"

namespace {
	// Utilis� pour les variables souvent utilis�es dans ce fichier, pour �viter les copies
	sf::Vector2f mouseMovePosition;
	sf::Vector2f mouseButtonPosition;
}

float deltaTime = 1.0f;
sf::Clock cloc;

Game::Game() : 
	window(sf::VideoMode(sf::VideoMode::getDesktopMode().height,sf::VideoMode::getDesktopMode().height), "The Legend Of Link", sf::Style::Fullscreen)
{
	spawnPos = {960,540};
	event = {};
	mapView = window.getDefaultView();
	spacingBetweenMapAndBorder = 1.0f / (window.getSize().x / ((window.getSize().x - window.getSize().y) / 2.0f));
	// Exemple : pour une dimension de 1920x1080 pixels
	// 1 / (1920 / ((1920 - 1080) / 2)) = 0.21875f ~ 21.875%
	mapView.setViewport(sf::FloatRect(spacingBetweenMapAndBorder, 0.0f, 1.0f - 2 * spacingBetweenMapAndBorder , 1.0f));
	window.setFramerateLimit(60);
	map.loadFromFile("assets/tiles/map.txt");
	// Boolean members
	isRunning = true;
	// Scenes
	isHomePageOn = true;
	isSaveSceneOn = false;
	isGameplayOn = false;
	lockClick = false;
	
}

Game::~Game() {

}

void Game::run() {
	
	Assets assets(window);
	player.init(Shared::playerSprite, spawnPos);
	Bokoblin bok;
	bok.init(Shared::playerSprite, spawnPos);
	ennemies.push_back(bok);
	
	while (window.isOpen() && isRunning) {

		pollEvents();
		draw(assets);

	}

	std::cout << "Programme termine" << '\n';
	window.close();
}

void Game::pollEvents() {
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
				if (!lockClick) { // Pour �viter la r�p�tition en boucle d'une action avec un seul clic
					lockClick = true;
					if (isHomePageOn) { // Condition non n�cessaire, ici pour la simplicit� de compr�hension du code
						if (Shared::playButton.getGlobalBounds().contains(mouseButtonPosition)) {
							isSaveSceneOn = true;
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
					else if (isSaveSceneOn) {
						isSaveSceneOn = false;
						isGameplayOn = true;
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
	mapView.setCenter(player.getSprite().getPosition());
	// Essayez d'�tre le plus court possible ici, juste des appels de fonctions
	if (isGameplayOn) {
		window.setView(mapView);
		map.draw(window);
		//window.draw(whiteBackground);
		player.update(deltaTime,event);
		player.draw(window);
		
		for (auto& bok : ennemies) {
			if ((std::abs(player.getSprite().getPosition().x - bok.getSprite().getPosition().x), std::abs(player.getSprite().getPosition().y - bok.getSprite().getPosition().y)) < (100, 100))
			{
				bok.followUpdate(deltaTime, player);
			}
			else
			{
				bok.update(deltaTime, event);
			}
			bok.draw(window);
		}
		
		deltaTime = cloc.restart().asSeconds();
		std::cout << deltaTime << '\n';
		// Plus de trucs � venir avec les ennemis, joueur, objets etc...
	}
	else if (isHomePageOn) {
		window.setView(window.getDefaultView());
		assets.drawHomePage(window);
	}
	else if (isSaveSceneOn) {
		// La save scene est statique pour le moment
		window.setView(window.getDefaultView());
		assets.drawSavePage(window);
	}

	window.display();
}

void Game::update() {
	// Vérification des collisions avec les ennemis
	for (auto& enemy : ennemies) {
		if (player.intersects(enemy) && !player.isCurrentlyInvincible()) {
			player.takeDamage(1);
		}
	}

	// Vérification des collisions avec les objets récupérables
	for (auto it = objects.begin(); it != objects.end(); ) {
		if (player.intersects(**it)) {
			HeartContainer* heart = dynamic_cast<HeartContainer*>(*it);
			if (heart) {
				player.heal(heart->getHealAmount());  // Soigne le joueur
				delete* it;  // Libère la mémoire
				it = objects.erase(it);  // Supprime l’objet de la liste
				continue;
			}
		}
		++it;
	}

	// Vérification du Game Over
	if (player.isDead()) {
		isGameplayOn = false;
		isGameOver = true;
	}
}