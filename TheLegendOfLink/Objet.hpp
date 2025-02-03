#pragma once
#include "SFML/Graphics.hpp"
#include "Entity.h"

template <typename T>
class Objet : public Entity {
protected:
	sf::Sprite spriteObjet;
	std::string nom;
	std::string description;
	sf::Vector2f position;
	T utilite;
public:
	Objet();
	virtual void init(sf::Sprite& sprite, sf::Vector2f& position) = 0;
	virtual void update(float& deltaTime, sf::Event& event) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
	sf::Sprite getSprite();
};

