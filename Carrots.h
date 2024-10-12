#ifndef CARROTS_H
#define CARROTS_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Crop.h"
#include "Animation.h"

class Carrots: public Crop {
 private:
  enum class indexAnimation {carrotsAnimation, Count};

 public:
  Carrots(const sf::Vector2f& position, float waitTime, float sellValue);
  virtual void Draw(sf::RenderTarget& rt) override;
  virtual void Update(float dt, float waitTime, bool resetFrame, Player& player) override;
  float virtual getGrowthTime() override;
  void virtual setGrowthTime(float waitTime) override;
  virtual float getSellValue() override;
  virtual void setSellValue(float sellValue) override;
  virtual std::string getCropType() override;

 private: 
  sf::Vector2f position;
  sf::Sprite sprite;
  Animation animations[int(indexAnimation::Count)]; // Create an array of different animations
  indexAnimation currentAnimation = indexAnimation::carrotsAnimation;
  float waitTime;
  float sellValue;
};

#endif