﻿#pragma once

#include "Ennemies.h"
#include "Player.h"

class Bokoblin : public Ennemies
{
private:
    float speed = 100;
    int i = 0;
    sf::Vector2f spawnPos;
    sf::Vector2f positionP[4];
public:
    Bokoblin();
    void init(sf::Sprite& sprite, sf::Vector2f& position) override;
    void update(float& deltaTime, sf::Event& event, Map& map) override;
    void followUpdate(float& deltaTime,Player& player) override;
    sf::Sprite getSprite() override;
    void draw(sf::RenderWindow& window) override;
};
