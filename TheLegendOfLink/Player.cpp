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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        spritePlayer.move(speed, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        spritePlayer.move( -speed , 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        spritePlayer.move( 0 , -speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        spritePlayer.move(  0, speed);
    }
}