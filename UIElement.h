#ifndef UIELEMENT_H
#define UIELEMENT_H
#include <SFML/Graphics.hpp>
#include <string>

class UIElement {
public:
    UIElement(const std::string& textureFile, const sf::Vector2f& position, const sf::Vector2f& scaleSize, const sf::IntRect& spriteRect); // Sets the texture for static sprites
    virtual void draw(sf::RenderWindow& window);  // Draws the sprite
    virtual sf::FloatRect getGlobalBounds() const; // Retrieves globalBounds()

protected:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f position;
    sf::IntRect spriteRect;
};

#endif
