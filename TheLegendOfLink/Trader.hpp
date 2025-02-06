#pragma once

#ifndef TRADER_HPP
#define TRADER_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "SharedVariables.h"

struct Item {
    std::string name;
    int price;
};

class Trader {
private:
    std::vector<Item> traderInventory;
    bool isInventoryOpen;
    sf::Texture bocauxTexture, fairyTexture, receptacleTexture;
    sf::Sprite bocauxSprite, fairySprite, receptacleSprite, playerSwordSprite;
    sf::Text text;
    float y = 200;
    sf::Vector2f flechePos1 = { 750.f, 550.f };
    sf::Vector2f flechePos2 = { 750.f, 650.f };
    sf::Vector2f flechePos3 = { 750.f, 750.f };
    sf::Vector2f flechePos4 = { 750.f, 850.f };

public:

    sf::Sprite traderSprite, traderGUISprite, flecheSprite;
    void draw(sf::RenderWindow& window);
    void openInventory();
    void closeInventory();
    bool isNear(const sf::Sprite& playerSprite);
    int buyItem();
    void setPosition(float x, float y);
    void init(sf::Texture& texture);

    const std::vector<Item>& getInventory() const { return traderInventory; };
    bool getInventoryStatus() const { return isInventoryOpen; };
    void resize(sf::Texture& texture, sf::Sprite& sprite, const float& scaleX, const float& scaleY);
    void setPos(sf::Vector2f vectorPos);
    void selectItem(int val);
};

#endif
