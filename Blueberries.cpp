#include "Blueberries.h"

Blueberries::Blueberries(const sf::Vector2f& position, float waitTime,
                         float SellValue)
    : position(position),
      waitTime(waitTime * globalModifier),
      sellValue(sellValue) {
  // Blueberries animation
  animations[int(indexAnimation::blueberriesAnimation)] =
      Animation(32 * 23, 32 * 11, 32, 32, 4, 2);
};

void Blueberries::Draw(sf::RenderTarget& rt) { rt.draw(sprite); };

void Blueberries::Update(float dt, float waitTime, bool resetFrame,
                         Player& player) {
  animations[int(currentAnimation)].Update(dt, waitTime, resetFrame, 2);
  if (animations[int(currentAnimation)].getTime() == 0) {
    player.addMoney(sellValue);
  }
  animations[int(currentAnimation)].ApplyAnimToSprite(sprite);
  sprite.setScale(sf::Vector2f(3, 3));
  sprite.setPosition(position);
}

float Blueberries::getGrowthTime() { return waitTime; }

void Blueberries::setGrowthTime(float waitTime) { this->waitTime = waitTime; }

void Blueberries::setSellValue(float sellValue) { this->sellValue = sellValue; }

float Blueberries::getSellValue() { return sellValue; }

std::string Blueberries::getCropType() { return "Blueberries"; }