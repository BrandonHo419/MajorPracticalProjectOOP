#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include "InteractiveUIElement.h"

class Button: public InteractiveUIElement {
public:
    Button(const std::string& textureFile, const sf::Vector2f& position, const sf::Vector2f& scaleSize, const sf::IntRect& spriteRect, const sf::IntRect& spriteRectPressed)
    : InteractiveUIElement(textureFile, position, scaleSize, spriteRect, spriteRectPressed) {}; // Sets the texture for static sprites
    virtual bool Pressed(const sf::Vector2f& worldPosition) override;
    virtual void Reset() override;
    virtual void setPressedTexture() override;
};

#endif