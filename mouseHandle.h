#include "Requirements.h"
#include "winDraw.h"
#include "Audio.h"
#include "Player.h"
#include "PlantGrowth.h"

#ifndef MOUSEHANDLE_H
#define MOUSEHANDLE_H

class mouseHandle {
private:
    RenderWindow& win;
    Audio& a;
    winDraw& wd;
    createSprite cs;
    loadRect lr;
    Player p;
    Clock c;
    float funds = p.getMoney();
    string fundsInString = to_string(funds);

    bool isBeet = false; 
    float beetModifier = 1000;

    bool isBlueberry = false;
    float blueberryModifier = 1000;

    bool isTomato = false;
    float tomatoModifier = 1000; 

    bool isCarrot = false;
    float carrotModifier = 1000; 

    bool isStrawberry = false;
    float strawberryModifier = 1000; 

    bool isPressed = false;

    Clock beetClock, blueberryClock, tomatoClock, carrotClock, strawberryClock;

    

public:
    mouseHandle(RenderWindow& window, Audio& audio, winDraw& winDrawInstance, createSprite cs, loadRect lr) 
        : win(window), a(audio), wd(winDrawInstance), cs(cs), lr(lr) {}

   void handleMouseClick(Event event, RenderWindow& win, Sprite& cropSign, float cost, float& funds, RectangleShape& bar, RectangleShape& bar1, RectangleShape& bar2, RectangleShape& bar3, RectangleShape& bar4, Clock& cropClock, bool& isCrop, float modifier, void (*growthFunction)(float&, string&, Text&, RenderWindow&, RectangleShape&, RectangleShape&, RectangleShape&, RectangleShape&, RectangleShape&, Clock&, bool&, float&), string& fundsInString, Text& money, Audio& a) {
    if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
        Vector2i mousepos = Mouse::getPosition(win);
        if (cropSign.getGlobalBounds().contains(static_cast<Vector2f>(mousepos))) {
            if (funds >= cost) {
                funds -= cost;
                bar.setFillColor(Color::Green);
                win.draw(bar);
                win.draw(money);
                win.display();
                isCrop = true;
                cropClock.restart();
                growthFunction(funds, fundsInString, money, win, bar, bar1, bar2, bar3, bar4, cropClock, isCrop, modifier);
                
            }
        }
    }
}




};



#endif
