#include "Player.h"

Player::Player(sf::Sprite sprite, sf::Vector2f position)
{
    spawnPos = position;
    init(sprite);
}


void Player::init(sf::Sprite& sprite)
{
    spriteEntity = sprite;
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
        spriteEntity.move(speed * deltaTime, 0);
        moving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !moving)
    {
        spriteEntity.move( -speed * deltaTime, 0);
        moving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && !moving)
    {
        spriteEntity.move( 0 , -speed * deltaTime);
        moving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !moving)
    {
        spriteEntity.move(  0, speed * deltaTime);
        moving = true;
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
