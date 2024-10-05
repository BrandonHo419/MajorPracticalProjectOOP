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
        
        float workersPrice;

    protected:

    bool haveWorkers;
    public:
        Shop(){
            haveFertiliser = false;
            fertiliser = 0.05;
            fertiliserPrice = 500;
            haveGreenhouse = false;
            greenhouse = 0.05;
            greenhousePrice = 500;
            haveWorkers = false;
            workersPrice = 500;
        }
        std::string printItems() {
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
        bool purchaseFertiliser() {
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
        };
        bool purchaseGreenhouse() {
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
        bool purchaseWorkers() {
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
};
#endif