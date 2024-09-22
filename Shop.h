#include "Player.h"

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
        void printItems();
        bool purchaseFertiliser();
        bool purchaseGreenhouse();
        bool purchaseWorkers();
};
#endif