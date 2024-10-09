#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "Textures.h"
#include "drawShop.h"
#include "PlantGrowth.h"
#include "oldPlantGrowth.h"
#include "Player.h"
#include "Shop.h"
#include "Requirements.h"
#include "Animation.h"
#include "ScrollAnimation.h"
#include "RandomEvents.h"
#include "loadRect.h"
#include "DialogBox.h"

using namespace std;
using namespace sf;

auto tp = std::chrono::steady_clock::now();

int main() {
    
    RenderWindow win(VideoMode(1280, 720), "Super Awesome Plant Game :3");
    Player p;
     Font font;
    font.loadFromFile("Albertson.ttf");
    float funds = p.getMoney();
    cout << funds << endl;
    string fundsInString = to_string(funds);

   
    
    Text money;
    money.setFont(font);
    money.setString(fundsInString);
    money.setFillColor(Color::White);
    money.setPosition(920, 60);
// utilise the classes
    
    Shop s;
    Animation anims;
    RandomEvents events;
    Scroll sc(Vector2f(275.f, 152.f));
    sc.Update(1, 1);
    sc.Update(1, 1);
    loadRect lr;



    events.genRand();
    
    

    
    // open clock for progression
    Clock beetClock;
    Clock avoClock;
    Clock appleClock;
    Clock bananaClock;
    Clock cherryClock;
    Clock dtt;
    // 

    

    // plant stuff + shop
    bool isBeet = false; 
    float beetModifier = 1000; // timer more orles

    bool isAvo = false;
    float avoModifier = 1000;

    bool isApple = false;
    float appleModifier = 1000; 

    bool isBanana = false;
    float bananaModifier = 1000; 

    bool isCherry = false;
    float cherryModifier = 1000; 

    bool isPressed = false;

    bool isUpgrade1 = false;

    // end plant stuff + shop

    // money functionality
    
    

    //end money

    // Load textures
   
    Texture bd; // create something for backdrop
    Texture minibd;
    Texture avo;
    Texture beet;
    Texture apple;
    Texture banana;
    Texture cherry;
    Texture shopButton;
    Texture sign;
    Texture sign2;
    Texture sign3;
    Texture sign4;
    Texture sign5;
    

    Texture back;
    Texture fore;
    Texture fertiliser;
    Texture house;
    Texture worker;
    Texture board1;
    Texture board2;
    Texture board3;
    Texture shopBoard;
     Texture block;
    // End loading textures

    loadRect();


    // load from file
    bd.loadFromFile("bd1.jpg");
    minibd.loadFromFile("minibd.jpg");
    avo.loadFromFile("avocado.png");
    beet.loadFromFile("beetroot.png");
    apple.loadFromFile("apple.png");
    banana.loadFromFile("banana.png");
    cherry.loadFromFile("cherry.png");
    shopButton.loadFromFile("shop.png");
    sign.loadFromFile("sign.png");
    sign2.loadFromFile("sign.png");
    sign3.loadFromFile("sign.png");
    sign4.loadFromFile("sign.png");
    sign5.loadFromFile("sign.png");
    block.loadFromFile("scrollsandblocks.png");
    
    // end load from file
    


    if (!bd.loadFromFile("bd1.jpg")) {
        cerr << "Error loading background texture" << endl;
        return -1; // Exit if the texture fails to load
    }

    if (!minibd.loadFromFile("minibd.jpg")) {
        cerr << "Error loading background texture" << endl;
        return -1; 
    }

    if (!avo.loadFromFile("avocado.png")) {
        cerr << "Error loading avocado texture" << endl;
        return -1; 
    };

    if (!beet.loadFromFile("beetroot.png")) {
        cerr << "Error loading beetroot texture" << endl;
        return -1; 
    }
    

    // Create sprites for the GFX
    Sprite backdrop(bd); // creates a sprite so it stays in systme memory
    Sprite minibackdrop(minibd);
    Sprite avocado(avo);
    Sprite beetroot(beet);
    Sprite apples(apple);
    Sprite bananas(banana);
    Sprite cherries(cherry);
    Sprite shop(shopButton);
    Sprite signs(sign);
    Sprite signs2(sign2);
    Sprite signs3(sign3);
    Sprite signs4(sign4);
    Sprite signs5(sign5);
    Sprite blocks;

// Shop Sprites
    Sprite background(back);
    Sprite foreground(fore);
    Sprite shopSign1(board1);
    Sprite shopSign2(board2);
    Sprite shopSign3(board3);
    Sprite shopSign(shopBoard);
    Sprite fert(fertiliser);
    Sprite greenhouse(house);
    Sprite farmer(worker);

    // End sprites

    // Set Scales
    minibackdrop.setScale(2.0, 1.5);
    avocado.setScale(0.14, 0.14);
    beetroot.setScale(0.14, 0.14);
    apples.setScale(0.14, 0.14);
    bananas.setScale(0.14, 0.14);
    cherries.setScale(0.2, 0.2);
    shop.setScale(0.4, 0.4);
    signs.setScale(0.4, 0.4);
    signs2.setScale(0.4, 0.4);
    signs3.setScale(0.4, 0.4);
    signs4.setScale(0.4, 0.4);
    signs5.setScale(0.4, 0.4);
    blocks.setScale(1, 1);

    
    
    // shop scales
    foreground.setScale(2.0, 1.5);
    fert.setScale(0.2f, 0.2f);
    greenhouse.setScale(0.35f, 0.35f);
    farmer.setScale(0.045, 0.045);
    shopSign.setScale(0.4, 0.4);
    shopSign1.setScale(0.4, 0.4);
    shopSign2.setScale(0.4, 0.4);
    shopSign3.setScale(0.4, 0.4);
    //End scales

    // Set positions
    FloatRect minibackdropbounds = minibackdrop.getLocalBounds(); // Get the local boudns with FloatRect which gets dimension (width and height)
    minibackdrop.setOrigin(minibackdropbounds.width/2, minibackdropbounds.height/2); // this ensures it calculates relative to the center
    minibackdrop.setPosition(win.getSize().x/2, win.getSize().y/2); // sets the position

    FloatRect shopPlace = shop.getLocalBounds();
    shop.setOrigin(shopPlace.width/2, shopPlace.height/2);
    shop.setPosition(win.getSize().x/2, win.getSize().y/2 +235);

    FloatRect signsPlacement = signs.getLocalBounds();
    signs.setOrigin(signsPlacement.width/2, signsPlacement.height/2);
    signs.setPosition(win.getSize().x/2 - 458, signsPlacement.height/2 - 50);
    

    FloatRect signsPlacement2 = signs2.getLocalBounds();
    signs2.setOrigin(signsPlacement2.width/2, signsPlacement2.height/2);
    signs2.setPosition(win.getSize().x/2 - 458, signsPlacement2.height/2 + 50);

    FloatRect signsPlacement3 = signs3.getLocalBounds();
    signs3.setOrigin(signsPlacement3.width/2, signsPlacement3.height/2);
    signs3.setPosition(win.getSize().x/2 - 458, signsPlacement3.height/2 + 150);

    FloatRect signsPlacement4 = signs4.getLocalBounds();
    signs4.setOrigin(signsPlacement4.width/2, signsPlacement4.height/2);
    signs4.setPosition(win.getSize().x/2 - 453, signsPlacement4.height/2 + 250);

    FloatRect signsPlacement5 = signs5.getLocalBounds();
    signs5.setOrigin(signsPlacement5.width/2, signsPlacement5.height/2);
    signs5.setPosition(win.getSize().x/2 - 458, signsPlacement5.height/2 + 357);

    FloatRect minibackdropbounds2 = foreground.getLocalBounds();
    foreground.setOrigin(minibackdropbounds2.width / 2, minibackdropbounds2.height / 2);
    foreground.setPosition(win.getSize().x / 2, win.getSize().y / 2);

    FloatRect fertDimensions = fert.getLocalBounds();
    fert.setOrigin(fertDimensions.width / 2, fertDimensions.height / 2);
    fert.setPosition(win.getSize().x/2 -458, win.getSize().y/2 - 20);

    FloatRect greenhouseDimensions = greenhouse.getLocalBounds();
    greenhouse.setOrigin(greenhouseDimensions.width / 2, greenhouseDimensions.height / 2);
    greenhouse.setPosition(win.getSize().x/2, win.getSize().y/2 - 20);

    FloatRect workerDimensions = farmer.getLocalBounds();
    farmer.setOrigin(workerDimensions.width / 2, workerDimensions.height / 2);
    farmer.setPosition(win.getSize().x/2 + 458, win.getSize().y/2 - 20);

    FloatRect signDimensions = shopSign1.getLocalBounds();
    shopSign1.setOrigin(signDimensions.width / 2, signDimensions.height / 2);
    shopSign1.setPosition(win.getSize().x/2 -458, win.getSize().y/2 - 20);

    FloatRect signDimensions2 = shopSign2.getLocalBounds();
    shopSign2.setOrigin(signDimensions.width / 2, signDimensions.height / 2);
    shopSign2.setPosition(win.getSize().x/2, win.getSize().y/2 - 20);

    FloatRect signDimensions3 = shopSign3.getLocalBounds();
    shopSign3.setOrigin(signDimensions3.width / 2, signDimensions3.height / 2);
    shopSign3.setPosition(win.getSize().x/2 + 458, win.getSize().y/2 - 20);

    FloatRect shopDimensions2 = shopSign.getLocalBounds();
    shopSign.setOrigin(shopDimensions2.width / 2, shopDimensions2.height / 2);
    shopSign.setPosition(win.getSize().x/2, win.getSize().y/2 - 200);

        FloatRect bounds = events.message1.getLocalBounds();
        events.message1.setPosition(lr.DialogBox.getPosition().x + (lr.DialogBox.getSize().x - bounds.width) /2, 
        lr.DialogBox.getPosition().y + (lr.DialogBox.getSize().y - bounds.height)/2 - bounds.top);
    
    

    // New position
    avocado.setPosition(150, 100);
    beetroot.setPosition(150, 200);
    apples.setPosition(150, 300);
    bananas.setPosition(150, 400);
    cherries.setPosition(150, 500);
    
    // End positions


    while (win.isOpen())
    {
        sf::Event event;
        Event e;
        Event beet;
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                win.close();

        
        // anim 
        
        
        if(event.type ==Event::MouseButtonPressed) {
            if(event.mouseButton.button == Mouse::Left) {
                Vector2i mousepos = Mouse::getPosition(win);
                Vector2f mouseposf(static_cast<float>(mousepos.x), static_cast<float>(mousepos.y));
                if(sc.getGlobalBounds().contains(static_cast<Vector2f>(mouseposf))) {
                    isUpgrade1 = true;
                    float dt = dtt.restart().asSeconds();
                    float waitTime =0.01;
                    dtt.restart();
                    sc.Update(dt, waitTime);
                    // add extra functionality
                    
                }
            }
        }

        
        if(event.type == Event::MouseButtonPressed) { // checks if it is a mouse press
            if(event.mouseButton.button == Mouse::Left) { // checks whether it was a left mouse button press
                Vector2i mousepos = Mouse::getPosition(win); // retrieves the current mouse position (x and y)
                if(signs.getGlobalBounds().contains(static_cast<Vector2f>(mousepos))) { // returns a rectangle of bounds and static_cast converts 2i to 2f
                    if(funds >= 10) {
                        funds = funds-10;
                        lr.bar.setFillColor(Color::Green);
                        win.draw(lr.bar);
                        win.draw(money);
                        win.display();
                        isAvo = true;
                        avoClock.restart();    
                        avoGrowth(funds, fundsInString, money, win, lr.bar, lr.bar1, lr.bar2, lr.bar3, lr.bar4, avoClock, isAvo, avoModifier); // calls function
                        
                    }
                } 
            }
        } if(event.type == Event::MouseButtonPressed) {
            if(event.mouseButton.button == Mouse::Left) {
                Vector2i mousepos = Mouse::getPosition(win);
                if(signs2.getGlobalBounds().contains(static_cast<Vector2f>(mousepos))) {
                    if(funds >= 50) {
                        funds = funds-50;
                        lr.bar21.setFillColor(Color::Green);
                        win.draw(lr.bar21);
                        win.draw(money);
                        win.display();
                        isBeet = true;
                        beetClock.restart();
                        beetGrowth(funds, fundsInString, money, win, lr.bar21, lr.bar22, lr.bar23, lr.bar24, lr.bar25, beetClock, beetModifier, isBeet);
                        
                    }; // make else condition pop up for poorness
                 
                    
    };
            }
        } if(event.type == Event::MouseButtonPressed) {
            if(event.mouseButton.button == Mouse::Left) {
                Vector2i mousepos = Mouse::getPosition(win);
                if(signs3.getGlobalBounds().contains(static_cast<Vector2f>(mousepos))) {
                    lr.bar31.setFillColor(Color::Green);
                    win.draw(lr.bar31);
                    win.display();
                    isApple = true;
                    appleClock.restart();
                    appleGrowth(funds, fundsInString, money, win, lr.bar31, lr.bar32, lr.bar33, lr.bar34, lr.bar35, appleClock, appleModifier, isApple);
    };
        }
        }
        if(event.type == Event::MouseButtonPressed) {
            if(event.mouseButton.button == Mouse::Left) {
                Vector2i mousepos = Mouse::getPosition(win);
                if(signs4.getGlobalBounds().contains(static_cast<Vector2f>(mousepos))) {
                    lr.bar41.setFillColor(Color::Green);
                    win.draw(lr.bar41);
                    win.display();
                    isBanana = true;
                    bananaClock.restart();
                    bananaGrowth(funds, fundsInString, money, win, lr.bar41, lr.bar42, lr.bar43, lr.bar44, lr.bar45, bananaClock, bananaModifier, isBanana);

    };
        }
        }
        if(event.type == Event::MouseButtonPressed) {
            if(event.mouseButton.button == Mouse::Left) {
                Vector2i mousepos = Mouse::getPosition(win);
                if(signs5.getGlobalBounds().contains(static_cast<Vector2f>(mousepos))) {
                    lr.bar51.setFillColor(Color::Green);
                    win.draw(lr.bar51);
                    win.display();
                    isCherry = true;
                    cherryClock.restart();
                    cherryGrowth(funds, fundsInString, money, win, lr.bar51, lr.bar52, lr.bar53, lr.bar54, lr.bar55, cherryClock, cherryModifier, isCherry);
    };
        }
        } if(event.type = Event::MouseButtonPressed) {
            if(event.mouseButton.button == Mouse::Left) {
                Vector2i mousepos = Mouse::getPosition(win);
                if(shop.getGlobalBounds().contains(static_cast<Vector2f>(mousepos))) {
                    drawShop(win);
                    win.display();
    };
        }
        }
        if(events.eventOne == true) {
            while(events.eventOne == true) {
            win.draw(lr.DialogBox);
            win.draw(events.message1);
            win.display();
            if(event.type = Event::MouseButtonPressed) {
                if(event.mouseButton.button == Mouse::Left) {
                    Vector2i mousepos = Mouse::getPosition(win);
                    if(lr.DialogBox.getGlobalBounds().contains(static_cast<Vector2f>(mousepos))) {
                        events.eventOne = false;
                    }
                }
                }
            }
        }
        }
// flags
        if(isBeet == true) {
            if(beetClock.getElapsedTime().asMilliseconds()>= beetModifier) {
                beetGrowth(funds, fundsInString, money, win, lr.bar21,lr.bar22, lr.bar23, lr.bar24, lr.bar25, beetClock, beetModifier, isBeet);
            }
        };

        if(isAvo == true) {
            if(avoClock.getElapsedTime().asMilliseconds() >= avoModifier) {
                avoGrowth(funds, fundsInString, money, win, lr.bar, lr.bar1, lr.bar2, lr.bar3, lr.bar4, avoClock, isAvo, avoModifier);
            }
        }
        if(isApple == true) {
            if(appleClock.getElapsedTime().asMilliseconds() >= appleModifier) {
                appleGrowth(funds, fundsInString, money, win, lr.bar31, lr.bar32, lr.bar33, lr.bar34, lr.bar35, appleClock, appleModifier, isApple);
            }
        }

        if(isBanana == true) {
            if(bananaClock.getElapsedTime().asMilliseconds() >= bananaModifier) {
                bananaGrowth(funds, fundsInString, money, win, lr.bar41, lr.bar42, lr.bar43, lr.bar44, lr.bar45, bananaClock, bananaModifier, isBanana);
            }
        }

        if(isCherry == true) {
            if(cherryClock.getElapsedTime().asMilliseconds() >= cherryModifier) {
                appleGrowth(funds, fundsInString, money, win, lr.bar51, lr.bar52, lr.bar53, lr.bar54, lr.bar55, cherryClock, cherryModifier, isCherry);
            }
        }

        if(isUpgrade1 == true) {
            if(dtt.getElapsedTime().asSeconds() >= 0.3) {
                float dt = dtt.restart().asSeconds();
                float waitTime =0.3;
                sc.Update(dt, waitTime);
                isUpgrade1 = false;
            }
        }

        

        
            

        // draw the windows
        win.clear();
        win.draw(backdrop);
        win.draw(minibackdrop);
        // 
        win.draw(signs);
        win.draw(signs2);
        win.draw(signs3);
        win.draw(signs4);
        win.draw(signs5);
        //
        win.draw(lr.bar);
        win.draw(lr.bar1);
        win.draw(lr.bar2);
        win.draw(lr.bar3);
        win.draw(lr.bar4);
        win.draw(lr.bar21);
        win.draw(lr.bar22);
        win.draw(lr.bar23);
        win.draw(lr.bar24);
        win.draw(lr.bar25);
        win.draw(lr.bar31);
        win.draw(lr.bar32);
        win.draw(lr.bar33);
        win.draw(lr.bar34);
        win.draw(lr.bar35);
        win.draw(lr.bar41);
        win.draw(lr.bar42);
        win.draw(lr.bar43);
        win.draw(lr.bar44);
        win.draw(lr.bar45);
        win.draw(lr.bar51);
        win.draw(lr.bar52);
        win.draw(lr.bar53);
        win.draw(lr.bar54);
        win.draw(lr.bar55);
        //
        win.draw(avocado);
        win.draw(beetroot);
        win.draw(apples);
        win.draw(bananas);
        win.draw(cherries);
        //
        win.draw(shop);
        win.draw(money);
        //
        
        win.draw(blocks);
        sc.Draw(win);

        win.display();

        
    }

    return 0;
};


