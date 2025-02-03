#pragma once

#include "Entity.h"

class Player : public Entity
{
private:
    sf::Vector2f spawnPos;
    sf::RectangleShape hitBox;
    float speed = 200;
    int frame = 0;
    bool moving = false;
    bool isAttacking = false;
    bool back = false;
    float health;
    bool isInvincible;
    sf::Clock invincibilityTimer;
public:
    void takeDamage(float damage);
    void heal(float amount);
    bool isDead() const;
    float getHealth() const;
    void updateInvincibility();
    bool isCurrentlyInvincible() const;
public:
    Player();
    void init(sf::Sprite& sprite, sf::Vector2f& position) override;
    void update(float& deltaTime,sf::Event& event) override;
    void draw(sf::RenderWindow& window) override;
    sf::Sprite getSprite();
    ~Player();
};
