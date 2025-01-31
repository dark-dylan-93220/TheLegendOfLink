#pragma once

#include "Entity.h"

class Player : public Entity
{
private:
    sf::Vector2f spawnPos;
    sf::RectangleShape hitBox;
    float speed = 200;
    bool moving;
    bool isAttacking;
public:
    Player();
    void init(sf::Sprite& sprite, sf::Vector2f& position) override;
    void update(float& deltaTime,sf::Event& event) override;
    void draw(sf::RenderWindow& window) override;
    sf::Sprite getSprite();
    ~Player();
};
