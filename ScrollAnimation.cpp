#include "ScrollAnimation.h"

Scroll::Scroll(const sf::Vector2f& position): position(position) {
    // Beets animation
    animations[int(indexAnimation::scroll)] = Animation(0, 32*2, 96, 32, 2, 0);
};

void Scroll::Draw(sf::RenderTarget& rt) const {
    rt.draw(sprite);
};

void Scroll::Update(float dt, float waitTime) {
    animations[int(currentAnimation)].Update(dt, waitTime);
    animations[int(currentAnimation)].ApplyAnimToSprite(sprite);
    sprite.setPosition(position);
}