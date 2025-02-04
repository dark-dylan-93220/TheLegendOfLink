#pragma once
#include "Objet.hpp"

class Potion : public Objet<int>
{
private:
	int vie;
	sf::Vector2f pos;
	bool recolte = false;
public:
	Potion() : vie(2){}
	void init(sf::Sprite& sprite, sf::Vector2f& position ) override;
	void update(float& deltaTime, sf::Event& event) override;
	void draw(sf::RenderWindow& window) override;
	sf::Sprite getSprite();
	~Potion();
};
