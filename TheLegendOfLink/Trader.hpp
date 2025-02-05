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
    sf::Sprite traderSprite;
    std::vector<Item> traderInventory;
    bool isInventoryOpen;

public:

    void draw(sf::RenderWindow& window);
    void openInventory();
    void closeInventory();
    bool isNear(const sf::Vector2f& playerPos);
    bool buyItem(int index, int& playerRubis);
    void setPosition(float x, float y);
    void init(sf::Texture& texture);

    const std::vector<Item>& getInventory() const { return traderInventory; }
    bool getInventoryStatus() const { return isInventoryOpen; }
};

#endif
