#include "Game.hpp"
#include "Player.h"
#include "AssetLoader.hpp"

Game::Game() : 
	window(sf::VideoMode::getFullscreenModes().at(0), "The Legend Of Link", sf::Style::Fullscreen)
{
	window.setFramerateLimit(60);
	window.setActive(true);
}

Game::~Game() {

}

void Game::run() {
	Assets assets(window);

	sf::Event event;
	while (window.isOpen()) {

		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close(); 
				std::cout << "Programme termine" << '\n';
				break;
			default:
				break;
			}
		}

		window.clear(sf::Color::Black);

		window.draw(whiteBackground);
		window.draw(playerSprite);

		window.draw(playButton);
		window.draw(settingsButton);
		window.draw(leaveButton);

		window.draw(playButtonText);
		window.draw(settingsButtonText);
		window.draw(leaveButtonText);

		window.display();

	}
}