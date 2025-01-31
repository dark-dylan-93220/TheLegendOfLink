#pragma once
#include "SFML/Graphics.hpp"
class Entity
{
protected:
    sf::Sprite spriteEntity;
    float speed;
public:
    virtual void init(sf::Sprite& sprite, sf::Vector2f& position) = 0;
    virtual void update(float& deltaTime,sf::Event& event) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
};

