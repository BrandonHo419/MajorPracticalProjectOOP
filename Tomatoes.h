#ifndef TOMATOES_H
#define TOMATOES_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Animation.h"

class Tomatoes {
 private:
  enum class indexAnimation {tomatoesAnimation, Count};

 public:
  Tomatoes(const sf::Vector2f& position);
  void Draw(sf::RenderTarget& rt) const;
  void Update(float dt, float waitTime);

 private:
  sf::Vector2f position;
  sf::Sprite sprite;
  Animation animations[int(indexAnimation::Count)]; // Create an array of different animations
  indexAnimation currentAnimation = indexAnimation::tomatoesAnimation;
};

#endif