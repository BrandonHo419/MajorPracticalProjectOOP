#include "Tomatoes.h"

Tomatoes::Tomatoes(const sf::Vector2f& position, float waitTime,
                   float SellValue)
    : position(position),
      waitTime(waitTime * globalModifier),
      sellValue(sellValue) {
  // Tomatoes animation
  animations[int(indexAnimation::tomatoesAnimation)] =
      Animation(32 * 28, 32 * 11, 32, 32, 4, 2);
};

void Tomatoes::Draw(sf::RenderTarget& rt) { rt.draw(sprite); };

void Tomatoes::Update(float dt, float waitTime, bool resetFrame,
                      Player& player) {
  animations[int(currentAnimation)].Update(dt, waitTime, resetFrame, 2);
  if (animations[int(currentAnimation)].getTime() == 0) {
    player.addMoney(sellValue);
  }
  animations[int(currentAnimation)].ApplyAnimToSprite(sprite);
  sprite.setScale(sf::Vector2f(3, 3));
  sprite.setPosition(position);
}

float Tomatoes::getGrowthTime() { return waitTime; }

void Tomatoes::setGrowthTime(float waitTime) { this->waitTime = waitTime; }

void Tomatoes::setSellValue(float sellValue) { this->sellValue = sellValue; }

float Tomatoes::getSellValue() { return sellValue; }

std::string Tomatoes::getCropType() { return "Tomatoes"; }