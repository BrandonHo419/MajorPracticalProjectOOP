#include "Asparagus.h"

Asparagus::Asparagus(const sf::Vector2f& position): position(position) {
    // Beets animation
    animations[int(indexAnimation::asparagusAnimation)] = Animation(0, 32*11, 32, 32, 4, 2);
};

void Asparagus::Draw(sf::RenderTarget& rt) const {
    rt.draw(sprite);
};

void Asparagus::Update(float dt, float waitTime) {
    animations[int(currentAnimation)].Update(dt, waitTime);
    animations[int(currentAnimation)].ApplyAnimToSprite(sprite);
    sprite.setPosition(position);
}