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

void Player::update(float& deltaTime,sf::Event& event)
{
    hitBox.setPosition(spriteEntity.getPosition());
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    {
        isAttacking = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !moving)
    {
        spriteEntity.move(speed * 2 * deltaTime, 0);
        moving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !moving)
    {
        spriteEntity.move( -speed * 2  * deltaTime, 0);
        moving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && !moving)
    {
        spriteEntity.move( 0 , -speed * deltaTime);
        back = true;
        moving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !moving)
    {
        spriteEntity.move(0, speed * deltaTime);
        back = false;
        moving = true;
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
