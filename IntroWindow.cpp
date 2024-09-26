#include "Render.h"
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;


int main() {

    
    bool ee = false;
    RenderWindow win(VideoMode(1280, 720), "Super Awesome Plant Game :3");
// utilise the classes
    Player p;
    Shop s;

    SoundBuffer buffer;


Sound eesound(buffer);

Texture rawr;


Sprite rawrs;
rawrs.setTexture(rawr);
rawrs.setScale(1.9f, 1.9f);

    // open clock for progression
    Clock beetClock;
    Clock avoClock;
    Clock appleClock;
    Clock bananaClock;
    Clock cherryClock;
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

    // end plant stuff + shop

    // money functionality
    
    float funds = p.getMoney();
    cout << funds << endl;
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
    // End loading textures

    // Load Progress Bar Shapes

    RectangleShape bar(Vector2f(40, 40));
    bar.setFillColor(Color::Black);
    bar.setPosition(290, 104);

    RectangleShape bar1(Vector2f(40, 40));
    bar1.setFillColor(Color::Black);
    bar1.setPosition(331, 104);
    
    RectangleShape bar2(Vector2f(40, 40));
    bar2.setFillColor(Color::Black);
    bar2.setPosition(372, 104);

    RectangleShape bar3(Vector2f(40, 40));
    bar3.setFillColor(Color::Black);
    bar3.setPosition(413, 104);

    RectangleShape bar4(Vector2f(40, 40));
    bar4.setFillColor(Color::Black);
    bar4.setPosition(454, 104);

    RectangleShape bar21(Vector2f(40, 40));
    bar21.setFillColor(Color::Black);
    bar21.setPosition(290, 204);

    RectangleShape bar22(Vector2f(40, 40));
    bar22.setFillColor(Color::Black);
    bar22.setPosition(331, 204);
    
    RectangleShape bar23(Vector2f(40, 40));
    bar23.setFillColor(Color::Black);
    bar23.setPosition(372, 204);

    RectangleShape bar24(Vector2f(40, 40));
    bar24.setFillColor(Color::Black);
    bar24.setPosition(413, 204);

    RectangleShape bar25(Vector2f(40, 40));
    bar25.setFillColor(Color::Black);
    bar25.setPosition(454, 204);

    RectangleShape bar31(Vector2f(40, 40));
    bar31.setFillColor(Color::Black);
    bar31.setPosition(290, 304);

    RectangleShape bar32(Vector2f(40, 40));
    bar32.setFillColor(Color::Black);
    bar32.setPosition(331, 304);
    
    RectangleShape bar33(Vector2f(40, 40));
    bar33.setFillColor(Color::Black);
    bar33.setPosition(372, 304);

    RectangleShape bar34(Vector2f(40, 40));
    bar34.setFillColor(Color::Black);
    bar34.setPosition(413, 304);

    RectangleShape bar35(Vector2f(40, 40));
    bar35.setFillColor(Color::Black);
    bar35.setPosition(454, 304);

    RectangleShape bar41(Vector2f(40, 40));
    bar41.setFillColor(Color::Black);
    bar41.setPosition(290, 404);

    RectangleShape bar42(Vector2f(40, 40));
    bar42.setFillColor(Color::Black);
    bar42.setPosition(331, 404);
    
    RectangleShape bar43(Vector2f(40, 40));
    bar43.setFillColor(Color::Black);
    bar43.setPosition(372, 404);

    RectangleShape bar44(Vector2f(40, 40));
    bar44.setFillColor(Color::Black);
    bar44.setPosition(413, 404);

    RectangleShape bar45(Vector2f(40, 40));
    bar45.setFillColor(Color::Black);
    bar45.setPosition(454, 404);

    RectangleShape bar51(Vector2f(40, 40));
    bar51.setFillColor(Color::Black);
    bar51.setPosition(290, 511);

    RectangleShape bar52(Vector2f(40, 40));
    bar52.setFillColor(Color::Black);
    bar52.setPosition(331, 511);
    
    RectangleShape bar53(Vector2f(40, 40));
    bar53.setFillColor(Color::Black);
    bar53.setPosition(372, 511);

    RectangleShape bar54(Vector2f(40, 40));
    bar54.setFillColor(Color::Black);
    bar54.setPosition(413, 511);

    RectangleShape bar55(Vector2f(40, 40));
    bar55.setFillColor(Color::Black);
    bar55.setPosition(454, 511);


    // load from file
    setupTextures(bd, minibd, avo, beet, apple, banana, cherry, shopButton, sign, sign2, sign3, sign4, sign5);
    
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
    setScales(win, minibackdrop, avocado, beetroot, apples, bananas, cherries, shop, signs, signs2, signs3, signs4, signs5); // also sets positions of these
    
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
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                win.close();
        if(event.type == Event::MouseButtonPressed) { // checks if it is a mouse press
            if(event.mouseButton.button == Mouse::Left) { // checks whether it was a left mouse button press
                Vector2i mousepos = Mouse::getPosition(win); // retrieves the current mouse position (x and y)
                if(signs.getGlobalBounds().contains(static_cast<Vector2f>(mousepos))) { // returns a rectangle of bounds and static_cast converts 2i to 2f
                    if(funds >= 10) {
                        funds = funds-10;
                        bar.setFillColor(Color::Green);
                        win.draw(bar);
                        win.draw(money);
                        win.display();
                        isAvo = true;
                        avoClock.restart();    
                        avoGrowth(funds, fundsInString, money, win, bar, bar1, bar2, bar3, bar4, avoClock, isAvo, avoModifier); // calls function
                        
                    }
                } 
            }
        } if(event.type == Event::MouseButtonPressed) {
            if(event.mouseButton.button == Mouse::Left) {
                Vector2i mousepos = Mouse::getPosition(win);
                if(signs2.getGlobalBounds().contains(static_cast<Vector2f>(mousepos))) {
                    if(funds >= 50) {
                        funds = funds-50;
                        bar21.setFillColor(Color::Green);
                        win.draw(bar21);
                        win.draw(money);
                        win.display();
                        isBeet = true;
                        beetClock.restart();
                        beetGrowth(funds, fundsInString, money, win, bar21, bar22, bar23, bar24, bar25, beetClock, beetModifier, isBeet);
                        
                    }; // make else condition pop up for poorness
                 
                    
    };
            }
        } if(event.type == Event::MouseButtonPressed) {
            if(event.mouseButton.button == Mouse::Left) {
                Vector2i mousepos = Mouse::getPosition(win);
                if(signs3.getGlobalBounds().contains(static_cast<Vector2f>(mousepos))) {
                    bar31.setFillColor(Color::Green);
                    win.draw(bar31);
                    win.display();
                    isApple = true;
                    appleClock.restart();
                    appleGrowth(funds, fundsInString, money, win, bar31, bar32, bar33, bar34, bar35, appleClock, appleModifier, isApple);
    };
        }
        }
        if(event.type == Event::MouseButtonPressed) {
            if(event.mouseButton.button == Mouse::Left) {
                Vector2i mousepos = Mouse::getPosition(win);
                if(signs4.getGlobalBounds().contains(static_cast<Vector2f>(mousepos))) {
                    bar41.setFillColor(Color::Green);
                    win.draw(bar41);
                    win.display();
                    isBanana = true;
                    bananaClock.restart();
                    bananaGrowth(funds, fundsInString, money, win, bar41, bar42, bar43, bar44, bar45, bananaClock, bananaModifier, isBanana);

    };
        }
        }
        if(event.type == Event::MouseButtonPressed) {
            if(event.mouseButton.button == Mouse::Left) {
                Vector2i mousepos = Mouse::getPosition(win);
                if(signs5.getGlobalBounds().contains(static_cast<Vector2f>(mousepos))) {
                    bar51.setFillColor(Color::Green);
                    win.draw(bar51);
                    win.display();
                    isCherry = true;
                    cherryClock.restart();
                    cherryGrowth(funds, fundsInString, money, win, bar51, bar52, bar53, bar54, bar55, cherryClock, cherryModifier, isCherry);
    };
        }
        } if(event.type = Event::MouseButtonPressed) {
            if(event.mouseButton.button == Mouse::Left) {
                Vector2i mousepos = Mouse::getPosition(win);
                if(shop.getGlobalBounds().contains(static_cast<Vector2f>(mousepos))) {
                    win.clear();
                    isPressed = true;
                    drawShop(win);
                   
    };
        }
        } if (Keyboard::isKeyPressed(Keyboard::Left) &&
        Keyboard::isKeyPressed(Keyboard::Right) &&
        Keyboard::isKeyPressed(Keyboard::Up)) {
        win.clear();
        eesound.play();
        ee = true;
         
        Clock c; // Start the clock when ee becomes true

        // Loop to wait for 3 seconds
        while (ee) {
            if (c.getElapsedTime().asSeconds() >= 3) {
                ee = false; // Stop the flag after 3 seconds
                eesound.stop(); // Stop the sound
            } else {
                win.clear();
                win.draw(rawrs);
                win.display();
            }
        }
    }

     
        
    }
        if(isBeet == true) {
            if(beetClock.getElapsedTime().asMilliseconds() >= beetModifier) {
                beetGrowth(funds, fundsInString, money, win, bar21, bar22, bar23, bar24, bar25, beetClock, beetModifier, isBeet);
            }
        };

        if(isAvo == true) {
            if(avoClock.getElapsedTime().asMilliseconds() >= avoModifier) {
                avoGrowth(funds, fundsInString, money, win, bar, bar1, bar2, bar3, bar4, avoClock, isAvo, avoModifier);
            }
        }
        if(isApple == true) {
            if(appleClock.getElapsedTime().asMilliseconds() >= appleModifier) {
                appleGrowth(funds, fundsInString, money, win, bar31, bar32, bar33, bar34, bar35, appleClock, appleModifier, isApple);
            }
        }

        if(isBanana == true) {
            if(bananaClock.getElapsedTime().asMilliseconds() >= bananaModifier) {
                bananaGrowth(funds, fundsInString, money, win, bar41, bar42, bar43, bar44, bar45, bananaClock, bananaModifier, isBanana);
            }
        }

        if(isCherry == true) {
            if(cherryClock.getElapsedTime().asMilliseconds() >= cherryModifier) {
                appleGrowth(funds, fundsInString, money, win, bar51, bar52, bar53, bar54, bar55, cherryClock, cherryModifier, isCherry);
            }
        }
        if(isPressed == true) {
            drawShop(win);
            isPressed = false;
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
        win.draw(bar);
        win.draw(bar1);
        win.draw(bar2);
        win.draw(bar3);
        win.draw(bar4);
        win.draw(bar21);
        win.draw(bar22);
        win.draw(bar23);
        win.draw(bar24);
        win.draw(bar25);
        win.draw(bar31);
        win.draw(bar32);
        win.draw(bar33);
        win.draw(bar34);
        win.draw(bar35);
        win.draw(bar41);
        win.draw(bar42);
        win.draw(bar43);
        win.draw(bar44);
        win.draw(bar45);
        win.draw(bar51);
        win.draw(bar52);
        win.draw(bar53);
        win.draw(bar54);
        win.draw(bar55);
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
        win.display();

        
    }

    return 0;
};


