#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

void avoGrowth(float& funds, string& fundsInString, Text& money, RenderWindow& win, RectangleShape& bar, RectangleShape&bar1, RectangleShape&bar2, RectangleShape&bar3, RectangleShape&bar4, Clock& avoClock, bool& isAvo, float& avoModifier) {
    // lets say avo growth time is 25s
    float profit = 100;
    int y = 1;
        float currentProgress = avoClock.getElapsedTime().asSeconds();
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


    float currentProgress = beetClock.getElapsedTime().asSeconds();
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