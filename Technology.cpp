#include "Technology.h"


Technology::Technology() : cropTech("NULL"), moneyTech("NULL"), cropModifier(1), moneyModifier(1), baseModifier(1){}; // Starts at 1 (for multiplier of 1)

string Technology::getCropTech() {
    return cropTech;
};

string Technology::getMoneyTech() {
    return moneyTech;
};

int Technology::getCropModifier() {
    return cropModifier;
};

int Technology::getMoneyModifier() {
    return moneyModifier;
};


Technology::~Technology(){}; //deconstructs

