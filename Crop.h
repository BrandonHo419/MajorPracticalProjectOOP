#ifndef CROP_H
#define CROP_H
#include <SFML/Graphics.hpp>

#include "Player.h"

class Crop {
 protected:
  float globalModifier = 1;

 public:
  Crop() = default;
  // float cropTemperature;
  // float cropRainfall;
  // float growthTime;
  // float sellValue;
  // float purchasePrice;

  virtual ~Crop() = default;  // Virtual destructor for proper cleanup
  float virtual getGrowthTime() = 0;
  void virtual setGrowthTime(float modifier) = 0;
  virtual void Draw(sf::RenderTarget& rt) = 0;  // Pure virtual function to be
                                                // overridden by specific crops
  virtual void Update(float dt, float waitTime, bool resetFrame,
                      Player& player) = 0;
};

#endif