#include "Beets.h"

Beets::Beets(const sf::Vector2f& position): position(position) {
    // Beets animation
    animations[int(indexAnimation::beetsAnimation)] = Animation(32*9, 32, 32, 32, 4, 2);
};

void Beets::Draw(sf::RenderTarget& rt) const {
    rt.draw(sprite);
};

void Beets::Update(float dt, float waitTime) {
    animations[int(currentAnimation)].Update(dt, waitTime);
    animations[int(currentAnimation)].ApplyAnimToSprite(sprite);
    sprite.setPosition(position);
}