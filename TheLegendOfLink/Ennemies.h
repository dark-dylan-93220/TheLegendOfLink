#pragma once
#include "Entity.h"

class Player;

class Ennemies : public Entity
{
public:
    Ennemies();
    virtual void init(sf::Sprite& sprite, sf::Vector2f& position);
    virtual void update(float& deltaTime,sf::Event& event, Map& map);
    virtual void draw(sf::RenderWindow& window);
    virtual sf::Sprite getSprite();
    virtual void followUpdate(float& deltaTime,Player& player);
};
