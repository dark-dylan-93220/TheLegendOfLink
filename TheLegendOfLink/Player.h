#pragma once

#include "SharedVariables.h"
#include "Entity.h"
#include "Eprojectiles.h"
#include <iostream>

class Player : public Entity
{
private:
    sf::Vector2f spawnPos;
    sf::RectangleShape hitBox;
    sf::Sprite swordPlayerSprite, caillouxEnMietteSprite;
    float speed = 200;
    int frame = 0;
    bool moving = false;
    bool isAttacking = false;
    int incrAttack = 0;
    bool back = false;
    float health;
    bool isInvincible;
    float invincibilityTimer;
    int rubis = 0;
    
public:
    std::vector<std::unique_ptr<Eprojectiles>> projectiles;
    sf::Clock playerLockClick;
    sf::Vector2f tampon;


public:
    int maxHealth = 6;
    bool possedeBocal = false;
    bool possedeFairy = false;
    Player();
    void init(sf::Sprite& sprite, sf::Vector2f& position) override;
    void update(float& deltaTime,sf::Event& event, Map& map) override;
    void draw(sf::RenderWindow& window) override;
    sf::Sprite getSprite();
    void setPositionPlayer(sf::Vector2f newPos);
    int getRubis();
    void setRubis(int nb);
    void attaquer(sf::RenderWindow& window, Map& map);
    void resize(sf::Texture& texture, sf::Sprite& sprite, const float& scaleX, const float& scaleY);
    void takeDamage(float damage);
    void heal(float amount);
    bool isDead() const;
    float getHealth() const;
    void updateInvincibility();
    bool isCurrentlyInvincible() const;
    ~Player();
};
