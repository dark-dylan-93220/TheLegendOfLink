#pragma once

#include "Ennemies.h"
#include "Player.h"

class Boss : public Ennemies
{
private:
    float speed = 150;
    int i = 0;
    sf::Vector2f spawnPos;
    sf::Vector2f positionP[4];
public:
    Boss();
    void init(sf::Sprite& sprite, sf::Vector2f& position) override;
    void update(float& deltaTime, sf::Event& event, Map& map) override;
    void followUpdate(float& deltaTime, Player& player) override;
    sf::Sprite getSprite() override;
    void draw(sf::RenderWindow& window) override;
};
