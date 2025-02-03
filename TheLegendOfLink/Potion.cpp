#include "Potion.hpp"
#include "Objet.hpp"
#include "Player.h"

sf::Clock potion;

void Potion::init(sf::Sprite& sprite, sf::Vector2f& position) {
	spriteObjet = sprite;
	pos = position;
	spriteObjet.setPosition(pos);
}

void Potion::update(float& deltaTime, sf::Event& event) {
	if (recolte) {

	}
}

void Potion::draw(sf::RenderWindow& window) {
	window.draw(spriteObjet);
}

sf::Sprite Potion::getSprite()
{
	return spriteObjet;
}

Potion::~Potion(){}