#pragma once
#include "Entity.h"
class Eprojectiles : public Entity
{
private:
    sf::Vector2f targetPosition;
    sf::Vector2f selfPos;
public:
    float lifetime;
public:
    Eprojectiles(sf::Vector2f playerPos);
    void init(sf::Sprite& sprite, sf::Vector2f& position) override;
    void update(float& deltaTime, sf::Event& event, Map& map) override;
    void draw(sf::RenderWindow& window) override;
    ~Eprojectiles();
};
