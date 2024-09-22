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
        
void Shop::printItems() {
    std::cout << "You have:\n"; 
    if (haveFertiliser == true) {
        std::cout << "Fertiliser\n";
    }

    if (haveGreenhouse == true) {
        std::cout << "A greenhouse\n";
    }

    if (haveWorkers == true) {
        std::cout << "Workers";
    }

    if (haveFertiliser == false && haveGreenhouse == false && haveWorkers == false) {
        std::cout << "Nothing";
    }

}

bool Shop::purchaseFertiliser() {
    if (haveFertiliser == false && getMoney() >= fertiliserPrice){
        setMoney(fertiliserPrice);
        haveFertiliser = true;
        return true;
    } else {
        return false;
    } 
}
        
bool Shop::purchaseGreenhouse() {
    if (haveGreenhouse == false && getMoney() >= greenhousePrice){
        setMoney(greenhousePrice);
        haveGreenhouse = true;
        return true;
    } else {
        return false;
    } 
}
        
bool Shop::purchaseWorkers() {
    if (haveWorkers == false && getMoney() >= workersPrice){
        setMoney(workersPrice);
        haveWorkers = true;
        return true;
    } else {
        return false;
    } 
}