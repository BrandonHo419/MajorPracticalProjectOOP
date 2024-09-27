#include "Tomatoes.h"

Tomatoes::Tomatoes(const sf::Vector2f& position): position(position) {
    // Tomatoes animation
    animations[int(indexAnimation::tomatoesAnimation)] = Animation(32*28, 32*11, 32, 32, 4, 2);
};

void Tomatoes::Draw(sf::RenderTarget& rt) const {
    rt.draw(sprite);
};

void Tomatoes::Update(float dt, float waitTime) {
    animations[int(currentAnimation)].Update(dt, waitTime);
    animations[int(currentAnimation)].ApplyAnimToSprite(sprite);
    sprite.setPosition(position);
}