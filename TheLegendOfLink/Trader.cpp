#include "Trader.hpp"
#include <iostream>

void Trader::init(sf::Texture& texture) {
    resize(texture, traderSprite, 32 * 2, 32 * 1.5);
    traderInventory.push_back({ "epee", 20 });
    traderInventory.push_back({ "bocal", 5 });
    traderInventory.push_back({ "receptacle de coeur - rupture de stock", 10 });
    traderInventory.push_back({ "fee", 15 });

    bocauxTexture.loadFromFile("assets/tiles/bocaux.png");
    fairyTexture.loadFromFile("assets/tiles/fairy.png");
    receptacleTexture.loadFromFile("assets/tiles/receptacle.png");

    resize(bocauxTexture, bocauxSprite, 100, 100);
    resize(fairyTexture, fairySprite, 100, 100);
    resize(receptacleTexture, receptacleSprite, 100, 100);
    resize(Shared::playerSwordTexture, playerSwordSprite, 100, 100);
    resize(Shared::flecheTexture, flecheSprite, 100, 100);
    
}

void Trader::draw(sf::RenderWindow& window) {
    window.draw(traderSprite);
    if (isInventoryOpen) {
        resize(Shared::traderGUI, traderGUISprite, window.getDefaultView().getSize().x, window.getDefaultView().getSize().y);
        window.draw(traderGUISprite);
        window.draw(bocauxSprite);
        window.draw(fairySprite);
        window.draw(receptacleSprite);
        window.draw(playerSwordSprite);
        window.draw(flecheSprite);
        for (size_t i = 0; i < traderInventory.size(); i++) {
            text.setString(traderInventory[i].name + " - " + std::to_string(traderInventory[i].price) + " rubis");
            window.draw(text);
            y += 100;
        }
    }
}

void Trader::openInventory() {
    isInventoryOpen = true;
}

void Trader::closeInventory() {
    isInventoryOpen = false;
}

bool Trader::isNear(const sf::Sprite& playerSprite) {
    return traderSprite.getGlobalBounds().intersects(playerSprite.getGlobalBounds());
}

void Trader::setPosition(float x, float y) {
    traderSprite.setPosition(x, y);
}

int Trader::buyItem() {
    int playerRubis = 0;
    if (550.f == flechePos1.y) {
        playerRubis -= traderInventory[0].price;
        return 5;
    }
    if (750.f == flechePos1.y) {
        playerRubis -= traderInventory[2].price;
        return 15;
    }
    if (850.f == flechePos1.y) {
        playerRubis -= traderInventory[3].price;
        return 20;
    }
}

void Trader::resize(sf::Texture& texture, sf::Sprite& sprite, const float& scaleX, const float& scaleY) {
    sprite.setTexture(texture);
    float scaleFinaleX = scaleX / texture.getSize().x;
    float scaleFinaleY = scaleY / texture.getSize().y;
    sprite.setScale(scaleFinaleX, scaleFinaleY);
}

void Trader::setPos(sf::Vector2f vectorPos) {
    traderGUISprite.setPosition(vectorPos);
    bocauxSprite.setPosition(vectorPos.x + 950, vectorPos.y + 220);
    fairySprite.setPosition(vectorPos.x + 950, vectorPos.y + 320);
    receptacleSprite.setPosition(vectorPos.x + 950, vectorPos.y + 420);
    playerSwordSprite.setPosition(vectorPos.x + 950, vectorPos.y + 520);

    text.setFont(Shared::pixelNes);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);
    text.setPosition(vectorPos.x + 1500, vectorPos.y + y);
    
}

void Trader::selectItem(int val) {
    
    if (val == 1) {
         flecheSprite.setPosition(flechePos1);
    }
    else if (val == 2) {
        flecheSprite.setPosition(flechePos2);
    }
    else if (val == 3) {
        flecheSprite.setPosition(flechePos3);
    }
    else if (val == 4) {
        flecheSprite.setPosition(flechePos4);
    }
}
