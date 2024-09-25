#include "Shop.h"
#include <iostream>


Shop::Shop():Player() {
    haveFertiliser = false;
    fertiliser = 0.05;
    fertiliserPrice = 500;
    haveGreenhouse = false;
    greenhouse = 0.05;
    greenhousePrice = 500;
    haveWorkers = false;
    workersPrice = 500;
}
        
std::string Shop::printItems() {
    std::string items = "";
    items = items + "You have:\n"; 
    if (haveFertiliser == true) {
        items = items + "Fertiliser\n";
    }

    if (haveGreenhouse == true) {
        items = items + "A greenhouse\n";
    }

    if (haveWorkers == true) {
        items = items + "Workers\n";
    }

    if (haveFertiliser == false && haveGreenhouse == false && haveWorkers == false) {
        items = items + "Nothing\n";
    }

    return items;
}

bool Shop::purchaseFertiliser() {
    if (haveFertiliser == true) {
        return true;
    }
    else if (getMoney() >= fertiliserPrice) {
        setMoney(fertiliserPrice);
        haveFertiliser = true;
        return true;
    } 
    else {
        return false;
    }
}
        
bool Shop::purchaseGreenhouse() {
    if (haveGreenhouse == true) {
        return true;
    } else if (getMoney() >= greenhousePrice){
        setMoney(greenhousePrice);
        haveGreenhouse = true;
        return true;
    }  
    else {
        return false;
    }
}
        
bool Shop::purchaseWorkers() {
    if (haveWorkers == true) {
        return true;
    } else if (getMoney() >= workersPrice) {
        setMoney(workersPrice);
        haveWorkers = true;
        return true;
    } else {
        return false;
    }
}

// this has become very irrelevant