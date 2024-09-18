#include "cherryTech.h"

cherryTech::cherryTech() : growthSpeed(1){};


void cherryTech::setModifier() {
    growthSpeed = growthSpeed +(baseModifier * cropModifier);
}

float cherryTech::getSpeed() {
    return growthSpeed;
}

cherryTech::~cherryTech(){};