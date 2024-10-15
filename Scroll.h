#ifndef SCROLL_H
#define SCROLL_H
#include "InteractiveUIElement.h"

class Scroll: public InteractiveUIElement{
  public:
    Scroll(const std::string& textureFile, const sf::Vector2f& position, const sf::Vector2f& scaleSize, const sf::IntRect& spriteRect, const sf::IntRect& spriteRectPressed)
    : InteractiveUIElement(textureFile, position, scaleSize, spriteRect, spriteRectPressed) {}; // Sets the texture for static sprites
    virtual bool Pressed(const sf::Vector2f& worldPosition) override {return false;}; // Scroll does not need a pressed feature
    virtual void Reset() override;
    virtual void setPressedTexture() override;
};

#endif