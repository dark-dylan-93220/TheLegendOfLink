#pragma once
#include "Game.hpp"
class Entity
{
public:
    virtual void init(sf::Sprite& path) = 0;
    virtual void update(float& deltaTime) = 0;
};
