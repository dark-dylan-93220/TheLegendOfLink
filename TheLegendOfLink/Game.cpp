#include "Game.hpp"
#include "Player.h"
Game::Game() {

}

Game::~Game() {

}

void Game::run() {
	sf::RenderWindow window(sf::VideoMode::getFullscreenModes().at(0), "The Legend Of Link", sf::Style::Fullscreen);
	sf::Event event;
	while (window.isOpen()) {

		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close(); std::cout << "Programme termine" << '\n';
				break;
			default:
				break;
			}
		}
	}
}