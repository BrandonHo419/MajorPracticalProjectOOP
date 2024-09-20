#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>

using namespace std;
using namespace sf;

void clickTest() {
    cout << "Click Testing Successful" << endl;
};

int main() {
    

    RenderWindow win(VideoMode(1280, 720), "Super Awesome Plant Game :3");

    // Load textures
    Texture bd; // create something for backdrop
    Texture minibd;
    Texture avo;
    Texture beet;
    Texture apple;
    Texture banana;
    Texture cherry;
    // End loading textures

    // load from file
    bd.loadFromFile("bd1.jpg");
    minibd.loadFromFile("minibd.jpg");
    avo.loadFromFile("avocado.png");
    beet.loadFromFile("beetroot.png");
    apple.loadFromFile("apple.png");
    banana.loadFromFile("banana.png");
    cherry.loadFromFile("cherry.png");
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
    Sprite buttonTest(minibd);
    Sprite avocado(avo);
    Sprite beetroot(beet);
    Sprite apples(apple);
    Sprite bananas(banana);
    Sprite cherries(cherry);

    // End sprites

    // Set Scales
    minibackdrop.setScale(2.0, 1.5);
    buttonTest.setScale(0.25, 0.15);
    avocado.setScale(0.2, 0.2);
    beetroot.setScale(0.2, 0.2);
    apples.setScale(0.2, 0.2);
    bananas.setScale(0.2, 0.2);
    cherries.setScale(0.2, 0.2);
    //End scales

    // Set positions
    FloatRect minibackdropbounds = minibackdrop.getLocalBounds(); // Get the local boudns with FloatRect which gets dimension (width and height)
    minibackdrop.setOrigin(minibackdropbounds.width/2, minibackdropbounds.height/2); // this ensures it calculates relative to the center
    minibackdrop.setPosition(win.getSize().x/2, win.getSize().y/2); // sets the position

    // New position
    buttonTest.setPosition(100, 100);
    avocado.setPosition(150, 100);
    beetroot.setPosition(150, 175);
    apples.setPosition(150, 250);
    bananas.setPosition(150, 325);
    cherries.setPosition(150, 400);
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
                if(buttonTest.getGlobalBounds().contains(static_cast<Vector2f>(mousepos))) { // returns a rectangle of bounds and static_cast converts 2i to 2f
                    clickTest(); // calls function
                }
            }
        }
    };

        // Create base rectangle shapes


        win.clear();
        win.draw(backdrop);
        win.draw(minibackdrop);
        win.draw(buttonTest);
        win.draw(avocado);
        win.draw(beetroot);
        win.draw(apples);
        win.draw(bananas);
        win.draw(cherries);
        win.display();
    }

    return 0;
};

