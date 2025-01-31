#pragma once
#include "Ennemies.h"
#include "Player.h"

class Bokoblin : public Ennemies
{
private:
    float speed = 100;
    int i = 0;
    sf::Vector2f spawnPos;
    sf::Vector2f position[4] = {{spawnPos.x,spawnPos.y},{spawnPos.x + 200,spawnPos.y},{spawnPos.x + 200,spawnPos.y + 200},{spawnPos.x,spawnPos.y + 200}};    
public:
    Bokoblin(sf::Sprite sprite, sf::Vector2f position);
    void init(sf::Sprite& sprite) override;
    void update(float& deltaTime, sf::Event& event) override;
    void followUpdate(float& deltaTime,Player player);
    sf::Sprite getSprite();
    void draw(sf::RenderWindow& window) override;
};
