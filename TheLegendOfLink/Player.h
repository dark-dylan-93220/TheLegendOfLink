#pragma once

#include "Entity.h"
#include <iostream>

class Player : public Entity
{
private:
    sf::Vector2f spawnPos;
    sf::RectangleShape hitBox;
    float speed = 200;
    int frame = 0;
    bool moving = false;
    bool isAttacking = false;
    bool back = false;
public:
    Player();
    void init(sf::Sprite& sprite, sf::Vector2f& position) override;
    void update(float& deltaTime,sf::Event& event, Map& map) override;
    void draw(sf::RenderWindow& window) override;
    sf::Sprite getSprite();
    ~Player();
};
