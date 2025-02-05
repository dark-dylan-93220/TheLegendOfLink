#include "Trader.hpp"

#include <iostream>

void Trader::init(sf::Texture& texture) {
    traderSprite.setTexture(texture);
    traderInventory.push_back({ "receptacle de coeur", 10 });
    traderInventory.push_back({ "bocal", 5 });
    traderInventory.push_back({ "fee", 15 });
}

void Trader::draw(sf::RenderWindow& window) {
    window.draw(traderSprite);
    if (isInventoryOpen) {
        sf::Text text;
        text.setFont(Shared::pixelNes);
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::White);

        float y = 50;
        for (size_t i = 0; i < traderInventory.size(); i++) {
            text.setString(traderInventory[i].name + " - " + std::to_string(traderInventory[i].price) + " rubis");
            text.setPosition(400, y);
            window.draw(text);
            y += 30;
        }
    }
}

void Trader::openInventory() {
    isInventoryOpen = true;
}

void Trader::closeInventory() {
    isInventoryOpen = false;
}

bool Trader::isNear(const sf::Vector2f& playerPos) {
    return traderSprite.getGlobalBounds().contains(playerPos);
}

void Trader::setPosition(float x, float y) {
    traderSprite.setPosition(x, y);
}

bool Trader::buyItem(int index, int& playerRubis) {
    if (index >= 0 && index < traderInventory.size() && playerRubis >= traderInventory[index].price) {
        playerRubis -= traderInventory[index].price;
        std::cout << "Achat reussi" << traderInventory[index].name << std::endl;
        return true;
    }
    std::cout << "Achat impossible" << std::endl;
    return false;
}
