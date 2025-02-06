#include "Boss.hpp"

Boss::Boss() {}

void Boss::init(sf::Sprite& sprite, sf::Vector2f& position)
{
    spawnPos = position;
    spriteEntity = sprite;
    positionP[0] = { spawnPos.x,spawnPos.y };
    positionP[1] = { spawnPos.x + 200,spawnPos.y };
    positionP[2] = { spawnPos.x + 200,spawnPos.y + 200 };
    positionP[3] = { spawnPos.x,spawnPos.y + 200 };
    spriteEntity.setScale(2.f * (16.f / 9.f), 2.f);
    spriteEntity.setOrigin(spriteEntity.getLocalBounds().width / 2, spriteEntity.getLocalBounds().height / 2);
    spriteEntity.setPosition(spawnPos);
}

void Boss::update(float& deltaTime, sf::Event& event, Map& map)
{
    if (i >= 4) {
        i = 0;
        return;
    }


    if (std::abs(spriteEntity.getPosition().x - positionP[i].x) > 1.0f) {
        float dirX = (positionP[i].x > spriteEntity.getPosition().x) ? 1.0f : -1.0f;
        spriteEntity.move(dirX * (16.f / 9.f) * speed * deltaTime, 0);
    }


    if (std::abs(spriteEntity.getPosition().y - positionP[i].y) > 1.0f) {
        float dirY = (positionP[i].y > spriteEntity.getPosition().y) ? 1.0f : -1.0f;
        spriteEntity.move(0, dirY * speed * deltaTime);
    }


    if (std::abs(spriteEntity.getPosition().x - positionP[i].x) <= 1.0f &&
        std::abs(spriteEntity.getPosition().y - positionP[i].y) <= 1.0f) {
        i++;
        if (i >= 4)
        {
            i = 0;
        }
    }
}

sf::Vector2f normalizeBoss(const sf::Vector2f& vector)
{
    float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);

    if (length == 0.0f)
        return sf::Vector2f(0.0f, 0.0f);
    return sf::Vector2f(vector.x / length, vector.y / length);
}

void Boss::followUpdate(float& deltaTime, Player& player)
{
    sf::Vector2f direction = normalizeBoss(player.getSprite().getPosition() - spriteEntity.getPosition());

    sf::Vector2f initialPosition = spriteEntity.getPosition();

    spriteEntity.move(deltaTime * speed * normalizeBoss(player.getSprite().getPosition() - spriteEntity.getPosition()));

    /*for (auto& map : maps)
    {
        if (sprite.getGlobalBounds().intersects(map->sprite.getGlobalBounds()) && ! map->isFloor)
        {
            sprite.setPosition(initialPosition);
            break;
        }
    }*/
}

sf::Sprite Boss::getSprite()
{
    return spriteEntity;
}
void Boss::draw(sf::RenderWindow& window)
{
    window.draw(spriteEntity);
}