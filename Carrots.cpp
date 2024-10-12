#include "Carrots.h"

Carrots::Carrots(const sf::Vector2f& position)
    : position(position), waitTime(4.5f), sellValue(100.f * globalModifier) {
  // Carrots animation
  animations[int(indexAnimation::carrotsAnimation)] =
      Animation(32 * 6, 32, 32, 32, 4, 2);
};

void Carrots::Draw(sf::RenderTarget& rt) { rt.draw(sprite); };

void Carrots::Update(float dt, float waitTime, bool resetFrame,
                     Player& player) {
  animations[int(currentAnimation)].Update(dt, waitTime, resetFrame, 2);
  if (animations[int(currentAnimation)].getTime() == 0) {
    player.addMoney(sellValue);
  }
  animations[int(currentAnimation)].ApplyAnimToSprite(sprite);
  sprite.setScale(sf::Vector2f(3, 3));
  sprite.setPosition(position);
}

float Carrots::getGrowthTime() { return waitTime; }

void Carrots::setGrowthTime(float modifier) {
  this->waitTime = waitTime * modifier;
}