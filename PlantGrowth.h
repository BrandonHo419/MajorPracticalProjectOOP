#include "Requirements.h"
#include "loadRect.h"

#ifndef PLANTGROWTH_H
#define PLANTGROWTH_H




void blueberryGrowth(float& funds, string& fundsInString, Text& money, RenderWindow& win, loadRect& lr, Clock& blueberryClock, bool& isBlueberry, float& blueberryModifier) {
    // lets say blueberry growth time is 25s
    float profit = 100;
        float currentProgress = blueberryClock.getElapsedTime().asMilliseconds();
        if(currentProgress >=blueberryModifier) {
            lr.bar1.setFillColor(Color::Green);
            win.draw(lr.bar1);
        }
        if(currentProgress >=blueberryModifier*2) {
        lr.bar2.setFillColor(Color::Green);
        win.draw(lr.bar2);
        
        }
        if(currentProgress >= blueberryModifier*3) {
        lr.bar3.setFillColor(Color::Green);
        win.draw(lr.bar3);
        
        }
        if(currentProgress >=blueberryModifier*4) {
        lr.bar4.setFillColor(Color::Green);
        win.draw(lr.bar4);
        }
        
        if(currentProgress >= blueberryModifier*5) {
        funds = funds+profit;
        fundsInString = to_string(funds);
        money.setString(fundsInString);
        lr.bar1.setFillColor(Color::Black);
        lr.bar2.setFillColor(Color::Black);
        lr.bar3.setFillColor(Color::Black);
        lr.bar4.setFillColor(Color::Black);
        lr.bar.setFillColor(Color::Black);
        blueberryClock.restart();
        win.draw(lr.bar1);
        win.draw(lr.bar2);
        win.draw(lr.bar3);
        win.draw(lr.bar4);
        win.draw(lr.bar);
        win.draw(money);
        win.display();
        isBlueberry = false;
        blueberryClock.restart();
       
        }
        win.display();
    
   
};

void beetGrowth(float& funds, string& fundsInString, Text& money, RenderWindow& win, loadRect& lr, Clock&beetClock, float&beetModifier, bool&isBeet) {
    float profit = 50;

    float currentProgress = beetClock.getElapsedTime().asMilliseconds();
        if(currentProgress >=beetModifier) {
            lr.bar22.setFillColor(Color::Green);
            win.draw(lr.bar22);
        }
        if(currentProgress >=beetModifier*2) {
        lr.bar23.setFillColor(Color::Green);
        win.draw(lr.bar23);
        
        }
        if(currentProgress >= beetModifier*3) {
        lr.bar24.setFillColor(Color::Green);
        win.draw(lr.bar24);
        
        }
        if(currentProgress >=beetModifier*4) {
        lr.bar25.setFillColor(Color::Green);
        win.draw(lr.bar25);
        }
        
        if(currentProgress >= beetModifier*5) {
        funds = funds+profit;
        fundsInString = to_string(funds);
        money.setString(fundsInString);
        lr.bar21.setFillColor(Color::Black);
        lr.bar22.setFillColor(Color::Black);
        lr.bar23.setFillColor(Color::Black);
        lr.bar24.setFillColor(Color::Black);
        lr.bar25.setFillColor(Color::Black);
        beetClock.restart();
        win.draw(lr.bar21);
        win.draw(lr.bar22);
        win.draw(lr.bar23);
        win.draw(lr.bar24);
        win.draw(lr.bar25);
        win.draw(money);
        win.display();
        isBeet = false;
        beetClock.restart();
       
        }
        win.display();
    
   
};

