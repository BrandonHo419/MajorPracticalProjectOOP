#include "Requirements.h"


using namespace std;
using namespace sf;

void avoGrowth(float& funds, string& fundsInString, Text& money, RenderWindow& win, RectangleShape& bar, RectangleShape&bar1, RectangleShape&bar2, RectangleShape&bar3, RectangleShape&bar4, Clock& avoClock, bool& isAvo, float& avoModifier) {
    // lets say avo growth time is 25s
    float profit = 100;
    int y = 1;
        
        float currentProgress = avoClock.getElapsedTime().asMilliseconds();
        if(currentProgress >=avoModifier) {
            bar1.setFillColor(Color::Green);
            win.draw(bar1);
        }
        if(currentProgress >=avoModifier*2) {
        bar2.setFillColor(Color::Green);
        win.draw(bar2);
        
        }
        if(currentProgress >= avoModifier*3) {
        bar3.setFillColor(Color::Green);
        win.draw(bar3);
        
        }
        if(currentProgress >=avoModifier*4) {
        bar4.setFillColor(Color::Green);
        win.draw(bar4);
        }
        
        if(currentProgress >= avoModifier*5) {
        funds = funds+profit;
        fundsInString = to_string(funds);
        money.setString(fundsInString);
        bar1.setFillColor(Color::Black);
        bar2.setFillColor(Color::Black);
        bar3.setFillColor(Color::Black);
        bar4.setFillColor(Color::Black);
        bar.setFillColor(Color::Black);
        avoClock.restart();
        win.draw(bar1);
        win.draw(bar2);
        win.draw(bar3);
        win.draw(bar4);
        win.draw(bar);
        win.draw(money);
        win.display();
        isAvo = false;
        avoClock.restart();
       
        }
        win.display();
    
   
};

void beetGrowth(float& funds, string& fundsInString, Text& money, RenderWindow& win, RectangleShape& bar21, RectangleShape&bar22, RectangleShape&bar23, RectangleShape&bar24, RectangleShape&bar25, Clock&beetClock, float&beetModifier, bool&isBeet) {
    float profit = 50;
    int x = 0;


    
    float currentProgress = beetClock.getElapsedTime().asMilliseconds();
        if(currentProgress >=beetModifier) {
            bar22.setFillColor(Color::Green);
            win.draw(bar22);
        }
        if(currentProgress >=beetModifier*2) {
        bar23.setFillColor(Color::Green);
        win.draw(bar23);
        
        }
        if(currentProgress >= beetModifier*3) {
        bar24.setFillColor(Color::Green);
        win.draw(bar24);
        
        }
        if(currentProgress >=beetModifier*4) {
        bar25.setFillColor(Color::Green);
        win.draw(bar25);
        }
        
        if(currentProgress >= beetModifier*5) {
        funds = funds+profit;
        fundsInString = to_string(funds);
        money.setString(fundsInString);
        bar21.setFillColor(Color::Black);
        bar22.setFillColor(Color::Black);
        bar23.setFillColor(Color::Black);
        bar24.setFillColor(Color::Black);
        bar25.setFillColor(Color::Black);
        beetClock.restart();
        win.draw(bar21);
        win.draw(bar22);
        win.draw(bar23);
        win.draw(bar24);
        win.draw(bar25);
        win.draw(money);
        win.display();
        isBeet = false;
        beetClock.restart();
       
        }
        win.display();
    
   
};

