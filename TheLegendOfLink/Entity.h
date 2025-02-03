#pragma once
#include "SFML/Graphics.hpp"
class Entity
{
protected:
    sf::Sprite spriteEntity;
    float speed;

public:
    sf::FloatRect getBounds() const {
        return spriteEntity.getGlobalBounds();  // Récupère la hitbox de l'entité
    }
    bool intersects(const Entity& other) const {
        return getBounds().intersects(other.getBounds());  // Regarde si il y a une collision
    }
public:
    virtual ~Entity() = default;
    virtual void init(sf::Sprite& sprite, sf::Vector2f& position) = 0;
    virtual void update(float& deltaTime,sf::Event& event) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
};

