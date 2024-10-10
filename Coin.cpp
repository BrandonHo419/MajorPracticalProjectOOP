#include "Coin.h"

Coin::Coin(const sf::Vector2f& position): position(position) {
    // Coin animation
    animations[int(indexAnimation::coinAnimation)] = Animation(0, 0, 32, 24, 8, 1);
};

void Coin::Draw(sf::RenderTarget& rt) const {
    rt.draw(sprite);
};

void Coin::Update(float dt, float waitTime, bool resetFrame) {
    animations[int(currentAnimation)].Update(dt, waitTime, resetFrame, 1);
    animations[int(currentAnimation)].ApplyAnimToSprite(sprite);
    sprite.setScale(sf::Vector2f(4, 4));
    sprite.setPosition(position);
}