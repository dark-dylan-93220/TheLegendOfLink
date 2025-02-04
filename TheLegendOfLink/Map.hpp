#pragma once

#include "SFML/Graphics.hpp"
#include <string>
#include <vector>
#include <fstream>

class Map {
private:
    sf::Texture murTexture, grassTexture, herbeTexture, caillouxTexture, caillouxEnMietteTexture, bocauxTexture, fairyTexture, receptacleTexture;

public:
    bool doorLocked = true;
    const float SIZEX = sf::VideoMode::getDesktopMode().height / 13.5f;
    const float SIZEY = sf::VideoMode::getDesktopMode().height / 27.0f;
    std::vector<std::string> mapData;
    std::vector<sf::Sprite> spritesWall;
    std::vector<sf::Sprite> spritesGrass;
    std::vector<sf::Sprite> spritesHerbes;
    std::vector<sf::Sprite> spritesKorogus;
    std::vector<sf::Sprite> spritesCailloux;
    std::vector<sf::Sprite> spritesCaillouxEnMiette;
    std::vector<sf::Sprite> spritesBocaux;
    std::vector<sf::Sprite> spritesFairy;
    std::vector<sf::Sprite> spritesReceptacles;

    bool isObstacle(double x, double y);
    void loadFromFile(const std::string& filename);
    void draw(sf::RenderWindow& window);
    void resize(sf::Texture& texture, sf::Sprite& sprite, const float& scaleX, const float& scaleY);
    void addVector();
};