#include "Player.h"
#include "SharedVariables.h"

Player::Player() {}

sf::Clock clo;

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
    spriteEntity.setScale(0.1f, 0.1f);
    spriteEntity.setPosition(spawnPos);
}

void Player::update(float& deltaTime, sf::Event& event, Map& map)
{
    hitBox.setPosition(spriteEntity.getPosition());
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        isAttacking = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        spriteEntity.move(speed * deltaTime, 0);
        moving = true;
        for (int i = 0; i < map.spritesWall.size(); i++) {
            if (map.spritesWall[i].getGlobalBounds().intersects(spriteEntity.getGlobalBounds())) {
                spriteEntity.move(-speed * deltaTime, 0);
                moving = false;
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        spriteEntity.move(-speed * deltaTime, 0);
        moving = true;
        for (int i = 0; i < map.spritesWall.size(); i++) {
            if (map.spritesWall[i].getGlobalBounds().intersects(spriteEntity.getGlobalBounds())) {
                spriteEntity.move(speed * deltaTime, 0);
                moving = false;
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        spriteEntity.move(0, -speed * deltaTime);
        moving = true;
        for (int i = 0; i < map.spritesWall.size(); i++) {
            if (map.spritesWall[i].getGlobalBounds().intersects(spriteEntity.getGlobalBounds())) {
                spriteEntity.move(0, speed * deltaTime);
                moving = false;
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        spriteEntity.move(0, speed * deltaTime);
        moving = true;
        for (int i = 0; i < map.spritesWall.size(); i++) {
            if (map.spritesWall[i].getGlobalBounds().intersects(spriteEntity.getGlobalBounds())) {
                spriteEntity.move(0, -speed * deltaTime);
                moving = false;
            }
        }
    }
    moving = false;
}

void Player::attaquer(sf::RenderWindow& window, Map& map) {
    resize(Shared::playerSwordTexture, swordPlayerSprite, 120, 120);
    resize(Shared::caillouxEnMietteTexture, caillouxEnMietteSprite, 32, 32);
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
        if (swordPlayerSprite.getGlobalBounds().intersects(map.spritesHerbes[i].getGlobalBounds()))
        {
            map.spritesHerbes.erase(map.spritesHerbes.begin() + i);
            rubis++;
            std::cout << "rubis : " << rubis << std::endl;
        }
    }
    for (int i = 0; i < map.spritesCailloux.size(); i++) {
        if(&map.spritesCailloux[i] && swordPlayerSprite.getGlobalBounds().intersects(map.spritesCailloux[i].getGlobalBounds())) {
            caillouxEnMietteSprite.setPosition(map.spritesCailloux[i].getPosition()); // --------------
            map.spritesCailloux[i].setScale(0, 0);
            map.spritesCaillouxEnMiette.push_back(caillouxEnMietteSprite);

            rubis++;
            std::cout << "rubis : " << rubis << std::endl;
        }
    }
    
}

void Player::draw(sf::RenderWindow& window)
{
    window.draw(spriteEntity);
}

sf::Sprite Player::getSprite()
{
    return spriteEntity;
}
int Player::getRubis() { return rubis; }
void Player::setRubis(int nb) { rubis = nb; }

Player::~Player()
{
    
}
