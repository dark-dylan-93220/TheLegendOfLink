#include "Game.hpp"
#include "Player.h"
#include "AssetLoader.hpp"
#include "Bokoblin.h"
float deltaTime = 1.0f;
sf::Clock cloc;



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
	Assets assets(window);
	Player player(playerSprite, sf::Vector2f(0, 0));
	Bokoblin bok(playerSprite, sf::Vector2f(100, 100));
	sf::Event event;
	while (window.isOpen()) {
		cloc.restart();
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
		player.update(deltaTime,event);
		player.draw(window);
		player.getSprite().getPosition();
		if ((abs(player.getSprite().getPosition().x - bok.getSprite().getPosition().x) , abs(player.getSprite().getPosition().y - bok.getSprite().getPosition().y))< (100,100))
		{
			bok.followUpdate(deltaTime, player);
		}
		else
		{
			bok.update(deltaTime,event);
		}
		
		bok.draw(window);
		window.display();
		deltaTime = cloc.getElapsedTime().asSeconds();
	}
}