void tomatoGrowth(float& funds, string& fundsInString, Text& money, RenderWindow& win, loadRect& lr, Clock&tomatoClock, float&tomatoModifier, bool&istomato) {
    float profit = 10;
    int x = 0;


    float currentProgress =tomatoClock.getElapsedTime().asMilliseconds();
        if(currentProgress >=tomatoModifier) {
            lr.bar32.setFillColor(Color::Green);
            win.draw(lr.bar32);
        }
        if(currentProgress >=tomatoModifier*2) {
        lr.bar33.setFillColor(Color::Green);
        win.draw(lr.bar33);
        
        }
        if(currentProgress >= tomatoModifier*3) {
        lr.bar34.setFillColor(Color::Green);
        win.draw(lr.bar34);
        
        }
        if(currentProgress >=tomatoModifier*4) {
        lr.bar35.setFillColor(Color::Green);
        win.draw(lr.bar35);
        }
        
        if(currentProgress >= tomatoModifier*5) {
        funds = funds+profit;
        fundsInString = to_string(funds);
        money.setString(fundsInString);
        lr.bar31.setFillColor(Color::Black);
        lr.bar32.setFillColor(Color::Black);
        lr.bar33.setFillColor(Color::Black);
        lr.bar34.setFillColor(Color::Black);
        lr.bar35.setFillColor(Color::Black);
        tomatoClock.restart();
        win.draw(lr.bar31);
        win.draw(lr.bar32);
        win.draw(lr.bar33);
        win.draw(lr.bar34);
        win.draw(lr.bar35);
        win.draw(money);
        win.display();
        istomato = false;
        tomatoClock.restart();
       
        }
        win.display();
    
   
};

void carrotGrowth(float& funds, string& fundsInString, Text& money, RenderWindow& win, loadRect& lr, Clock&carrotClock, float&carrotModifier, bool&isCarrot) {
    float profit = 10;
    int x = 0;


    float currentProgress =carrotClock.getElapsedTime().asMilliseconds();
        if(currentProgress >=carrotModifier) {
            lr.bar42.setFillColor(Color::Green);
            win.draw(lr.bar42);
        }
        if(currentProgress >=carrotModifier*2) {
        lr.bar43.setFillColor(Color::Green);
        win.draw(lr.bar43);
        
        }
        if(currentProgress >= carrotModifier*3) {
        lr.bar44.setFillColor(Color::Green);
        win.draw(lr.bar44);
        
        }
        if(currentProgress >=carrotModifier*4) {
        lr.bar45.setFillColor(Color::Green);
        win.draw(lr.bar45);
        }
        
        if(currentProgress >= carrotModifier*5) {
        funds = funds+profit;
        fundsInString = to_string(funds);
        money.setString(fundsInString);
        lr.bar41.setFillColor(Color::Black);
        lr.bar42.setFillColor(Color::Black);
        lr.bar43.setFillColor(Color::Black);
        lr.bar44.setFillColor(Color::Black);
        lr.bar45.setFillColor(Color::Black);
        carrotClock.restart();
        win.draw(lr.bar41);
        win.draw(lr.bar42);
        win.draw(lr.bar43);
        win.draw(lr.bar44);
        win.draw(lr.bar45);
        win.draw(money);
        win.display();
        isCarrot = false;
        carrotClock.restart();
       
        }
        win.display();
    
   
};

void strawberryGrowth(float& funds, string& fundsInString, Text& money, RenderWindow& win, loadRect& lr, Clock&strawberryClock, float&strawberryModifier, bool&isStrawberry) {
    float profit = 10;
    int x = 0;


    float currentProgress =strawberryClock.getElapsedTime().asMilliseconds();
        if(currentProgress >=strawberryModifier) {
            lr.bar52.setFillColor(Color::Green);
            win.draw(lr.bar52);
        }
        if(currentProgress >=strawberryModifier*2) {
        lr.bar53.setFillColor(Color::Green);
        win.draw(lr.bar53);
        
        }
        if(currentProgress >= strawberryModifier*3) {
        lr.bar54.setFillColor(Color::Green);
        win.draw(lr.bar54);
        
        }
        if(currentProgress >=strawberryModifier*4) {
        lr.bar55.setFillColor(Color::Green);
        win.draw(lr.bar55);
        }
        
        if(currentProgress >= strawberryModifier*5) {
        funds = funds+profit;
        fundsInString = to_string(funds);
        money.setString(fundsInString);
        lr.bar51.setFillColor(Color::Black);
        lr.bar52.setFillColor(Color::Black);
        lr.bar53.setFillColor(Color::Black);
        lr.bar54.setFillColor(Color::Black);
        lr.bar55.setFillColor(Color::Black);
        strawberryClock.restart();
        win.draw(lr.bar51);
        win.draw(lr.bar52);
        win.draw(lr.bar53);
        win.draw(lr.bar54);
        win.draw(lr.bar55);
        win.draw(money);
        win.display();
        isStrawberry = false;
        strawberryClock.restart();
       
        }
        win.display();
    
   
};

#endif