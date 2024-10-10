#include "Tomatoes.h"

Tomatoes::Tomatoes(const sf::Vector2f& position): position(position), waitTime(6.5f), sellValue(250.f) {
    // Tomatoes animation
    animations[int(indexAnimation::tomatoesAnimation)] = Animation(32*28, 32*11, 32, 32, 4, 2);
};

void Tomatoes::Draw(sf::RenderTarget& rt) {
    rt.draw(sprite);
};

void Tomatoes::Update(float dt, float waitTime, bool resetFrame, Player& player) {
    animations[int(currentAnimation)].Update(dt, waitTime, resetFrame, 2);
    if (animations[int(currentAnimation)].getTime() == 0) {
        player.addMoney(sellValue);
    }
    animations[int(currentAnimation)].ApplyAnimToSprite(sprite);
    sprite.setScale(sf::Vector2f(3, 3));
    sprite.setPosition(position);
}

float Tomatoes::getGrowthTime() {
    return waitTime;
}

void Tomatoes::setGrowthTime(float modifier) {
    this->waitTime = waitTime * modifier;
}