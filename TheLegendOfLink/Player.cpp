#include "Player.h"
#include "SharedVariables.h"

Player::Player() {}

sf::Clock clo;

void Player::init(sf::Sprite& sprite, sf::Vector2f& position)
{
    spawnPos = position;
    spriteEntity = sprite;
    spriteEntity.setScale(0.4f, 0.2f);
    spriteEntity.setPosition(spawnPos);
}

void Player::update(float& deltaTime, sf::Event& event, Map& map)
{
    hitBox.setPosition(spriteEntity.getPosition());
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    {
        isAttacking = true;
    }
    std::cout << "collide\n";
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        spriteEntity.move(speed * deltaTime, 0);
        moving = true;
        for (int i = 0; i < map.spritesWall.size(); i++) {
            if (map.spritesWall[i].getGlobalBounds().intersects(spriteEntity.getGlobalBounds())) {
                spriteEntity.move(-speed * deltaTime, 0);
                moving = false;
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        spriteEntity.move(-speed * deltaTime, 0);
        moving = true;
        for (int i = 0; i < map.spritesWall.size(); i++) {
            if (map.spritesWall[i].getGlobalBounds().intersects(spriteEntity.getGlobalBounds())) {
                spriteEntity.move(speed * deltaTime, 0);
                moving = false;
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        spriteEntity.move(0, -speed * deltaTime);
        moving = true;
        for (int i = 0; i < map.spritesWall.size(); i++) {
            if (map.spritesWall[i].getGlobalBounds().intersects(spriteEntity.getGlobalBounds())) {
                spriteEntity.move(0, speed * deltaTime);
                moving = false;
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        spriteEntity.move(0, speed * deltaTime);
        moving = true;
        for (int i = 0; i < map.spritesWall.size(); i++) {
            if (map.spritesWall[i].getGlobalBounds().intersects(spriteEntity.getGlobalBounds())) {
                spriteEntity.move(0, -speed * deltaTime);
                moving = false;
            }
        }
    }
    moving = false;
    isAttacking = false;
}

void Player::draw(sf::RenderWindow& window)
{
    
    window.draw(spriteEntity);
}

sf::Sprite Player::getSprite()
{
    return spriteEntity;
}

Player::~Player()
{
    
}
