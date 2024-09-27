#include "Watermelon.h"

Watermelon::Watermelon(const sf::Vector2f& position): position(position) {
    // Watermelon animation
    animations[int(indexAnimation::watermelonAnimation)] = Animation(32*23, 32, 32, 32, 4, 2);
};

void Watermelon::Draw(sf::RenderTarget& rt) const {
    rt.draw(sprite);
};

void Watermelon::Update(float dt, float waitTime) {
    animations[int(currentAnimation)].Update(dt, waitTime);
    animations[int(currentAnimation)].ApplyAnimToSprite(sprite);
    sprite.setPosition(position);
}