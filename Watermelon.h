#ifndef WATERMELON_H
#define WATERMELON_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Animation.h"

class Watermelon {
 private:
  enum class indexAnimation { watermelonAnimation, Count };

 public:
  Watermelon(const sf::Vector2f& position);
  void Draw(sf::RenderTarget& rt) const;
  void Update(float dt, float waitTime);

 private:
  sf::Vector2f position;
  sf::Sprite sprite;
  Animation animations[int(indexAnimation::Count)]; // Create an array of different animations
  indexAnimation currentAnimation = indexAnimation::watermelonAnimation;
};

#endif