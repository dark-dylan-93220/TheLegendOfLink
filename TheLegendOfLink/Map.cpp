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
    resize(murTexture, murSprite, SIZEX, SIZEY);
    resize(grassTexture, grassSprite, SIZEX, SIZEY);
}

void Map::draw(sf::RenderWindow& window) {
    for (size_t y = 0; y < mapData.size(); ++y) {
        for (size_t x = 0; x < mapData[y].size(); ++x) {
            if (mapData[y][x] == '#') {
                murSprite.setPosition(x * SIZEX, y * SIZEY);
                window.draw(murSprite);
            }
            else {
                grassSprite.setPosition(x * SIZEX, y * SIZEY);
                window.draw(grassSprite);
            }
        }
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
