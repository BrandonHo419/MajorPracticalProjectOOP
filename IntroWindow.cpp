#include "Render.h"
#include "Audio.h"
#include "Animation.h"
#include "Textures.h"
#include "drawShop.h"
#include "PlantGrowth.h"
#include "Player.h"
#include "Shop.h"
#include "Requirements.h"
#include "ScrollAnimation.h"
#include "RandomEvents.h"
#include "loadTextures.h"
#include "createSprite.h"
#include "loadRect.h"
#include "winDraw.h"
#include "mouseHandle.h"
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

auto tp = std::chrono::steady_clock::now();


int main() {

    
    RenderWindow win(VideoMode(1280, 720), "Super Awesome Plant Game :3");
// utilise the classes
    Player p;
    Shop s;
    Animation anims;
    loadTextures lt;
    createSprite cs;
    loadRect lr;
    winDraw wr(win);
    
    
    

    // load sound buffers
    Audio a;
    
    

    RandomEvents events;


    events.genRand();
    events.deadFarmer();
    Text message;
    message.setString("A rival competitor hired Agent 47 and he BRUTALLY assasinated all of your farmers and stole some money");
    

    // open clock for progression
    Clock beetClock;
    Clock blueberryClock;
    Clock tomatoClock;
    Clock carrotClock;
    Clock strawberryClock;
    
    // 

    // plant stuff + shop
    bool isBeet = false; 
    float beetModifier = 1000; // timer more orles

    bool isBlueberry = false;
    float blueberryModifier = 1000;

    bool istomato = false;
    float tomatoModifier = 1000; 

    bool isCarrot = false;
    float carrotModifier = 1000; 

    bool isStrawberry = false;
    float strawberryModifier = 1000; 

    bool isPressed = false;

    // end plant stuff + shop

    // money functionality
    
    float funds = p.getMoney();
    string fundsInString = to_string(funds);

    Font font;
    font.loadFromFile("Albertson.ttf");
    
    Text money;
    money.setFont(font);
    money.setString(fundsInString);
    money.setFillColor(Color::White);
    money.setPosition(920, 60);

    //end money

    // Load textures
    loadTextures::allTextures getTextures = lt.getTextures();

  

    // load from file
    lt.assignTextures();
    

  


    while (win.isOpen())
{
    sf::Event event;
    while (win.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            win.close();

        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
            Vector2i mousepos = Mouse::getPosition(win);
            
            // Check for plant buttons
            if (cs.signs.getGlobalBounds().contains(static_cast<Vector2f>(mousepos)) && funds >= 10) {
                funds -= 10;
                lr.bar.setFillColor(Color::Green);
                isBlueberry = true;
                blueberryClock.restart();
                blueberryGrowth(funds, fundsInString, money, win, lr, blueberryClock, isBlueberry, blueberryModifier);
            } 
            else if (cs.signs2.getGlobalBounds().contains(static_cast<Vector2f>(mousepos)) && funds >= 50) {
                funds -= 50;
                lr.bar21.setFillColor(Color::Green);
                isBeet = true;
                beetClock.restart();
                beetGrowth(funds, fundsInString, money, win, lr, beetClock, beetModifier, isBeet);
            } 
            else if (cs.signs3.getGlobalBounds().contains(static_cast<Vector2f>(mousepos)) && funds >= 150) {
                funds -= 50;
                lr.bar31.setFillColor(Color::Green);
                istomato = true;
                tomatoClock.restart();
                tomatoGrowth(funds, fundsInString, money, win, lr, tomatoClock, tomatoModifier, istomato);
            } 
            else if (cs.signs4.getGlobalBounds().contains(static_cast<Vector2f>(mousepos)) && funds < 1100) {
                lr.bar41.setFillColor(Color::Green);
                isCarrot = true;
                carrotClock.restart();
                carrotGrowth(funds, fundsInString, money, win, lr, carrotClock, carrotModifier, isCarrot);
            } 
            else if (cs.signs5.getGlobalBounds().contains(static_cast<Vector2f>(mousepos)) && funds < 300) {
                lr.bar51.setFillColor(Color::Green);
                isStrawberry = true;
                strawberryClock.restart();
                strawberryGrowth(funds, fundsInString, money, win, lr, strawberryClock, strawberryModifier, isStrawberry);
            } 
            else if (cs.shop.getGlobalBounds().contains(static_cast<Vector2f>(mousepos))) {
                win.clear();
                drawShop(win);
            }
        }
    }

    
    if (isBeet && beetClock.getElapsedTime().asMilliseconds() >= beetModifier) {
        beetGrowth(funds, fundsInString, money, win, lr, beetClock, beetModifier, isBeet);
    }
    if (isBlueberry && blueberryClock.getElapsedTime().asMilliseconds() >= blueberryModifier) {
        blueberryGrowth(funds, fundsInString, money, win, lr, blueberryClock, isBlueberry, blueberryModifier);
    }
    if (istomato && tomatoClock.getElapsedTime().asMilliseconds() >= tomatoModifier) {
        tomatoGrowth(funds, fundsInString, money, win, lr, tomatoClock, tomatoModifier, istomato);
    }
    if (isCarrot && carrotClock.getElapsedTime().asMilliseconds() >= carrotModifier) {
        carrotGrowth(funds, fundsInString, money, win, lr, carrotClock, carrotModifier, isCarrot);
    }
    if (isStrawberry && strawberryClock.getElapsedTime().asMilliseconds() >= strawberryModifier) {
        strawberryGrowth(funds, fundsInString, money, win, lr, strawberryClock, strawberryModifier, isStrawberry);
    }

    
    wr.drawStart();
    win.draw(money);
    win.draw(message);
    a.playSounds();
    
    win.display(); 
}

return 0;

};


