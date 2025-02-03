#include "Player.h"
#include "SharedVariables.h"
#include "Entity.h"
Player::Player(): health(3) {}

sf::Clock clo;

void Player::takeDamage(float damage) {
    health -= damage;
    if (health <= 0) health = 0;
    // Active l'invincibilité pendant 2 secondes
    isInvincible = true;
    invincibilityTimer.restart();
}

void Player::heal(float amount) {
    health += amount;
    if (health > 10) health = 10;  // (à modifier si jamais)
}

bool Player::isDead() const {
    return health <= 0;
}

float Player::getHealth() const {
    return health;
}

void Player::updateInvincibility() {
    if (isInvincible && invincibilityTimer.getElapsedTime().asSeconds() >= 2.0f) {
        isInvincible = false;  // Fin de l’invincibilité après 2 secondes
    }
}

bool Player::isCurrentlyInvincible() const {
    return isInvincible;
}

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
    if (isInvincible) {
        int alpha = (invincibilityTimer.getElapsedTime().asMilliseconds() / 100) % 2 == 0 ? 255 : 100;
        spriteEntity.setColor(sf::Color(255, 255, 255, alpha));  // Clignotement
    }
    else {
        spriteEntity.setColor(sf::Color(255, 255, 255, 255));  // Normal
    }

    window.draw(spriteEntity);
}

sf::Sprite Player::getSprite()
{
    return spriteEntity;
}

Player::~Player()
{
    
}
