#include "Game.hpp"
#include "AssetLoader.hpp"
#include "SharedVariables.h"
#include "Bokoblin.h"
#include "HearthContainer.hpp"
#include "SaveFileManager.h"
#include "Map.hpp"


sf::Vector2f pos = sf::Vector2f(200.0f,200.0f);

namespace {
	// Utilis� pour les variables souvent utilis�es dans ce fichier, pour �viter les copies
	sf::Vector2f mouseMovePosition;
	sf::Vector2f mouseButtonPosition;
}

float deltaTime = 1.0f;
sf::Clock cloc;

Game::Game() : 
	window(sf::VideoMode(sf::VideoMode::getFullscreenModes().at(0)), "The Legend Of Link", sf::Style::Fullscreen)
{
	spawnPos = {960,540};
	event = {};
	mapView = window.getDefaultView();
	spacingBetweenMapAndBorder = 1.0f / (window.getSize().x / ((window.getSize().x - window.getSize().y) / 2.0f));
	// Exemple : pour une dimension de 1920x1080 pixels
	// 1 / (1920 / ((1920 - 1080) / 2)) = 0.21875f ~ 21.875%
	mapView.setViewport(sf::FloatRect(spacingBetweenMapAndBorder, 0.0f, 1.0f - 2 * spacingBetweenMapAndBorder , 1.0f));
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
	map.loadFromFile("assets/tiles/map.txt");
	// Boolean members
	isHomePageOn = false;
	isRunning = true;
	isGameOver = false;
	// Scenes
	isHomePageOn = true;
	isSettingsSceneOn = false;
	isSaveSceneOn = false;
	isGameplayOn = false;
	lockClick = false;
	map.addVector();
	isRunning = true;
	inDonjon = false;
	changeMap = false;
}

Game::~Game() {

}

void Game::run() {

	time_t currentTime = std::time(nullptr);
	std::tm timeInfo;

	if (localtime_s(&timeInfo, &currentTime) != 0) {
		std::cerr << "Invalid time!" << '\n';; // Handle error
	}

	std::stringstream ss;
	ss << std::put_time(&timeInfo, "%d/%m/%Y %H:%M");
	std::string current = ss.str();
	//std::cout << "Current time : " << current << '\n';

	SaveFileManager saveFileOne("Saves/saveSlotOne.txt");
	SaveFileManager saveFileTwo("Saves/saveSlotTwo.txt");
	SaveFileManager saveFileThree("Saves/saveSlotThree.txt");
	
	Assets assets(window);

	map.addVector();

	player.init(Shared::playerSprite, spawnPos);
	
	updateThread = std::thread(&Game::updateGame, this,std::ref(event));
	while (window.isOpen() && isRunning) {
		
		pollEvents();
		draw(assets);
		
		
	}

	updateThread.join();
	std::cout << "Programme termine" << '\n';
	window.close();
}

