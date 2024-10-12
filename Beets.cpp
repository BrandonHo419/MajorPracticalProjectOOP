#include "Beets.h"

Beets::Beets(const sf::Vector2f& position, float waitTime, float SellValue): position(position), waitTime(waitTime), sellValue(sellValue) {
    // Beets animation
    animations[int(indexAnimation::beetsAnimation)] = Animation(32*9, 32, 32, 32, 4, 2);
};

void Beets::Draw(sf::RenderTarget& rt) {
    rt.draw(sprite);
};

void Beets::Update(float dt, float waitTime, bool resetFrame, Player& player) {
    animations[int(currentAnimation)].Update(dt, waitTime, resetFrame, 2);
    if (animations[int(currentAnimation)].getTime() == 0) {
        player.addMoney(sellValue);
    }
    animations[int(currentAnimation)].ApplyAnimToSprite(sprite);
    sprite.setScale(sf::Vector2f(3, 3));
    sprite.setPosition(position);
}

float Beets::getGrowthTime() {
    return waitTime;
}

void Beets::setGrowthTime(float waitTime) {
    this->waitTime = waitTime;
}

void Beets::setSellValue(float sellValue) {
    this->sellValue = sellValue;
}

float Beets::getSellValue() {
    return sellValue;
}

std::string Beets::getCropType() {
    return "Beets";
}