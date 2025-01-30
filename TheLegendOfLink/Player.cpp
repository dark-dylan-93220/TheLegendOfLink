#include "Player.h"

Player::Player(sf::Sprite sprite, sf::Vector2f position) : spawnPos(position)
{
    init(sprite);
}


void Player::init(sf::Sprite& sprite)
{
    spritePlayer = sprite;
    //spritePlayer.setScale(0.01f, 0.01f);
    spritePlayer.setPosition(spawnPos);
}

void Player::update(float& deltaTime,sf::Event& event)
{
    hitBox.setPosition(spritePlayer.getPosition());
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    {
        isAttacking = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !moving)
    {
        spritePlayer.move(speed * deltaTime, 0);
        moving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !moving)
    {
        spritePlayer.move( -speed * deltaTime, 0);
        moving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && !moving)
    {
        spritePlayer.move( 0 , -speed * deltaTime);
        moving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !moving)
    {
        spritePlayer.move(  0, speed * deltaTime);
        moving = true;
    } 
    moving = false;
    isAttacking = false;
}

void Player::draw(sf::RenderWindow& window)
{
    window.draw(spritePlayer);
}

sf::Sprite Player::getSprite()
{
    return spritePlayer;
}

Player::~Player()
{
    
}
