#pragma once

#include "SFML/Graphics.hpp"
#include <string>
#include <vector>
#include <fstream>

class Map {
private:
    sf::Texture murTexture, grassTexture, korogusTexture, herbeTexture, wallDonjonTexture, floorDonjonTexture, porteTexture;

public:
    bool doorLocked = true;
    const float SIZEX = sf::VideoMode::getDesktopMode().height / 13.5f;
    const float SIZEY = sf::VideoMode::getDesktopMode().height / 27.0f;
    std::vector<std::string> mapData;
    std::vector<std::string> mapDonjonData;
    std::vector<sf::Sprite> spritesWall;
    std::vector<sf::Sprite> spritesGrass;
    std::vector<sf::Sprite> spritesHerbes;
    std::vector<sf::Sprite> spritesKorogus;
    std::vector<sf::Sprite> spritesWallDonjon;
    std::vector<sf::Sprite> spritesFloorDonjon;
    std::vector<sf::Sprite> spritesPorte;
public:
    bool isObstacle(double x, double y);
    void loadFromFile(const std::string& filename);
    void draw(sf::RenderWindow& window);
    void resize(sf::Texture& texture, sf::Sprite& sprite, const float& scaleX, const float& scaleY);
    void addVector();

};