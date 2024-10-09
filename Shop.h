#include "Player.h"
#include <string>
#include <SFML/Graphics.hpp>
#ifndef SHOP_H
#define SHOP_H


class Shop : public Player {
    private:
        bool isPressed;
        bool enoughMoney;
        bool haveFertiliser;
        int fertiliserLevel;
        float fertiliser;
        float fertiliserPrice;
        bool haveGreenhouse;
        int greenhouseLevel;
        float greenhouse;
        float greenhousePrice;
        float workersPrice;

        protected: // Need in protected class because I inherit.
        bool haveWorkers;
        int workersLevel;
        int numOfWorkers;
    public:
        Shop();
        std::string printItems(bool enoughMoney, int fertLevel, int greenLevel, int workersLevel);
        bool purchaseFertiliser();
        int getFertiliserLevel();
        bool purchaseGreenhouse();
        int getGreenhouseLevel();
        bool purchaseWorkers();
        int getWorkersLevel();
        void setIsPressed(bool set);
        bool checkIsPressed();
        void setEnoughMoney(bool set);
        bool checkEnoughMoney();
        ~Shop();
};
#endif