#ifndef CROP_H
#define CROP_H
#include <SFML/Graphics.hpp>
#include "Player.h"

class Crop {
    public:
    Crop() = default;
    virtual ~Crop() = default;  // Virtual destructor for proper cleanup
    virtual float getGrowthTime() = 0;
    virtual void setGrowthTime(float modifier) = 0;
    virtual void Draw(sf::RenderTarget& rt) = 0;  // Pure virtual function to be overridden by specific crops
    virtual void Update(float dt, float waitTime, bool resetFrame, Player& player) = 0;
    virtual float getSellValue() = 0;
    virtual void setSellValue(float modifier) = 0;
    virtual std::string getCropType() = 0;
};

#endif