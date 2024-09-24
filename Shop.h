#include "Player.h"
#include <string>
#ifndef SHOP_H
#define SHOP_H


class Shop : public Player {
    private:
        bool haveFertiliser;
        float fertiliser;
        float fertiliserPrice;
        bool haveGreenhouse;
        float greenhouse;
        float greenhousePrice;
        bool haveWorkers;
        float workersPrice;
    public:
        Shop();
        std::string printItems();
        bool purchaseFertiliser();
        bool purchaseGreenhouse();
        bool purchaseWorkers();
};
#endif