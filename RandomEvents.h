#include "Requirements.h"
#include "Shop.h"
#ifndef RANDOMEVENTS_H
#define RANDOMEVENTS_H

class RandomEvents : public Shop {
    private:
    Clock c;
    int min;
    int max;
    random_device rd;
    protected:

    public:
    RandomEvents() : c(), min(1), max(10), rd(){}

    void checkRand() {
        if(c.getElapsedTime().asSeconds() >= 120){}
    }

    void genRand(){
        mt19937 getRand(rd());
        uniform_int_distribution<> distrib(min, max);
        int genVal = distrib(getRand);
        deadFarmer();
    }
    void deadFarmer() {
        
        Shop s;
        haveWorkers = false;
        money = money - 514;
       
    };
    
 };

#endif 