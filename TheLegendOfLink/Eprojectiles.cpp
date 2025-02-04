#include "Eprojectiles.h"



Eprojectiles::Eprojectiles(sf::Vector2f playerPos) {targetPosition = playerPos;}

void Eprojectiles::init(sf::Sprite& sprite, sf::Vector2f& position)
{
    spriteEntity = sprite;
    spriteEntity.setPosition(position);
    spriteEntity.setScale((16.0f/9.0f), 1);
    selfPos = position;
}

sf::Vector2f normalizeVector(const sf::Vector2f& vector)
{
    float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);
    
    if (length == 0.0f)
        return sf::Vector2f(0.0f, 0.0f);
    return sf::Vector2f(vector.x / length * (16.0f/9.0f), vector.y / length);
}

void Eprojectiles::update(float& deltaTime, sf::Event& event, Map& map)
{
    lifetime += deltaTime;
    if (!isColliding)
        spriteEntity.move(normalizeVector(targetPosition - selfPos)* 300.0f * deltaTime);
}

void Eprojectiles::draw(sf::RenderWindow& window)
{
    window.draw(spriteEntity);
}

sf::Sprite Eprojectiles::getSprite()
{
    return spriteEntity;
}

Eprojectiles::~Eprojectiles() {}
