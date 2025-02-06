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
	// Save data
	saveTime = 0.f;
	totalPlayTime = 0.f;
	// Scenes
	isRunning = true;
	isHomePageOn = true;
	isGameOver = false;
	isSettingsSceneOn = false;
	isSaveSceneOn = false;
	isGameplayOn = false;
	lockClick = false;
	inDonjon = false;
	changeMap = false;
	selectedSave = "None";
}

Game::~Game() {

}

void Game::run() {
	SaveFileManager saveFileOne("Saves/saveSlotOne.txt");
	SaveFileManager saveFileTwo("Saves/saveSlotTwo.txt");
	SaveFileManager saveFileThree("Saves/saveSlotThree.txt");

	if (saveFileOne.exists)
		Shared::saveOneExists = true;
	if (saveFileTwo.exists)
		Shared::saveTwoExists = true;
	if (saveFileThree.exists)
		Shared::saveThreeExists = true;
	
	Assets assets(window);

	map.addVector();

	player.init(Shared::playerSprite, spawnPos);
	
	updateThread = std::thread(&Game::updateGame, this, std::ref(event));

	while (window.isOpen() && isRunning) {
		
		pollEvents();
		draw(assets);
		
		
	}

	updateThread.join();

	std::tm timeInfo;
	time_t currentTime = std::time(nullptr);

	if (localtime_s(&timeInfo, &currentTime) != 0) {
		std::cerr << "Invalid time!" << '\n';
	}

	std::stringstream st;
	st << std::put_time(&timeInfo, "%d/%m/%Y %H:%M");
	std::string current = st.str();

	if (selectedSave == "One")
		Shared::lastSaveTimeOne = currentTime;
	else if (selectedSave == "Two")
		Shared::lastSaveTimeTwo = currentTime;
	else if (selectedSave == "Three")
		Shared::lastSaveTimeThree = currentTime;

	std::cout << "Closing time : " << current << '\n';

	std::cout << totalPlayTime << std::endl;

	std::string minutes = std::to_string((int)(totalPlayTime / 60.f));
	std::string hours = std::to_string((int)(totalPlayTime / (60.f * 60.f)));

	if ((int)(totalPlayTime / 60.f) < 10) {
		minutes = "0" + std::to_string((int)(totalPlayTime / 60.f));
	}
	else if ((int)(totalPlayTime / 60.f) >= 60) {
		hours += std::to_string((int)(totalPlayTime / 60.f) / 60);
		std::string totalHours = std::to_string(stoi(hours) * 60);
		minutes = std::to_string((int)(totalPlayTime / 60.f) - stoi(totalHours));
		if (stoi(minutes) < 10) {
			minutes = "0" + std::to_string((int)(totalPlayTime / 60.f) - stoi(totalHours));
		}
	}

	std::cout << "Total play time : " << hours << ":" << minutes << '\n';

	if (selectedSave == "One") {
		Shared::playTimeOne = hours + ":" + minutes;
		saveFileOne.write(1);
	}
	else if (selectedSave == "Two") {
		Shared::playTimeTwo = hours + ":" + minutes;
		saveFileTwo.write(2);
	}
	else if (selectedSave == "Three") {
		Shared::playTimeThree = hours + ":" + minutes;
		saveFileThree.write(3);
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
		case sf::Event::TextEntered:
			if (isSaveSceneOn && nameChoosing) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
					if (nameChoice.size() == 0)
						nameChoice = "Link"; // Nom par défaut, sans choix
					if (selectedSave == "One") {
						Shared::saveNameOne = nameChoice;
						Shared::numberOfHeartsOne = 3;
						Shared::savedPosOne = { 0.f, 0.f };
						Shared::numberOfRubisOne = 0;
						Shared::hasBocalOne = -1;
						Shared::lastSaveTimeOne = std::time(nullptr);
						Shared::playTimeOne = "0:00";
						Shared::typingSaveOne = false;
					}
					else if (selectedSave == "Two") {
						Shared::saveNameTwo = nameChoice;
						Shared::numberOfHeartsTwo = 3;
						Shared::savedPosTwo = { 0.f, 0.f };
						Shared::numberOfRubisTwo = 0;
						Shared::hasBocalTwo = -1;
						Shared::lastSaveTimeTwo = std::time(nullptr);
						Shared::playTimeTwo = "0:00";
						Shared::typingSaveTwo = false;
					}
					else if (selectedSave == "Three") {
						Shared::saveNameThree = nameChoice;
						Shared::numberOfHeartsThree = 3;
						Shared::savedPosThree = { 0.f, 0.f };
						Shared::numberOfRubisThree = 0;
						Shared::hasBocalThree = -1;
						Shared::lastSaveTimeThree = std::time(nullptr);
						Shared::playTimeThree = "0:00";
						Shared::typingSaveThree = false;
					}
					nameChoosing = false;
					isSaveSceneOn = false;
					isGameplayOn = true;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace)) {
					if (nameChoice.length() > 0) {
						nameChoice.pop_back();
						Shared::nameCreationText.setString(nameChoice);
					}
				}
				else if (event.text.unicode < 128 && nameChoice.length() < 9) {
					nameChoice += static_cast<char>(event.text.unicode);
					Shared::nameCreationText.setString(nameChoice);
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
							if(selectedSave == "None")
								selectedSave = "One";
							if (Shared::saveOneExists) {
								isSaveSceneOn = false;
								isGameplayOn = true;
								char hour = Shared::playTimeOne[0];
								totalPlayTime += 3600 * (hour - '0');
								std::string minutes = Shared::playTimeOne.substr(2);
								totalPlayTime += 60 * stoi(minutes); // Arrondi à la minute, besoin de jouer une minute complète pour qu'elle soit comptée
							}
							else if (selectedSave == "One") {
								Shared::typingSaveOne = true;
								Shared::nameCreationText = Shared::savePlayerNameText;
								Shared::nameCreationText.setPosition(Shared::saveIntSlotOne.getPosition().x + Shared::saveIntSlotOne.getSize().x * 0.25f, Shared::saveIntSlotOne.getPosition().y + Shared::saveIntSlotOne.getSize().y * 0.10f - Shared::savePlayerNameText.getLocalBounds().top);
								nameChoice = "";
								Shared::nameCreationText.setString(nameChoice);
								nameChoosing = true;
							}
						}
						else if (Shared::saveSlotTwo.getGlobalBounds().contains(mouseButtonPosition)) {
							if (selectedSave == "None")
								selectedSave = "Two";
							if (Shared::saveTwoExists) {
								isSaveSceneOn = false;
								isGameplayOn = true;
								char hour = Shared::playTimeTwo[0];
								totalPlayTime += 3600 * (hour - '0');
								std::string minutes = Shared::playTimeTwo.substr(2);
								totalPlayTime += 60 * stoi(minutes); // Arrondi à la minute, besoin de jouer une minute complète pour qu'elle soit comptée
							}
							else if(selectedSave == "Two") {
								Shared::typingSaveTwo = true;
								Shared::nameCreationText = Shared::savePlayerNameText;
								Shared::nameCreationText.setPosition(Shared::saveIntSlotTwo.getPosition().x + Shared::saveIntSlotTwo.getSize().x * 0.25f, Shared::saveIntSlotTwo.getPosition().y + Shared::saveIntSlotOne.getSize().y * 0.10f - Shared::savePlayerNameText.getLocalBounds().top);
								nameChoice = "";
								Shared::nameCreationText.setString(nameChoice);
								nameChoosing = true;
							}
						}
						if (Shared::saveSlotThree.getGlobalBounds().contains(mouseButtonPosition)) {
							if (selectedSave == "None")
								selectedSave = "Three";
							if (Shared::saveThreeExists) {
								isSaveSceneOn = false;
								isGameplayOn = true;
								char hour = Shared::playTimeThree[0];
								totalPlayTime += 3600 * (hour - '0');
								std::string minutes = Shared::playTimeThree.substr(2);
								totalPlayTime += 60 * stoi(minutes); // Arrondi à la minute, besoin de jouer une minute complète pour qu'elle soit comptée
							}
							else if(selectedSave == "Three") {
								Shared::typingSaveThree = true;
								Shared::nameCreationText = Shared::savePlayerNameText;
								Shared::nameCreationText.setPosition(Shared::saveIntSlotThree.getPosition().x + Shared::saveIntSlotThree.getSize().x * 0.25f, Shared::saveIntSlotThree.getPosition().y + Shared::saveIntSlotOne.getSize().y * 0.10f - Shared::savePlayerNameText.getLocalBounds().top);
								nameChoice = "";
								Shared::nameCreationText.setString(nameChoice);
								nameChoosing = true;
							}
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
		for (auto& boss : Shared::bosses)
		{
			boss->draw(window);
		}

		player.draw(window);
		player.attaquer(window, map);

		deltaTime = cloc.restart().asSeconds();
		
	
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
		if (nameChoosing) {
			window.draw(Shared::nameCreationText);
		}
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

		if(isGameplayOn)
			totalPlayTime += deltaTime;

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
		for (auto& boss : Shared::bosses)
		{
			if (std::abs(player.getSprite().getPosition().x - boss->getSprite().getPosition().x) < 100 || std::abs(player.getSprite().getPosition().y - boss->getSprite().getPosition().y) < 100)
			{
				boss->followUpdate(deltaTime, player);
			}
		}
		// Vérification des collisions avec les ennemis
		/*for (auto& enemy : ennemies) {
			if (player.intersects(enemy) && !player.isCurrentlyInvincible()) {
				player.takeDamage(1);
			}
		}*/

		for (auto& door : map.doors)
		{
			if (door.getGlobalBounds().intersects(player.getSprite().getGlobalBounds()))
			{

				map.clearVector();
				map.loadFromFile("assets/tiles/map_donjon.txt");
				map.addVector();
				player.setPositionPlayer({ 960.f, 540.f });
				break;
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