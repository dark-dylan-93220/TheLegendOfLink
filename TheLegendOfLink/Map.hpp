#pragma once

#include "SFML/Graphics.hpp"
#include <string>
#include <vector>
#include <fstream>

class Map {
private:
    sf::Texture grassTexture;
    sf::Sprite grassSprite;
    sf::Texture murTexture;
    sf::Sprite murSprite;

public:
    bool doorLocked = true;
    const float SIZEX = sf::VideoMode::getDesktopMode().height / 13.5f;
    const float SIZEY = sf::VideoMode::getDesktopMode().height / 27.0f;
    std::vector<std::string> mapData;

public:
    bool isObstacle(double x, double y);
    void loadFromFile(const std::string& filename);
    void draw(sf::RenderWindow& window);
    void resize(sf::Texture& texture, sf::Sprite& sprite, const float& scaleX, const float& scaleY);

};