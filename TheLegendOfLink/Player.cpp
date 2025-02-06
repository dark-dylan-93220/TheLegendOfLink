#include "Player.h"
#include "Game.hpp"

Player::Player(): health(3) {}

sf::Clock clo;

void Player::takeDamage(float damage) {
    health -= damage;
    if (health <= 0) health = 0;
    // Active l'invincibilité pendant 2 secondes
    isInvincible = true;
    invincibilityTimer = 0.f;
}

void Player::heal(float amount) {
    health += amount;
    if (health > 10) health = 10; // (à modifier si jamais)
    if (health > maxHealth) { health = maxHealth; }
}

bool Player::isDead() const {
    return health <= 0;
}

float Player::getHealth() const {
    return health;
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
    spriteEntity.setScale(0.15f * (16.0f/9.0f), 0.15f);
    spriteEntity.setPosition(spawnPos);
}

void Player::update(float& deltaTime, sf::Event& event, Map& map)
{
    invincibilityTimer += deltaTime;
    hitBox.setPosition(spriteEntity.getPosition());
    if (isInvincible && invincibilityTimer >= 2.0f) {
        isInvincible = false;  // Fin de l’invincibilité après 2 secondes
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        isAttacking = true;
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && playerLockClick.getElapsedTime().asSeconds() >= 1.5f)
    {
        projectiles.push_back(std::make_unique<Eprojectiles>((tampon)));
        tampon = spriteEntity.getPosition();
        projectiles.back()->init(Shared::projectileSprite,tampon);
        playerLockClick.restart();
    }
    for (auto& projectile : projectiles)
    {
        if (projectile == nullptr){}
        
        else if (projectile->lifetime >= 5.f)
        {
            projectiles.erase(std::find(projectiles.begin(), projectiles.end(),projectile));
        }
        else
        {
            projectile->update(deltaTime,event,map);
            for (int i = 0; i < map.spritesWall.size(); i++) {
                if (map.spritesWall[i].getGlobalBounds().intersects(projectile->getSprite().getGlobalBounds())) {
                    projectile->isColliding = true;
                }
            }
            for (auto& wall : map.spritesWallDonjon)
            {
                if (wall.getGlobalBounds().intersects(projectile->getSprite().getGlobalBounds()))
                {
                    projectile->isColliding = true;
                }
            }
            for (auto& ennemie : Shared::enemies)
            {
                if (projectile->getSprite().getGlobalBounds().intersects(ennemie->getSprite().getGlobalBounds()))
                {
                    ennemie->shouldBeDeleted = true;
                }
            }
            projectile->lifetime += deltaTime;
        }
        
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !moving)
    {
        spriteEntity.move(speed * (16.f/9.f) * deltaTime, 0);
        moving = true;
        for (int i = 0; i < map.spritesWall.size(); i++) {
            if (map.spritesWall[i].getGlobalBounds().intersects(spriteEntity.getGlobalBounds())) {
                std::cout << "collide\n";
                spriteEntity.move(-speed * (16.f/9.f) * deltaTime, 0);
                moving = false;
            }
        }
        for (int i = 0; i < map.spritesWallDonjon.size(); i++) {
            if (map.spritesWallDonjon[i].getGlobalBounds().intersects(spriteEntity.getGlobalBounds())) {
                std::cout << "collide\n";
                spriteEntity.move(-speed * (16.f / 9.f) * deltaTime, 0);
                moving = false;
            }
        }
        for (int i = 0; i < map.spritesCailloux.size(); i++) {
            if (map.spritesCailloux[i].getGlobalBounds().intersects(spriteEntity.getGlobalBounds())) {
                std::cout << "collide\n";
                spriteEntity.move(-speed * (16.f / 9.f) * deltaTime, 0);
                moving = false;
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !moving)
    {
        spriteEntity.move(-speed * (16.f/9.f) * deltaTime, 0);
        moving = true;
        for (int i = 0; i < map.spritesWall.size(); i++) {
            if (map.spritesWall[i].getGlobalBounds().intersects(spriteEntity.getGlobalBounds())) {
                spriteEntity.move(speed * (16.f/9.f) * deltaTime, 0);
                moving = false;
            }
        }
        for (int i = 0; i < map.spritesWallDonjon.size(); i++) {
            if (map.spritesWallDonjon[i].getGlobalBounds().intersects(spriteEntity.getGlobalBounds())) {
                spriteEntity.move(speed * (16.f / 9.f) * deltaTime, 0);
                moving = false;
            }
        }
        for (int i = 0; i < map.spritesCailloux.size(); i++) {
            if (map.spritesCailloux[i].getGlobalBounds().intersects(spriteEntity.getGlobalBounds())) {
                spriteEntity.move(speed * (16.f / 9.f) * deltaTime, 0);
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
                spriteEntity.move(0, speed * deltaTime);
                moving = false;
            }
        }
        for (int i = 0; i < map.spritesWallDonjon.size(); i++) {
            if (map.spritesWallDonjon[i].getGlobalBounds().intersects(spriteEntity.getGlobalBounds())) {
                spriteEntity.move(0, speed * deltaTime);
                moving = false;
            }
        }
        for (int i = 0; i < map.spritesCailloux.size(); i++) {
            if (map.spritesCailloux[i].getGlobalBounds().intersects(spriteEntity.getGlobalBounds())) {
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
                spriteEntity.move(0, -speed * deltaTime);
                moving = false;
            }
        }
        for (int i = 0; i < map.spritesWallDonjon.size(); i++) {
            if (map.spritesWallDonjon[i].getGlobalBounds().intersects(spriteEntity.getGlobalBounds())) {
                spriteEntity.move(0, -speed * deltaTime);
                moving = false;
            }
        }
        for (int i = 0; i < map.spritesCailloux.size(); i++) {
            if (map.spritesCailloux[i].getGlobalBounds().intersects(spriteEntity.getGlobalBounds())) {
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
    for (int i = 0; i < map.spritesBocaux.size(); i++)
    {
        if (map.spritesBocaux[i].getGlobalBounds().intersects(spriteEntity.getGlobalBounds())) {
            map.spritesBocaux.erase(map.spritesBocaux.begin() + i);
            possedeBocal = true;
        }
    }
    for (int i = 0; i < map.spritesFairy.size(); i++)
    {
        if (map.spritesFairy[i].getGlobalBounds().intersects(spriteEntity.getGlobalBounds()) && possedeBocal) {
            map.spritesFairy.erase(map.spritesFairy.begin() + i);
            possedeFairy = true;
        }
    }
    for (int i = 0; i < map.spritesReceptacles.size(); i++)
    {
        if (map.spritesReceptacles[i].getGlobalBounds().intersects(spriteEntity.getGlobalBounds())) {
            map.spritesReceptacles.erase(map.spritesReceptacles.begin() + i);
            maxHealth++;
            heal(1);
        }
    }
}

void Player::attaquer(sf::RenderWindow& window, Map& map) {
    resize(Shared::playerSwordTexture, swordPlayerSprite, 120, 120);
    resize(Shared::caillouxEnMietteTexture, caillouxEnMietteSprite, 80, 40);
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
    for (int i = 0; i < map.spritesHerbes.size(); i++) {
        if (swordPlayerSprite.getGlobalBounds().intersects(map.spritesHerbes[i].getGlobalBounds())) {
            map.spritesHerbes.erase(map.spritesHerbes.begin() + i);
            rubis++;
            std::cout << "rubis : " << rubis << std::endl;
        }
    }
    for (int i = 0; i < map.spritesCailloux.size(); i++) {
        if(&map.spritesCailloux[i] && swordPlayerSprite.getGlobalBounds().intersects(map.spritesCailloux[i].getGlobalBounds())) {
            caillouxEnMietteSprite.setPosition(map.spritesCailloux[i].getPosition());
            map.spritesCailloux[i].setScale(0, 0);
            map.spritesCaillouxEnMiette.push_back(caillouxEnMietteSprite);

            rubis++;
            std::cout << "rubis : " << rubis << std::endl;
        }
    }
}

void Player::draw(sf::RenderWindow& window)
{
    if (isInvincible) {
        int alpha = (std::fmod(invincibilityTimer / 100.0f, 2.0f)) == 0.0f ? 255 : 100;
        spriteEntity.setColor(sf::Color(255, 255, 255, alpha));  // Clignotement
    }
    else {
        spriteEntity.setColor(sf::Color(255, 255, 255, 255));  // Normal
    }
    for (auto& projectile : projectiles)
    {
        if (projectile == nullptr){}
        projectile->draw(window);
    }
    window.draw(spriteEntity);
}

sf::Sprite Player::getSprite()
{
    return spriteEntity;
}

void Player::setPositionPlayer(sf::Vector2f newPos)
{
    spriteEntity.setPosition(newPos);
}
int Player::getRubis() { return rubis; }
void Player::setRubis(int nb) { rubis = nb; }

Player::~Player()
{
    
}
