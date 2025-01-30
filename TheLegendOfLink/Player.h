#pragma once
#include "Entity.h"
class Player : public Entity
{
private:
    sf::Vector2f spawnPos;
    sf::Sprite spritePlayer;
    float speed = 1;
    bool moving;
public:
    Player(sf::Sprite sprite, sf::Vector2f position);
    void init(sf::Sprite& sprite) override;
    void update(float& deltaTime,sf::Event& event) override;
    sf::Sprite getSprite();
    ~Player();
};
