#include "Map.hpp"

void Map::resize(Texture& texture, Sprite& sprite, float scaleX, float scaleY) {
    sprite.setTexture(texture);
    float scaleFinaleX = scaleX / texture.getSize().x;
    float scaleFinaleY = scaleY / texture.getSize().y;
    sprite.setScale(scaleFinaleX, scaleFinaleY);
}

void Map::loadFromFile(const string& filename) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        mapData.push_back(line);
    }

    murTexture.loadFromFile("assets/tiles/wall.png");
    resize(murTexture, murSprite, SIZEX, SIZEY);
}

void Map::draw(RenderWindow& window) {
    for (size_t y = 0; y < mapData.size(); ++y) {
        for (size_t x = 0; x < mapData[y].size(); ++x) {
            if (mapData[y][x] == '#') {
                murSprite.setPosition(x * SIZEX, y * SIZEY);
                window.draw(murSprite);
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
