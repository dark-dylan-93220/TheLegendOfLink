#include "Map.hpp"
#include <iostream>

void Map::resize(sf::Texture& texture, sf::Sprite& sprite, const float& scaleX, const float& scaleY) {
    sprite.setTexture(texture);
    float scaleFinaleX = scaleX / texture.getSize().x;
    float scaleFinaleY = scaleY / texture.getSize().y;
    sprite.setScale(scaleFinaleX, scaleFinaleY);
}

void Map::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (getline(file, line)) {
        mapData.push_back(line);
    }
    murTexture.loadFromFile("assets/tiles/wall.png");
    grassTexture.loadFromFile("assets/tiles/grass.png"); 
    herbeTexture.loadFromFile("assets/tiles/herbe.png");
    korogusTexture.loadFromFile("assets/tiles/korogus.png");
    caillouxTexture.loadFromFile("assets/tiles/caillou.png");
}

void Map::addVector() {
    for (size_t y = 0; y < mapData.size(); ++y) {
        for (size_t x = 0; x < mapData[y].size(); ++x) {
            if (mapData[y][x] == '#') {
                sf::Sprite murSprite;
                resize(murTexture, murSprite, SIZEX, SIZEY);
                murSprite.setPosition(x * SIZEX, y * SIZEY);
                spritesWall.push_back(murSprite);
            }
            else {
                sf::Sprite grassSprite;
                resize(grassTexture, grassSprite, SIZEX, SIZEY);
                grassSprite.setPosition(x * SIZEX, y * SIZEY);
                spritesGrass.push_back(grassSprite);
            }
            if (mapData[y][x] == 'h') {
                sf::Sprite herbeSprite;
                resize(herbeTexture, herbeSprite, SIZEX, SIZEY);
                herbeSprite.setPosition(x * SIZEX, y * SIZEY);
                spritesHerbes.push_back(herbeSprite);
            }
            if (mapData[y][x] == 'K') {
                sf::Sprite korogusSprite;
                resize(korogusTexture, korogusSprite, SIZEX, SIZEY);
                korogusSprite.setPosition(x * SIZEX, y * SIZEY);
                spritesKorogus.push_back(korogusSprite);
            }
            if (mapData[y][x] == 'C') {
                sf::Sprite caillouxSprite;
                resize(caillouxTexture, caillouxSprite, SIZEX, SIZEY);
                caillouxSprite.setPosition(x * SIZEX, y * SIZEY);
                spritesCailloux.push_back(caillouxSprite);
            }
        }
    }
}

void Map::draw(sf::RenderWindow& window) {
    for (auto elem : spritesGrass) {
        window.draw(elem);
    }
    for (auto elem : spritesKorogus) {
        window.draw(elem);
    }
    for (auto elem : spritesHerbes) {
        window.draw(elem);
    }
    for (auto elem : spritesWall) {
        window.draw(elem);
    }
    for (auto elem : spritesCailloux) {
        window.draw(elem);
    }
    for (auto elem : spritesCaillouxEnMiette) {
        window.draw(elem);
    }
}

bool Map::isObstacle(double x, double y) {
    int tileX = x / (double)SIZEX;
    int tileY = y / (double)SIZEY;

    if (mapData[tileY][tileX] == '#' || mapData[tileY][tileX] == 'C') {
        return true;
    }
    return false;
}
