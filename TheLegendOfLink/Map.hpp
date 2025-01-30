#pragma once

#include "assets.hpp"

class Map {
private:
    Texture murTexture;
    Sprite murSprite;

public:
    bool doorLocked = true;
    vector<string> mapData;
    void loadFromFile(const string& filename);
    void draw(RenderWindow& window);
    bool isObstacle(double x, double y);
    void resize(Texture& texture, Sprite& sprite, float scaleX, float scaleY);

};