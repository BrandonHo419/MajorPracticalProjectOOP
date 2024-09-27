#include "Coin.h"

Coin::Coin(const sf::Vector2f& position): position(position) {
    // Coin animation
    animations[int(indexAnimation::coinAnimation)] = Animation(0, 0, 32, 32, 8, 1);
};

void Coin::Draw(sf::RenderTarget& rt) const {
    rt.draw(sprite);
};

void Coin::Update(float dt, float waitTime) {
    animations[int(currentAnimation)].Update(dt, waitTime);
    animations[int(currentAnimation)].ApplyAnimToSprite(sprite);
    sprite.setPosition(position);
}