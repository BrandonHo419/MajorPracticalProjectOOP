#include "Requirements.h"
#ifndef OLDPLANTGROWTH_H
#define OLDPLANTGROWTH_H

using namespace std;
using namespace sf;

class plantGrowth {
    private:

    protected:

    public:

    
};

void avoGrowth(float& funds, string& fundsInString, Text& money, RenderWindow& win, Clock& avoClock, bool& isAvo, float& avoModifier) {
    // lets say avo growth time is 25s
    float profit = 100;
    int y = 1;
        
        float currentProgress = avoClock.getElapsedTime().asMilliseconds();
        
        if(currentProgress >= avoModifier*5) {
        funds = funds+profit;
        fundsInString = to_string(funds);
        money.setString(fundsInString);
        avoClock.restart();
        win.draw(money);
        win.display();
        isAvo = false;
        avoClock.restart();
       
        }
        win.display();
    
   
};

void beetGrowth(float& funds, string& fundsInString, Text& money, RenderWindow& win,  Clock&beetClock, float&beetModifier, bool&isBeet) {
    float profit = 50;
    int x = 0;


    
    float currentProgress = beetClock.getElapsedTime().asMilliseconds();
        
        
        if(currentProgress >= beetModifier*5) {
        funds = funds+profit;
        fundsInString = to_string(funds);
        money.setString(fundsInString);
        beetClock.restart();
        win.draw(money);
        win.display();
        isBeet = false;
        beetClock.restart();
       
        }
        win.display();
    
   
};

void appleGrowth(float& funds, string& fundsInString, Text& money, RenderWindow& win, Clock&appleClock, float&appleModifier, bool&isApple) {
    float profit = 10;
    int x = 0;


    
    float currentProgress =appleClock.getElapsedTime().asMilliseconds();       
        if(currentProgress >= appleModifier*5) {
        funds = funds+profit;
        fundsInString = to_string(funds);
        money.setString(fundsInString);
        appleClock.restart();
        win.draw(money);
        win.display();
        isApple = false;
        appleClock.restart();
       
        }
        win.display();
    
   
};

void bananaGrowth(float& funds, string& fundsInString, Text& money, RenderWindow& win,  Clock&bananaClock, float&bananaModifier, bool&isBanana) {
    float profit = 10;
    int x = 0;


    
    float currentProgress =bananaClock.getElapsedTime().asMilliseconds();
        
        if(currentProgress >= bananaModifier*5) {
        funds = funds+profit;
        fundsInString = to_string(funds);
        money.setString(fundsInString);
        bananaClock.restart();
        win.draw(money);
        win.display();
        isBanana = false;
        bananaClock.restart();
       
        }
        win.display();
    
   
};

void cherryGrowth(float& funds, string& fundsInString, Text& money, RenderWindow& win, Clock&cherryClock, float&cherryModifier, bool&isCherry) {
    float profit = 10;
    int x = 0;


    
    float currentProgress =cherryClock.getElapsedTime().asMilliseconds();
        
        if(currentProgress >= cherryModifier*5) {
        funds = funds+profit;
        fundsInString = to_string(funds);
        money.setString(fundsInString);
        cherryClock.restart();
        win.draw(money);
        win.display();
        isCherry = false;
        cherryClock.restart();
       
        }
        win.display();
    
   
};


#endif