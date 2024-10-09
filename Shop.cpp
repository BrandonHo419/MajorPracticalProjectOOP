#include "Shop.h"
#include <iostream>


Shop::Shop():Player() {
    // Initialise shop variables 
    haveFertiliser = false;
    fertiliserLevel = 0;
    fertiliser = 0.05;
    fertiliserPrice = 500;
    haveGreenhouse = false;
    greenhouseLevel = 0;
    greenhouse = 0.05;
    greenhousePrice = 500;
    haveWorkers = false;
    workersLevel = 0;
    numOfWorkers = 1;
    workersPrice = 500;
    isPressed = false; // Checks if buttons have been pressed (used for graphics)
    enoughMoney = true;
}

// Returns a string of all items (and the level) the player has        
std::string Shop::printItems(bool enoughmoney, int fertLevel, int greenlevel, int workerslevel) {
    std::string items = ""; // Initalise string
    items = items + "You have:\n"; 

    // Checks whether use has each shop item, if so adds to string
    if (haveFertiliser == true) {
        std::string level = std::to_string(fertLevel); // Converts level (int) to string so it can be added to items
        items = items + "Fertiliser Level: " + level + "\n";
    }

    if (haveGreenhouse == true) {
        std::string level = std::to_string(greenlevel);
        items = items + "A greenhouse Level: " + level + "\n";
    }

    if (haveWorkers == true) {
        std::string level = std::to_string(workersLevel);
        items = items + "Workers " + level + "\n";
    }

    if (enoughmoney == false) {
        items = items + "Not enough money for item or maxed item out (3)\n";
    }

    if (haveFertiliser == false && haveGreenhouse == false && haveWorkers == false) {
        items = items + "Nothing\n";
    }
    return items; // Returns string
}

// Buy (or upgrade) fertiliser
bool Shop::purchaseFertiliser() {
    // If already owned upgrades fertiliser if they haven't maxed item and have enough money
    if (haveFertiliser == true) {
        if (fertiliserLevel < 3 && getMoney() >= fertiliserPrice) {
            fertiliserLevel++; // Increase level
            setMoney(fertiliserPrice); // Uses setMoney function from player class to deduct money for upgrade
            fertiliser *= 2; // Double the effect of fertiliser 
            return true;
        } else {
            return false; 
        }
    }
    // Buy fertilsier
    else if (getMoney() >= fertiliserPrice) {
        setMoney(fertiliserPrice);
        fertiliserLevel++;
        haveFertiliser = true;
        return true;
    } 
    else {
        return false;
    }
}

int Shop::getFertiliserLevel() {
    return fertiliserLevel;
}

// Buy (or upgrade) greenhouse
bool Shop::purchaseGreenhouse() {
    // If already owned, upgrades greenhouse if they haven't maxed item and have enough money
    if (haveGreenhouse == true) {
        if (greenhouseLevel < 3 && getMoney() >= greenhousePrice) {
            greenhouseLevel++; // Increase level
            setMoney(greenhousePrice); // Deduct money for upgrade
            greenhouse *= 2; // Double the effect of the greenhouse
            return true;
        } else {
            return false; // Return false if money is insufficient or max level reached
        }
    }
    // Buy greenhouse
    else if (getMoney() >= greenhousePrice) {
        setMoney(greenhousePrice); // Deduct money for the purchase
        greenhouseLevel++;
        haveGreenhouse = true; 
        return true;
    }  
    else {
        return false; // Return false if not enough money
    }
}


int Shop::getGreenhouseLevel() {
    return greenhouseLevel;
}

// Buy or or upgrade workers   
bool Shop::purchaseWorkers() {
    // If already owned, upgrades workers if they haven't maxed item and have enough money
    if (haveWorkers == true) {
        if (workersLevel < 3 && getMoney() >= workersPrice) {
            workersLevel++; // Increase level
            setMoney(workersPrice); // Deduct money
            numOfWorkers++; // Increase the number of workers
            return true;
        } else {
            return false;
        }
    // Buy worker if player has enough money
    } else if (getMoney() >= workersPrice) {
        setMoney(workersPrice); // Deduct money
        workersLevel++;
        haveWorkers = true;
        return true;
    } else {
        return false; // Return false if not enough money or max level
    }
}

int Shop::getWorkersLevel() {
    return workersLevel;
}

void Shop::setIsPressed(bool pushed) {
    isPressed = pushed;
}

bool Shop::checkIsPressed() {
    return isPressed;
}

 void Shop::setEnoughMoney(bool set) {
    enoughMoney = set;
 }
        
bool Shop::checkEnoughMoney() {
    return enoughMoney;
}

Shop::~Shop(){};