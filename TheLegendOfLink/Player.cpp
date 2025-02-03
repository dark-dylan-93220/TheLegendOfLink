#include "Player.h"
#include "SharedVariables.h"

Player::Player() {}

sf::Clock clo;

void Player::init(sf::Sprite& sprite, sf::Vector2f& position)
{
    spawnPos = position;
    spriteEntity = sprite;
    spriteEntity.setScale(0.35f, 0.15f);
    spriteEntity.setPosition(spawnPos);
}

void Player::update(float& deltaTime, sf::Event& event, Map& map)
{
    hitBox.setPosition(spriteEntity.getPosition());
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    {
        isAttacking = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !moving)
    {
        spriteEntity.move(speed * deltaTime, 0);
        moving = true;
        for (int i = 0; i < map.spritesWall.size(); i++) {
            if (map.spritesWall[i].getGlobalBounds().intersects(spriteEntity.getGlobalBounds())) {
                std::cout << "collide\n";
                spriteEntity.move(-speed * deltaTime, 0);
                moving = false;
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !moving)
    {
        spriteEntity.move(-speed * deltaTime, 0);
        moving = true;
        for (int i = 0; i < map.spritesWall.size(); i++) {
            if (map.spritesWall[i].getGlobalBounds().intersects(spriteEntity.getGlobalBounds())) {
                std::cout << "collide\n";
                spriteEntity.move(speed * deltaTime, 0);
                moving = false;
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && !moving)
    {
        spriteEntity.move(0, -speed * deltaTime);
        back = true;
        moving = true;
        for (int i = 0; i < map.spritesWall.size(); i++) {
            if (map.spritesWall[i].getGlobalBounds().intersects(spriteEntity.getGlobalBounds())) {
                std::cout << "collide\n";
                spriteEntity.move(0, speed * deltaTime);
                moving = false;
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !moving)
    {
        spriteEntity.move(0, speed * deltaTime);
        back = false;
        moving = true;
        for (int i = 0; i < map.spritesWall.size(); i++) {
            if (map.spritesWall[i].getGlobalBounds().intersects(spriteEntity.getGlobalBounds())) {
                std::cout << "collide\n";
                spriteEntity.move(0, -speed * deltaTime);
                moving = false;
            }
        }
    }
    if (moving)
    {
        if (frame > 5)
        {
            frame = 0;
        }
        if (clo.getElapsedTime().asSeconds() > 0.15f && !back)
        {
            spriteEntity.setTexture(Shared::playerTextures.at(frame));
            clo.restart();
            frame++;
        }
        else if (clo.getElapsedTime().asSeconds() > 0.15f && back)
        {
            spriteEntity.setTexture(Shared::playerTexturesBack.at(frame));
            clo.restart();
            frame++;
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
