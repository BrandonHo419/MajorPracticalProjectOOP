#ifndef BEETS_H
#define BEETS_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Crop.h"
#include "Animation.h"

class Beets: public Crop {
 private:
  enum class indexAnimation {beetsAnimation, Count};

 public:
  Beets(const sf::Vector2f& position);
  virtual void Draw(sf::RenderTarget& rt) override;
  virtual void Update(float dt, float waitTime, bool resetFrame, Player& player) override;
  float virtual getGrowthTime() override;
  void virtual setGrowthTime(float modifier) override;

 private:
  sf::Vector2f position;
  sf::Sprite sprite;
  Animation animations[int(indexAnimation::Count)]; // Create an array of different animations
  indexAnimation currentAnimation = indexAnimation::beetsAnimation;
  float waitTime;
  float sellValue;
};

#endif