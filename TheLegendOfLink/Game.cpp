#include "Game.hpp"
#include "Player.h"
#include "AssetLoader.hpp"

Game::Game() : 
	window(sf::VideoMode::getFullscreenModes().at(0), "The Legend Of Link", sf::Style::Fullscreen)
{
	window.setFramerateLimit(60);
	window.setActive(true);
	map.loadFromFile("assets/tiles/map.txt");
}

Game::~Game() {

}

void Game::run() {
	//Assets assets(window);

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

		window.display();

	}
}