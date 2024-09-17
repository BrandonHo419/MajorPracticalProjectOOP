#include "Avocado.h"

avocado::avocado(){};

void avocado::setGrowthSpeed() {
    growthSpeed = 3.0; // When technology gets implemented. Add an additional modifier (whether %, * or +)
}; // also it doesn't require this-> because it knows we are working with this class member

void avocado::setPlantSpeed() {
    plantSpeed = 5.0;
};

void avocado::setThirstRate() {
    thirstRate = 3.0;
};

avocado::~avocado(){};  