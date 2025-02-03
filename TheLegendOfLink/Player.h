#pragma once

#include "SharedVariables.h"
#include "Entity.h"
#include <iostream>

class Player : public Entity
{
private:
    sf::Vector2f spawnPos;
    sf::RectangleShape hitBox;
    sf::Sprite swordPlayerSprite;
    float speed = 200;
    int frame = 0;
    bool moving = false;
    bool isAttacking = false;
    int incrAttack = 0;
    bool back = false;
    float health;
    bool isInvincible;
    sf::Clock invincibilityTimer;
    int korogus;
    int rubis;
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
    void update(float& deltaTime,sf::Event& event, Map& map) override;
    void draw(sf::RenderWindow& window) override;
    sf::Sprite getSprite();
    int getKorogus();
    void setKorogus(int nb);
    void attaquer(sf::RenderWindow& window, Map& map);
    void resize(sf::Texture& texture, sf::Sprite& sprite, const float& scaleX, const float& scaleY);
    ~Player();
};
