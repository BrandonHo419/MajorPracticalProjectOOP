#include "Button.h"
#include <iostream>
bool Button::Pressed(const sf::Vector2f& worldPosition) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sprite.getGlobalBounds().contains(worldPosition)) {
        //std::cout << "Button Pressed" << std::endl;
        return true;
    }
    return false;
}

void Button::Reset() {
    sprite.setTextureRect(spriteRect);
}

void Button::setPressedTexture() {
    sprite.setTextureRect(spriteRectPressed);
}