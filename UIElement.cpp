#include "UIElement.h"

UIElement::UIElement(const std::string& textureFile, const sf::Vector2f& position, const sf::Vector2f& scaleSize, const sf::IntRect& spriteRect) 
:position(position), spriteRect(spriteRect) {
    if (!texture.loadFromFile(textureFile)) {
        throw std::runtime_error("Could not load texture");
    }
    sprite.setTexture(texture);
    sprite.setTextureRect(spriteRect);
    sprite.setPosition(position);
    sprite.setScale(scaleSize.x,scaleSize.y);
}
    
void UIElement::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

sf::FloatRect UIElement::getGlobalBounds() const {
    return sprite.getGlobalBounds();
}