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

void Map::addVector() {
    for (size_t y = 0; y < mapData.size(); ++y) {
        for (size_t x = 0; x < mapData[y].size(); ++x) {
            if (mapData[y][x] == '#') {
                sf::Sprite murSprite;
                resize(murTexture, murSprite, SIZEX, SIZEY);
                murSprite.setPosition(x * SIZEX, y * SIZEY);
                spritesWall.push_back(murSprite);
            }
            
            if (mapData[y][x] == 'h') {
                sf::Sprite herbeSprite;
                resize(herbeTexture, herbeSprite, SIZEX, SIZEY);
                herbeSprite.setPosition(x * SIZEX, y * SIZEY);
                spritesHerbes.push_back(herbeSprite);
            }
            if (mapData[y][x] == 'C') {
                if (spritesWall.empty()) {
                    sf::Sprite floorDonjonSprite;
                    resize(floorDonjonTexture, floorDonjonSprite, SIZEX, SIZEY);
                    floorDonjonSprite.setPosition(x * SIZEX, y * SIZEY);
                    spritesFloorDonjon.push_back(floorDonjonSprite);
                }
                else
                {
                    sf::Sprite grassSprite;
                    resize(grassTexture, grassSprite, SIZEX, SIZEY);
                    grassSprite.setPosition(x * SIZEX, y * SIZEY);
                    spritesGrass.push_back(grassSprite);
                }
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
                doors.push_back(porteSprite);
            }
            if (mapData[y][x] == 'E')
            {  
                if (spritesWall.empty()) {
                    sf::Sprite floorDonjonSprite;
                    resize(floorDonjonTexture, floorDonjonSprite, SIZEX, SIZEY);
                    floorDonjonSprite.setPosition(x * SIZEX, y * SIZEY);
                    spritesFloorDonjon.push_back(floorDonjonSprite);
                }
                else
                {
                    sf::Sprite grassSprite;
                    resize(grassTexture, grassSprite, SIZEX, SIZEY);
                    grassSprite.setPosition(x * SIZEX, y * SIZEY);
                    spritesGrass.push_back(grassSprite);
                }
                sf::Vector2f pos = { x * SIZEX, y * SIZEY };
                std::unique_ptr<Bokoblin> bok = std::make_unique<Bokoblin>();
                bok->init(Shared::bokoSprite, pos);
                Shared::enemies.push_back(std::move(bok));
            }
            else {
                sf::Sprite grassSprite;
                resize(grassTexture, grassSprite, SIZEX, SIZEY);
                grassSprite.setPosition(x * SIZEX, y * SIZEY);
                spritesGrass.push_back(grassSprite);
            }
            if (mapData[y][x] == 'w') {
                sf::Sprite wallDonjonSprite;
                resize(wallDonjonTexture, wallDonjonSprite, SIZEX, SIZEY);
                wallDonjonSprite.setPosition(x * SIZEX, y * SIZEY);
                spritesWallDonjon.push_back(wallDonjonSprite);
            }
            if (mapData[y][x] == 'f') {
                sf::Sprite floorDonjonSprite;
                resize(floorDonjonTexture, floorDonjonSprite, SIZEX, SIZEY);
                floorDonjonSprite.setPosition(x * SIZEX, y * SIZEY);
                spritesFloorDonjon.push_back(floorDonjonSprite);
            }
            if (mapData[y][x] == 'L')
            {
                if (spritesWall.empty()) {
                    sf::Sprite floorDonjonSprite;
                    resize(floorDonjonTexture, floorDonjonSprite, SIZEX, SIZEY);
                    floorDonjonSprite.setPosition(x * SIZEX, y * SIZEY);
                    spritesFloorDonjon.push_back(floorDonjonSprite);
                }
                else
                {
                    sf::Sprite grassSprite;
                    resize(grassTexture, grassSprite, SIZEX, SIZEY);
                    grassSprite.setPosition(x * SIZEX, y * SIZEY);
                    spritesGrass.push_back(grassSprite);
                }
                sf::Vector2f pos = { x * SIZEX, y * SIZEY };
                std::unique_ptr<Boss> bok = std::make_unique<Boss>();
                bok->init(Shared::bokoSprite, pos);
                Shared::bosses.push_back(std::move(bok));
            }

        }
    }

}

void Map::clearVector()
{
    if (!mapData.empty())
        mapData.clear();
    if (!spritesWall.empty())
        spritesWall.clear();
    if (!spritesGrass.empty())
        spritesGrass.clear();
    if (!spritesHerbes.empty())
        spritesHerbes.clear();
    if (!spritesKorogus.empty())
        spritesKorogus.clear();
    if (!spritesCailloux.empty())
        spritesCailloux.clear();
    if (!spritesCaillouxEnMiette.empty())
        spritesCaillouxEnMiette.clear();
    if (!spritesBocaux.empty())
        spritesBocaux.clear();
    if (!spritesFairy.empty())
        spritesFairy.clear();
    if (!spritesReceptacles.empty())
        spritesReceptacles.clear();
    if (!spritesWallDonjon.empty())
        spritesWallDonjon.clear();
    if (!spritesFloorDonjon.empty())
        spritesFloorDonjon.clear();
    if (!doors.empty())
        doors.clear();
    if (!Shared::enemies.empty())
        Shared::enemies.clear();
}

void Map::draw(sf::RenderWindow& window) {
    for (auto& elem : spritesGrass) {
        if (!spritesGrass.empty())
            window.draw(elem);
    }
    for (auto& elem : spritesHerbes) {
        if (!spritesHerbes.empty())
            window.draw(elem);
    }
    for (auto& elem : spritesWall) {
        if (!spritesWall.empty())
            window.draw(elem);
    }
    for (auto& elem : spritesWallDonjon) {
        if (!spritesWallDonjon.empty())
            window.draw(elem);
    }
    for (auto& elem : spritesFloorDonjon) {
        if (!spritesFloorDonjon.empty())
            window.draw(elem);
    }
    for (auto& elem : spritesCailloux) {
        if (!spritesCailloux.empty())
            window.draw(elem);
    }
    for (auto& elem : spritesCaillouxEnMiette) {
        if (!spritesCaillouxEnMiette.empty())
            window.draw(elem);
    }
    for (auto& elem : spritesBocaux) {
        if (!spritesBocaux.empty())
            window.draw(elem);
    }
    for (auto& elem : spritesFairy) {
        if (!spritesFairy.empty())
            window.draw(elem);
    }
    for (auto& elem : spritesReceptacles) {
        if (!spritesReceptacles.empty())
            window.draw(elem);
    }
    
    for (auto& elem : doors) {
        if (!doors.empty())
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
