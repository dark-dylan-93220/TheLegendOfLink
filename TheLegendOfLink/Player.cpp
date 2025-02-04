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

void Player::resize(sf::Texture& texture, sf::Sprite& sprite, const float& scaleX, const float& scaleY) {
    sprite.setTexture(texture);
    float scaleFinaleX = scaleX / texture.getSize().x;
    float scaleFinaleY = scaleY / texture.getSize().y;
    sprite.setScale(scaleFinaleX, scaleFinaleY);
}

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
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        isAttacking = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !moving)
    {
        spriteEntity.move(speed * deltaTime * 1.666667f, 0);
        moving = true;
        for (int i = 0; i < map.spritesWall.size(); i++) {
            if (map.spritesWall[i].getGlobalBounds().intersects(spriteEntity.getGlobalBounds())) {
                std::cout << "collide\n";
                spriteEntity.move(-speed * deltaTime * 1.6666667f, 0);
                moving = false;
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !moving)
    {
        spriteEntity.move(-speed * deltaTime * 1.666667f, 0);
        moving = true;
        for (int i = 0; i < map.spritesWall.size(); i++) {
            if (map.spritesWall[i].getGlobalBounds().intersects(spriteEntity.getGlobalBounds())) {
                std::cout << "collide\n";
                spriteEntity.move(speed * deltaTime * 1.6666667f, 0);
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
}

void Player::attaquer(sf::RenderWindow& window, Map& map) {
    resize(Shared::playerSwordTexture, swordPlayerSprite, 120, 120);
    if (isAttacking) { incrAttack++; }
    if (incrAttack > 18) {
        incrAttack = 0;
        isAttacking = false;
    }
    if (incrAttack != 0) {
        swordPlayerSprite.setPosition(spriteEntity.getPosition().x + spriteEntity.getGlobalBounds().width / 2, spriteEntity.getPosition().y + spriteEntity.getGlobalBounds().height / 2);
        swordPlayerSprite.setRotation(incrAttack * 20);
        window.draw(swordPlayerSprite);
    }
    for (int i = 0; i < map.spritesHerbes.size(); i++)
    {
        if (swordPlayerSprite.getGlobalBounds().intersects(map.spritesHerbes[i].getGlobalBounds()))
        {
            map.spritesHerbes.erase(map.spritesHerbes.begin() + i);
            rubis++;
        }
        

    } 
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
int Player::getKorogus() const { return korogus; }
void Player::setKorogus(int nb) { korogus = nb; }

Player::~Player()
{
    
}
