#include "Bokoblin.h"

Bokoblin::Bokoblin() {}

void Bokoblin::init(sf::Sprite& sprite, sf::Vector2f& position)
{
    spawnPos = position;
    spriteEntity = sprite;
    spriteEntity.setScale(0.2f, 0.2f);
    spriteEntity.setPosition(spawnPos);
}

void Bokoblin::update(float& deltaTime, sf::Event& event, Map& map)
{
    if (i >= 4) {
        i = 0;
        return;
    }

    
    if (std::abs(spriteEntity.getPosition().x - position[i].x) > 1.0f) {
        float dirX = (position[i].x > spriteEntity.getPosition().x) ? 1.0f : -1.0f;
        spriteEntity.move(dirX * speed * deltaTime, 0);
    }

    
    if (std::abs(spriteEntity.getPosition().y - position[i].y) > 1.0f) {
        float dirY = (position[i].y > spriteEntity.getPosition().y) ? 1.0f : -1.0f;
        spriteEntity.move(0, dirY * speed * deltaTime);
    }

    
    if (std::abs(spriteEntity.getPosition().x - position[i].x) <= 1.0f &&
        std::abs(spriteEntity.getPosition().y - position[i].y) <= 1.0f) {
        i++;
        if (i >= 4)
            {
            i = 0;
            }
        }
}

sf::Vector2f normalize(const sf::Vector2f& vector)
{
    float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);
    
    if (length == 0.0f)
        return sf::Vector2f(0.0f, 0.0f);
    return sf::Vector2f(vector.x / length, vector.y / length);
}

void Bokoblin::followUpdate(float& deltaTime, Player& player)
{
    sf::Vector2f direction = normalize(player.getSprite().getPosition() - spriteEntity.getPosition());
    
    sf::Vector2f initialPosition = spriteEntity.getPosition();
    
    spriteEntity.move(deltaTime * speed * normalize( player.getSprite().getPosition() - spriteEntity.getPosition()));
    
    /*for (auto& map : maps)
    {
        if (sprite.getGlobalBounds().intersects(map->sprite.getGlobalBounds()) && ! map->isFloor)
        {
            sprite.setPosition(initialPosition);
            break;
        }
    }*/
}

sf::Sprite Bokoblin::getSprite()
{
    return spriteEntity;
}
void Bokoblin::draw(sf::RenderWindow& window)
{
    window.draw(spriteEntity);
}