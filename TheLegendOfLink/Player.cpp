#include "Player.h"

Player::Player(sf::Sprite sprite, sf::Vector2f position) : spawnPos(position)
{
    init(sprite);
}


void Player::init(sf::Sprite& sprite)
{
    spritePlayer = sprite;
    spritePlayer.setPosition(spawnPos);
}

void Player::update(float& deltaTime,sf::Event& event)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !moving)
    {
        spritePlayer.move(speed, 0);
        moving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !moving)
    {
        spritePlayer.move( -speed , 0);
        moving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && !moving)
    {
        spritePlayer.move( 0 , -speed);
        moving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !moving)
    {
        spritePlayer.move(  0, speed);
        moving = true;
    }

    moving = false;
}