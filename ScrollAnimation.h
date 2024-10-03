#include "Requirements.h"
#include "Animation.h"
#ifndef SCROLLANIMATION_H
#define SCROLLANIMATION_H


class Scroll{
 private:
  enum class indexAnimation { scroll, Count };

 public:
  Scroll(const sf::Vector2f& position);
  void Draw(sf::RenderTarget& rt) const;
  void Update(float dt, float waitTime);

 private:
  sf::Vector2f position;
  sf::Sprite sprite;
  Animation animations[int(indexAnimation::Count)]; // Create an array of different animations
  indexAnimation currentAnimation = indexAnimation::scroll;
};

#endif