#include "Peas.h"

Peas::Peas(const sf::Vector2f& position): position(position) {
    // Peas animation
    animations[int(indexAnimation::peasAnimation)] = Animation(32*29, 32*11, 32, 32, 4, 2);
};

void Peas::Draw(sf::RenderTarget& rt) const {
    rt.draw(sprite);
};

void Peas::Update(float dt, float waitTime) {
    animations[int(currentAnimation)].Update(dt, waitTime);
    animations[int(currentAnimation)].ApplyAnimToSprite(sprite);
    sprite.setPosition(position);
}