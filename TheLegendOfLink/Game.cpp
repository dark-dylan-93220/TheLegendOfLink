#include "Game.hpp"
#include "Player.h"
#include "AssetLoader.hpp"

Game::Game() : 
	window(sf::VideoMode::getDesktopMode(), "The Legend Of Link", sf::Style::Fullscreen)
{
	sf::View view = window.getDefaultView();
	view.setViewport(sf::FloatRect(0.20f, 0.0f, 0.5625f, 1.0f));
	window.setView(view);
	window.setFramerateLimit(60);
	window.setActive(true);
	map.loadFromFile("assets/tiles/map.txt");
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

		//window.draw(whiteBackground);
		//window.draw(playerSprite);
		map.draw(window);

		window.draw(playButton);
		window.draw(settingsButton);
		window.draw(leaveButton);

		window.draw(playButtonText);
		window.draw(settingsButtonText);
		window.draw(leaveButtonText);

		window.display();

	}
}