void appleGrowth(float& funds, string& fundsInString, Text& money, RenderWindow& win, RectangleShape& bar31, RectangleShape&bar32, RectangleShape&bar33, RectangleShape&bar34, RectangleShape&bar35, Clock&appleClock, float&appleModifier, bool&isApple) {
    float profit = 10;
    int x = 0;


    
    float currentProgress =appleClock.getElapsedTime().asMilliseconds();
        if(currentProgress >=appleModifier) {
            bar32.setFillColor(Color::Green);
            win.draw(bar32);
        }
        if(currentProgress >=appleModifier*2) {
        bar33.setFillColor(Color::Green);
        win.draw(bar33);
        
        }
        if(currentProgress >= appleModifier*3) {
        bar34.setFillColor(Color::Green);
        win.draw(bar34);
        
        }
        if(currentProgress >=appleModifier*4) {
        bar35.setFillColor(Color::Green);
        win.draw(bar35);
        }
        
        if(currentProgress >= appleModifier*5) {
        funds = funds+profit;
        fundsInString = to_string(funds);
        money.setString(fundsInString);
        bar31.setFillColor(Color::Black);
        bar32.setFillColor(Color::Black);
        bar33.setFillColor(Color::Black);
        bar34.setFillColor(Color::Black);
        bar35.setFillColor(Color::Black);
        appleClock.restart();
        win.draw(bar31);
        win.draw(bar32);
        win.draw(bar33);
        win.draw(bar34);
        win.draw(bar35);
        win.draw(money);
        win.display();
        isApple = false;
        appleClock.restart();
       
        }
        win.display();
    
   
};

void bananaGrowth(float& funds, string& fundsInString, Text& money, RenderWindow& win, RectangleShape& bar41, RectangleShape&bar42, RectangleShape&bar43, RectangleShape&bar44, RectangleShape&bar45, Clock&bananaClock, float&bananaModifier, bool&isBanana) {
    float profit = 10;
    int x = 0;


    
    float currentProgress =bananaClock.getElapsedTime().asMilliseconds();
        if(currentProgress >=bananaModifier) {
            bar42.setFillColor(Color::Green);
            win.draw(bar42);
        }
        if(currentProgress >=bananaModifier*2) {
        bar43.setFillColor(Color::Green);
        win.draw(bar43);
        
        }
        if(currentProgress >= bananaModifier*3) {
        bar44.setFillColor(Color::Green);
        win.draw(bar44);
        
        }
        if(currentProgress >=bananaModifier*4) {
        bar45.setFillColor(Color::Green);
        win.draw(bar45);
        }
        
        if(currentProgress >= bananaModifier*5) {
        funds = funds+profit;
        fundsInString = to_string(funds);
        money.setString(fundsInString);
        bar41.setFillColor(Color::Black);
        bar42.setFillColor(Color::Black);
        bar43.setFillColor(Color::Black);
        bar44.setFillColor(Color::Black);
        bar45.setFillColor(Color::Black);
        bananaClock.restart();
        win.draw(bar41);
        win.draw(bar42);
        win.draw(bar43);
        win.draw(bar44);
        win.draw(bar45);
        win.draw(money);
        win.display();
        isBanana = false;
        bananaClock.restart();
       
        }
        win.display();
    
   
};

void cherryGrowth(float& funds, string& fundsInString, Text& money, RenderWindow& win, RectangleShape& bar51, RectangleShape&bar52, RectangleShape&bar53, RectangleShape&bar54, RectangleShape&bar55, Clock&cherryClock, float&cherryModifier, bool&isCherry) {
    float profit = 10;
    int x = 0;


    
    float currentProgress =cherryClock.getElapsedTime().asMilliseconds();
        if(currentProgress >=cherryModifier) {
            bar52.setFillColor(Color::Green);
            win.draw(bar52);
        }
        if(currentProgress >=cherryModifier*2) {
        bar53.setFillColor(Color::Green);
        win.draw(bar53);
        
        }
        if(currentProgress >= cherryModifier*3) {
        bar54.setFillColor(Color::Green);
        win.draw(bar54);
        
        }
        if(currentProgress >=cherryModifier*4) {
        bar55.setFillColor(Color::Green);
        win.draw(bar55);
        }
        
        if(currentProgress >= cherryModifier*5) {
        funds = funds+profit;
        fundsInString = to_string(funds);
        money.setString(fundsInString);
        bar51.setFillColor(Color::Black);
        bar52.setFillColor(Color::Black);
        bar53.setFillColor(Color::Black);
        bar54.setFillColor(Color::Black);
        bar55.setFillColor(Color::Black);
        cherryClock.restart();
        win.draw(bar51);
        win.draw(bar52);
        win.draw(bar53);
        win.draw(bar54);
        win.draw(bar55);
        win.draw(money);
        win.display();
        isCherry = false;
        cherryClock.restart();
       
        }
        win.display();
    
   
};
