#pragma once
#include "Entity.h"
class Player : public Entity
{
private:
    sf::Vector2f spawnPos;
    sf::Sprite spritePlayer;
    unsigned int speed;
    bool moving;
public:
    Player(sf::Sprite sprite, sf::Vector2f position);
    void init(sf::Sprite& sprite) override;
    void update(float& deltaTime,sf::Event& event) override;
    ~Player();
};
