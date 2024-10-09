#include "Requirements.h"
#include "Shop.h"
#include "loadRect.h"
#ifndef RANDOMEVENTS_H
#define RANDOMEVENTS_H

class RandomEvents : public Shop {
    private:
    Clock c;
    int min;
    int max;
    random_device rd;
    
    Font font;
    

    
    protected:

    public:

    bool eventOne = false;
    bool eventTwo = false;
    bool eventThree = false;
    bool eventFour = false;
    bool eventFive = false;

    Text message1;

    RandomEvents() : c(), min(1), max(5), rd(){}


    void genRand(){
        mt19937 getRand(rd());
        uniform_int_distribution<> distrib(min, max);
        int genVal = distrib(getRand);
        if(genVal == 1) {
            
        }
    }

    void checkRand() {
        if(c.getElapsedTime().asSeconds() >= 120){
            genRand();
        } else {
            checkRand();
    }
    }

    

    Font getFont() {
        font.loadFromFile("Albertson.ttf");
        return font;
    }
    void deadFarmer() { 
        eventOne = true;
        getFont();
        message1.setString("A rival competitor hired Agent 47 and he BRUTALLY assasinated all of your farmers and stole some money");
        
        message1.setFillColor(Color::White);
        message1.setFont(font);
        message1.setCharacterSize(21);
        
        Shop s;
        haveWorkers = false;
        numOfWorkers = 0;
        workersLevel = 0;
        money = money - 520;
        
    };
    
 };

#endif 