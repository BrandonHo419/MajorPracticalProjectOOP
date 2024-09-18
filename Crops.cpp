#include "Crops.h"

Crops::Crops() : speed(0.0) {};

float Crops::getSpeed() {
    return speed;
};



bool Crops::isGrown() {
    // if(timeElapsed = growthRate) {
        return true;
    // }
}
Crops::~Crops(){}; 


//create seperate classes for each crop