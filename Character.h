#ifndef CHARACTER_H
#define CHARACTER_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Animation.h"

class Character {
 private:
  enum class indexAnimation { Upwards, UpwardsIdle, Downards, DownwardsIdle, Left, LeftIdle, Right, RightIdle, Count };

 public:
  Character(const sf::Vector2f& position);
  void Draw(sf::RenderTarget& rt) const;
  void SetDirection(const sf::Vector2f& direction);
  void Update(float dt, float waitTime);

 private:
  static constexpr float speed = 100.0f;
  sf::Vector2f position;
  sf::Vector2f velocity = {0.f, 0.f};
  sf::Sprite sprite;
  Animation animations[int(indexAnimation::Count)]; // Create an array of different animations
  indexAnimation currentAnimation = indexAnimation::Upwards;
};

#endif