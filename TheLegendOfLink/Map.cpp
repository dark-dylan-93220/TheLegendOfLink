#include "Map.hpp"
#include "Game.hpp"
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
    while (getline(file, line)) {
        mapDonjonData.push_back(line);
    }
    murTexture.loadFromFile("assets/tiles/wall.png");
    grassTexture.loadFromFile("assets/tiles/grass.png");
    herbeTexture.loadFromFile("assets/tiles/herbe.png");
    wallDonjonTexture.loadFromFile("assets/tiles/wall_donjon.png");
    floorDonjonTexture.loadFromFile("assets/tiles/floor_donjon.png");
    porteTexture.loadFromFile("assets/tiles/porte.png");
    caillouxTexture.loadFromFile("assets/tiles/caillou.png");
    bocauxTexture.loadFromFile("assets/tiles/bocaux.png");
    fairyTexture.loadFromFile("assets/tiles/fairy.png");
    receptacleTexture.loadFromFile("assets/tiles/receptacle.png");
}

void Map::addVector(Trader& trader) {
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
            if (mapData[y][x] == 'C') {
                sf::Sprite caillouxSprite;
                resize(caillouxTexture, caillouxSprite, SIZEX, SIZEY);
                caillouxSprite.setPosition(x * SIZEX, y * SIZEY);
                spritesCailloux.push_back(caillouxSprite);
            }
            if (mapData[y][x] == 'B') {
                sf::Sprite bocauxSprite;
                resize(bocauxTexture, bocauxSprite, SIZEX, SIZEY);
                bocauxSprite.setPosition(x * SIZEX, y * SIZEY);
                spritesBocaux.push_back(bocauxSprite);
            }
            if (mapData[y][x] == 'F') {
                sf::Sprite fairySprite;
                resize(fairyTexture, fairySprite, SIZEX, SIZEY);
                fairySprite.setPosition(x * SIZEX, y * SIZEY);
                spritesFairy.push_back(fairySprite);
            }
            if (mapData[y][x] == 'R') {
                sf::Sprite receptacleSprite;
                resize(receptacleTexture, receptacleSprite, SIZEX, SIZEY);
                receptacleSprite.setPosition(x * SIZEX, y * SIZEY);
                spritesReceptacles.push_back(receptacleSprite);
            }
            if (mapData[y][x] == 'P') {
                sf::Sprite porteSprite;
                resize(porteTexture, porteSprite, SIZEX, SIZEY);
                porteSprite.setPosition(x * SIZEX, y * SIZEY);
                spritesPorte.push_back(porteSprite);
            }
            if (mapData[y][x] == 'T') { // la texture n'est pas appliquée
                trader.setPosition(x * SIZEX, y * SIZEY);
                std::cout << "tests" << std::endl;
            }
        }
    }
    for (size_t y = 0; y < mapDonjonData.size(); ++y) {
        for (size_t x = 0; x < mapDonjonData[y].size(); ++x) {
            if (mapDonjonData[y][x] == 'w') {
                sf::Sprite wallDonjonSprite;
                resize(wallDonjonTexture, wallDonjonSprite, SIZEX, SIZEY);
                wallDonjonSprite.setPosition(x * SIZEX, y * SIZEY);
                spritesWallDonjon.push_back(wallDonjonSprite);
            }
            if (mapDonjonData[y][x] == 'f') {
                sf::Sprite floorDonjonSprite;
                resize(floorDonjonTexture, floorDonjonSprite, SIZEX, SIZEY);
                floorDonjonSprite.setPosition(x * SIZEX, y * SIZEY);
                spritesFloorDonjon.push_back(floorDonjonSprite);
            }
        }
    }
}

void Map::draw(sf::RenderWindow& window) {
    for (auto elem : spritesGrass) {
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
    for (auto elem : spritesBocaux) {
        window.draw(elem);
    }
    for (auto elem : spritesFairy) {
        window.draw(elem);
    }
    for (auto elem : spritesReceptacles) {
        window.draw(elem);
    }
    for (auto elem : spritesWallDonjon) {
        window.draw(elem);
    }
    for (auto elem : spritesFloorDonjon) {
        window.draw(elem);
    }
    for (auto elem : spritesPorte) {
        window.draw(elem);
    }
    
}

bool Map::isObstacle(double x, double y) {
    int tileX = x / (double)SIZEX;
    int tileY = y / (double)SIZEY;

    if (mapData[tileY][tileX] == '#' || mapData[tileY][tileX] == 'C') {
        return true;
    }
    if (mapDonjonData[tileY][tileX] == 'w') {
        return true;
    }
    return false;
}
