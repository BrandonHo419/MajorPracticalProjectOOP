#include "Shop.h"
#include "Player.h"
#include <iostream>
#include <string>

int main() {
    Shop Plantings;
    std::cout << Plantings.getMoney();
    Plantings.printItems();
    
    if (Plantings.purchaseFertiliser() == false) {
        std::cout << "\n" << "Insufficient funds or already purchased";
    }
    std::cout << "\n" << Plantings.getMoney();

    
    if (Plantings.purchaseGreenhouse() == false) {
        std::cout << "\n" << "Insufficient funds or already purchased";
    }
    std::cout << "\n" << Plantings.getMoney() << "\n";

    if (Plantings.purchaseWorkers() == false) {
        std::cout << "\n" << "Insufficient funds or already purchased";
    }
    std::cout << Plantings.getMoney();
}
