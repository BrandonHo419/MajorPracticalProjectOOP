#ifndef INTERACTIVEUIELEMENT_H
#define INTERACTIVEUIELEMENT_H
#include <SFML/Graphics.hpp>
#include "UIElement.h"

class InteractiveUIElement: public UIElement {
public:
    InteractiveUIElement(const std::string& textureFile, const sf::Vector2f& position, const sf::Vector2f& scaleSize, const sf::IntRect& spriteRect, const sf::IntRect& spriteRectPressed)
    : UIElement(textureFile, position, scaleSize, spriteRect), spriteRectPressed(spriteRectPressed) {}; // Sets the texture for static sprites
    virtual bool Pressed(const sf::Vector2f& worldMPosition) = 0; // Pure virtual for checking if the interactive element is pressed
    virtual void Reset() = 0; // Reset the texture when its not pressed
    virtual void setPressedTexture() = 0; // Set the new texture when it is pressed
protected:
    sf::IntRect spriteRectPressed;
};

#endif
