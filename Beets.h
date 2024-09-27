#ifndef BEETS_H
#define BEETS_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Animation.h"

class Beets {
 private:
  enum class indexAnimation { beetsAnimation, Count };

 public:
  Beets(const sf::Vector2f& position);
  void Draw(sf::RenderTarget& rt) const;
  void Update(float dt, float waitTime);

 private:
  sf::Vector2f position;
  sf::Sprite sprite;
  Animation animations[int(indexAnimation::Count)]; // Create an array of different animations
  indexAnimation currentAnimation = indexAnimation::beetsAnimation;
};

#endif