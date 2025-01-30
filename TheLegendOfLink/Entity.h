#pragma once
#include "Game.hpp"
class Entity
{
public:
    virtual void init(sf::Sprite& sprite) = 0;
    virtual void update(float& deltaTime,sf::Event& event) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
};

