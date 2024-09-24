#include <SFML/Graphics.hpp>
#include "Shop.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <sstream>


using namespace sf;

int main() {
    Shop Bob;
    RenderWindow game(VideoMode(1280, 720), "Shop");
    
    Text text;
    Font font; 
    if(!font.loadFromFile("Albertson.ttf")) {
        return -1;
    }

    text.setCharacterSize(30);
    text.setFillColor(Color::White);
    text.setFont(font);
    text.setPosition(20.f, 20.f);

    Texture back;
    Texture fore;
    Texture fertiliser;
    Texture house;
    Texture worker;
    Texture board1;
    Texture board2;
    Texture board3;
    Texture shopBoard;

    // Load textures correctly
    if (!back.loadFromFile("bd1.jpg")) {
        std::cout << "Error loading background texture\n";
        return -1;
    }

    if (!fore.loadFromFile("minibd.jpg")) {
        std::cout << "Error loading foreground texture\n";
        return -1;
    }

    if (!board1.loadFromFile("sign.png")) {
        std::cout << "Error loading sign\n";
    }

    if (!board2.loadFromFile("sign.png")) {
        std::cout << "Error loading sign\n";
    }

    if (!board3.loadFromFile("sign.png")) {
        std::cout << "Error loading sign\n";
    }

    if (!fertiliser.loadFromFile("file.png")) {
        std::cout << "Error loading fertiliser texture\n";
        return -1;
    }

    if (!house.loadFromFile("Ghouse.png")) {
        std::cout << "Error loading greenhouse texture\n";
        return -1;
    }

    if (!worker.loadFromFile("farmer.png")) {
        std::cout << "Error loading greenhouse texture\n";
        return -1;
    }

    if (!shopBoard.loadFromFile("shop.png")) {
        std::cout << "Error loading shop sign\n";
    }

   


    Sprite background(back);
    Sprite foreground(fore);
    Sprite sign1(board1);
    Sprite sign2(board2);
    Sprite sign3(board3);
    Sprite shopSign(shopBoard);
    Sprite fert(fertiliser);
    Sprite greenhouse(house);
    Sprite farmer(worker);

    // Set scale
    foreground.setScale(2.0, 1.5);
    fert.setScale(0.2f, 0.2f);
    greenhouse.setScale(0.35f, 0.35f);
    farmer.setScale(0.045, 0.045);
    shopSign.setScale(0.4, 0.4);
    sign1.setScale(0.4, 0.4);
    sign2.setScale(0.4, 0.4);
    sign3.setScale(0.4, 0.4);

    // Set positions and origins
    FloatRect minibackdropbounds = foreground.getLocalBounds();
    foreground.setOrigin(minibackdropbounds.width / 2, minibackdropbounds.height / 2);
    foreground.setPosition(game.getSize().x / 2, game.getSize().y / 2);

    FloatRect fertDimensions = fert.getLocalBounds();
    fert.setOrigin(fertDimensions.width / 2, fertDimensions.height / 2);
    fert.setPosition(game.getSize().x/2 -458, game.getSize().y/2 - 20);

    FloatRect greenhouseDimensions = greenhouse.getLocalBounds();
    greenhouse.setOrigin(greenhouseDimensions.width / 2, greenhouseDimensions.height / 2);
    greenhouse.setPosition(game.getSize().x/2, game.getSize().y/2 - 20);

    FloatRect workerDimensions = farmer.getLocalBounds();
    farmer.setOrigin(workerDimensions.width / 2, workerDimensions.height / 2);
    farmer.setPosition(game.getSize().x/2 + 458, game.getSize().y/2 - 20);

    FloatRect signDimensions = sign1.getLocalBounds();
    sign1.setOrigin(signDimensions.width / 2, signDimensions.height / 2);
    sign1.setPosition(game.getSize().x/2 -458, game.getSize().y/2 - 20);

    FloatRect signDimensions2 = sign2.getLocalBounds();
    sign2.setOrigin(signDimensions.width / 2, signDimensions.height / 2);
    sign2.setPosition(game.getSize().x/2, game.getSize().y/2 - 20);

    FloatRect signDimensions3 = sign3.getLocalBounds();
    sign3.setOrigin(signDimensions3.width / 2, signDimensions3.height / 2);
    sign3.setPosition(game.getSize().x/2 + 458, game.getSize().y/2 - 20);

    FloatRect shopDimensions2 = shopSign.getLocalBounds();
    shopSign.setOrigin(shopDimensions2.width / 2, shopDimensions2.height / 2);
    shopSign.setPosition(game.getSize().x/2, game.getSize().y/2 - 200);

    bool isPressed = false;

    while (game.isOpen()) {
        Event event;
        while (game.pollEvent(event)) {
            if (event.type == Event::Closed) {
                game.close();
            }

            // Check for mouse button press 
            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    // Get the mouse position relative to the window
                    Vector2i mousePosition = Mouse::getPosition(game);

                    // Check if the mouse position is within the bounds of the sprite
                    if (fert.getGlobalBounds().contains(Vector2f(mousePosition))) {
                        if (!isPressed) {
                            std::cout << "Fertiliser button clicked!" << std::endl;
                            Bob.purchaseFertiliser();

                            isPressed = true; // Set the flag to true when button is pressed
                        }
                    }

                    if (greenhouse.getGlobalBounds().contains(Vector2f(mousePosition))) {
                        if (!isPressed) {
                            std::cout << "Greenhouse button clicked!" << std::endl;
                            Bob.purchaseGreenhouse();
                            isPressed = true; // Set the flag to true when button is pressed
                        }
                    }

                    if (farmer.getGlobalBounds().contains(Vector2f(mousePosition))) {
                        if (!isPressed) {
                            std::cout << "Worker button clicked!" << std::endl;
                            Bob.purchaseWorkers();
                            isPressed = true; // Set the flag to true when button is pressed
                        }
                    }
                }
            }

            // Check for mouse button release 
            if (event.type == Event::MouseButtonReleased) {
                if (event.mouseButton.button == Mouse::Left) {
                    isPressed = false; // Reset the flag when the button is released
                }
            }
        }

        std::stringstream upgrades;
        upgrades << Bob.printItems() << "\n";
        text.setString(upgrades.str()); 

    
        game.clear(); // Clear the window
        game.draw(background); // Draw the background
        game.draw(foreground); // Draw the foreground
        game.draw(sign1);
        game.draw(sign2);
        game.draw(sign3);
        game.draw(shopSign);
        game.draw(fert); // Draw the fertiliser
        game.draw(greenhouse);
        game.draw(farmer);
        game.draw(text);
        game.display(); // Display the current frame    
    }
    return 0;
}

   