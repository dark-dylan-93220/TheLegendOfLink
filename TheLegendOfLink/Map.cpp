#include "Map.hpp"

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
        }
    }
}

void Map::draw(sf::RenderWindow& window) {
    for (auto elem : spritesGrass) {
        window.draw(elem);
    }
    for (auto elem : spritesWall) {
        window.draw(elem);
    }
}

bool Map::isObstacle(double x, double y) {
    int tileX = x / (double)SIZEX;
    int tileY = y / (double)SIZEY;

    if (mapData[tileY][tileX] == '#' || mapData[tileY][tileX] == 'D' || mapData[tileY][tileX] == 'd') {
        return true;
    }
    return false;
}
