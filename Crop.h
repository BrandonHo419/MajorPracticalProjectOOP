#ifndef CROP_H
#define CROP_H
#include <SFML/Graphics.hpp>

#include "Player.h"

class Crop {
 public:
  Crop() = default;
  virtual ~Crop() = default;          // Virtual destructor for proper cleanup
  virtual float getGrowthTime() = 0;  // Return growth time for each crop
  virtual void setGrowthTime(
      float modifier) = 0;  // Change the growth of each time
  virtual void Draw(sf::RenderTarget& rt) = 0;  // Draw each crop
  virtual void Update(
      float dt, float waitTime, bool resetFrame,
      Player& player) = 0;           // Update animation and add money to player
  virtual float getSellValue() = 0;  // Return sellValue
  virtual void setSellValue(float modifier) = 0;  // Change the sell Value
  virtual std::string getCropType() = 0;          // Return what crop it is

 protected:
  float globalModifier = 0.0f;
};

#endif