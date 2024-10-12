#include "Beets.h"

Beets::Beets(const sf::Vector2f& position)
    : position(position), waitTime(5.5f), sellValue(150.f * globalModifier) {
  // Beets animation
  animations[int(indexAnimation::beetsAnimation)] =
      Animation(32 * 9, 32, 32, 32, 4, 2);
};

void Beets::Draw(sf::RenderTarget& rt) { rt.draw(sprite); };

void Beets::Update(float dt, float waitTime, bool resetFrame, Player& player) {
  animations[int(currentAnimation)].Update(dt, waitTime, resetFrame, 2);
  if (animations[int(currentAnimation)].getTime() == 0) {
    player.addMoney(sellValue);
  }
  animations[int(currentAnimation)].ApplyAnimToSprite(sprite);
  sprite.setScale(sf::Vector2f(3, 3));
  sprite.setPosition(position);
}

float Beets::getGrowthTime() { return waitTime; }

void Beets::setGrowthTime(float modifier) {
  this->waitTime = waitTime * modifier;
}