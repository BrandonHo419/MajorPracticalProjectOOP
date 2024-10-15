#ifndef FENCES_H
#define FENCES_H
#include <SFML/Graphics.hpp>
#include "UIElement.h"

class Fences: public UIElement {
public:
    Fences(const std::string& textureFile, const sf::Vector2f& position, const sf::Vector2f& scaleSize, const sf::IntRect& spriteRect); // Sets the texture for static sprites
    virtual void draw(sf::RenderWindow& window) override;  // Draws the fence

protected:
    std::vector<sf::Sprite> fences;
};

#endif