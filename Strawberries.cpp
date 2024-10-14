#include "Strawberries.h"

Strawberries::Strawberries(const sf::Vector2f& position, float waitTime,
                           float sellValue)
    : position(position),
      waitTime(waitTime * globalModifier),
      sellValue(sellValue) {
  // Strawberries Animation
  animations[int(indexAnimation::strawberriesAnimation)] =
      Animation(32 * 20, 32 * 11, 32, 32, 4, 2);
};

void Strawberries::Draw(sf::RenderTarget& rt) { rt.draw(sprite); };

void Strawberries::Update(float dt, float waitTime, bool resetFrame,
                          Player& player) {
  animations[int(currentAnimation)].Update(dt, waitTime, resetFrame, 2);
  if (animations[int(currentAnimation)].getTime() == 0) {
    player.addMoney(sellValue);
  }
  animations[int(currentAnimation)].ApplyAnimToSprite(sprite);
  sprite.setScale(sf::Vector2f(3, 3));
  sprite.setPosition(position);
}

float Strawberries::getGrowthTime() { return waitTime; }

void Strawberries::setGrowthTime(float waitTime) { this->waitTime = waitTime; }

float Strawberries::getSellValue() { return sellValue; }

void Strawberries::setSellValue(float sellValue) {
  this->sellValue = sellValue;
}

std::string Strawberries::getCropType() { return "Strawberries"; }