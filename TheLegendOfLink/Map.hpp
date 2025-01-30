#pragma once

#include "SFML/Graphics.hpp"
#include <string>
#include <vector>
#include <fstream>

class Map {
private:
    sf::Texture murTexture;
    sf::Sprite murSprite;

public:
    bool doorLocked = true;
    const int SIZEX = 40;
    const int SIZEY = 40;
    std::vector<std::string> mapData;

public:
    bool isObstacle(double x, double y);
    void loadFromFile(const std::string& filename);
    void draw(sf::RenderWindow& window);
    void resize(sf::Texture& texture, sf::Sprite& sprite, const float& scaleX, const float& scaleY);

};