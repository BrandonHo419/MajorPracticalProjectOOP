#include "Crops.h"

Crops::Crops() : growthSpeed(0.0), plantSpeed(0.0), thirstRate(0.0){};

float Crops::getGrowthSpeed() {
    return growthSpeed;
};

float Crops::getPlantSpeed() {
    return plantSpeed;
}

float Crops::getThirstRate() {
    return thirstRate;
};

bool Crops::isGrown() {
    // if(timeElapsed = growthRate) {
        return true;
    // }
}
Crops::~Crops(){}; 


//create seperate classes for each crop