void Game::pollEvents() {
	while (window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			isRunning = false;
			break;

		case sf::Event::KeyPressed:
			switch (event.key.code) {
			case sf::Keyboard::Escape:
				if (isGameplayOn) {
					isGameplayOn = false;
					isSettingsSceneOn = true;
				}
				else if (isSettingsSceneOn) {
					isSettingsSceneOn = false;
					isGameplayOn = true;
				}
				break;
			}
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
			if (isGameOver) {
				if (Shared::retryButton.getGlobalBounds().contains(mouseMovePosition))
					Shared::retryButton.setFillColor(sf::Color(200, 200, 200));
				else
					Shared::retryButton.setFillColor(sf::Color(155, 155, 155));
				if (Shared::homeButton.getGlobalBounds().contains(mouseMovePosition))
					Shared::homeButton.setFillColor(sf::Color(200, 200, 200));
				else
					Shared::homeButton.setFillColor(sf::Color(155, 155, 155));
			}
			if(isSaveSceneOn) {
				if (Shared::saveSlotOne.getGlobalBounds().contains(mouseMovePosition)) {
					Shared::saveIntSlotOne.setFillColor(sf::Color(255, 255, 255));
					Shared::saveNumberRectOne.setFillColor(sf::Color(255, 255, 255));
				}
				else {
					Shared::saveIntSlotOne.setFillColor(sf::Color(50, 50, 50));
					Shared::saveNumberRectOne.setFillColor(sf::Color(50, 50, 50));
					Shared::saveRectOneText.setFillColor(sf::Color(255, 255, 255));
				}
				if (Shared::saveSlotTwo.getGlobalBounds().contains(mouseMovePosition)) {
					Shared::saveIntSlotTwo.setFillColor(sf::Color(255, 255, 255));
					Shared::saveNumberRectTwo.setFillColor(sf::Color(255, 255, 255));
				}
				else {
					Shared::saveIntSlotTwo.setFillColor(sf::Color(50, 50, 50));
					Shared::saveNumberRectTwo.setFillColor(sf::Color(50, 50, 50));
				}
				if (Shared::saveSlotThree.getGlobalBounds().contains(mouseMovePosition)) {
					Shared::saveIntSlotThree.setFillColor(sf::Color(255, 255, 255));
					Shared::saveNumberRectThree.setFillColor(sf::Color(255, 255, 255));
				}
				else {
					Shared::saveIntSlotThree.setFillColor(sf::Color(50, 50, 50));
					Shared::saveNumberRectThree.setFillColor(sf::Color(50, 50, 50));
				}
			}
			break;

		case sf::Event::MouseButtonPressed:
			mouseButtonPosition = { (float)event.mouseButton.x, (float)event.mouseButton.y };
			if (event.mouseButton.button == sf::Mouse::Right)
			{
				lockClick = true;
			}
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
							isHomePageOn = false;
							isSettingsSceneOn = true;
						}
						else if (Shared::leaveButton.getGlobalBounds().contains(mouseButtonPosition)) {
							// Sauvegarder la progression et quitter le jeu
							isRunning = false;
						}
					}
					else if (isSaveSceneOn) {
						if (Shared::saveSlotOne.getGlobalBounds().contains(mouseButtonPosition)) {
							isSaveSceneOn = false;
							isGameplayOn = true;
						}
					}
					else if (isGameOver) {
						if (Shared::homeButton.getGlobalBounds().contains(mouseButtonPosition)) {
							// Retourne au menu principal
							isHomePageOn = true;
							isGameOver = false;
						}
						else if (Shared::retryButton.getGlobalBounds().contains(mouseButtonPosition)) {
							// recharge une save pour relancer le jeu
							isSaveSceneOn = true;
							isGameOver = false;
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
	
	if (isGameplayOn) {
		mapView.setCenter(player.getSprite().getPosition());
		window.setView(mapView);
		map.draw(window);

		player.draw(window);
		player.attaquer(window, map);

		for (int i = 0; i < map.spritesCailloux.size(); i++) {
			if (map.spritesCailloux[i].getScale().x == 0 && map.spritesCailloux[i].getScale().y == 0)
			{
				map.spritesCailloux.erase(map.spritesCailloux.begin() + i);
				break;
			}
		}

		for (auto& bok : Shared::enemies) {
			bok->draw(window);
		}
		
		deltaTime = cloc.restart().asSeconds();
		for (auto& door : map.doors)
		{
			if (door.getGlobalBounds().intersects(player.getSprite().getGlobalBounds()))
			{

				if (inDonjon)
				{
					inDonjon = false;
					newMapFile = "assets/tiles/map.txt";
				}
				else
				{
					inDonjon = true;
					newMapFile = "assets/tiles/map_donjon.txt";
				}
				changeMap = true;
				break;
			}
			
		}
		if (changeMap)
		{
			changeMap = false;
			map.clearVector();
			map.loadFromFile(newMapFile);
			map.addVector();
			player.setPositionPlayer({ 10.f, 10.f });
		}
		// Plus de trucs � venir avec les ennemis, joueur, objets etc...
	}
	else if (isHomePageOn) {
		window.setView(window.getDefaultView());
		assets.drawHomePage(window);
	}
	else if (isSettingsSceneOn) {
		window.setView(window.getDefaultView());
		assets.drawSettingsPage(window);
	}
	else if (isSaveSceneOn) {
		// La save scene est statique pour le moment
		window.setView(window.getDefaultView());
		assets.drawSavePage(window);
	}
	else if (isGameOver) {
		window.setView(window.getDefaultView());
		assets.drawGameOver(window);
	}

	window.display();
}

void Game::updateGame(sf::Event& event) {
	while (window.isOpen() && isRunning) {
		deltaTime = cloc.restart().asSeconds();
		player.tampon = window.mapPixelToCoords(sf::Mouse::getPosition(window));
		player.update(deltaTime, event, map);
		for (auto& bok : Shared::enemies) {
			if (std::abs(player.getSprite().getPosition().x - bok->getSprite().getPosition().x)  < 100 || std::abs(player.getSprite().getPosition().y - bok->getSprite().getPosition().y) < 100)
			{
				bok->followUpdate(deltaTime, player);
			}
			else {
				bok->update(deltaTime, event, map);
			}
		}
		// Vérification des collisions avec les ennemis
		/*for (auto& enemy : ennemies) {
			if (player.intersects(enemy) && !player.isCurrentlyInvincible()) {
				player.takeDamage(1);
			}
		}*/

		
		

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
			if (player.possedeFairy) { // sauve de la mort si t'as une fee
				player.heal(player.maxHealth);
				player.possedeFairy = false;
				//peut etre donner 1s d'invincibilité ?
			}
			isGameplayOn = false;
			isGameOver = true;
		}

		for (auto it = Shared::enemies.begin(); it != Shared::enemies.end(); ) {
			if ((*it)->shouldBeDeleted) {
				it = Shared::enemies.erase(it);
			} else {
				++it;
			}
		}
		
	}

	
}