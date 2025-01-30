#pragma once
#include "Ennemies.h"

class Bokoblin : public Ennemies
{
public:
    void init(sf::Sprite& sprite) override;
    void update(float& deltaTime, sf::Event& event) override;
    void draw(sf::RenderWindow& window) override;
};
