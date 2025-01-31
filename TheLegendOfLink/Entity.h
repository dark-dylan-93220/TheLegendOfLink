#pragma once
#include "Game.hpp"
class Entity
{
protected:
    sf::Sprite spriteEntity;
    float speed;
public:
    virtual void init(sf::Sprite& sprite) = 0;
    virtual void update(float& deltaTime,sf::Event& event) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
};

