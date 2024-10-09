#include <SFML/Graphics.hpp>
#include "scroll.cpp"
#include "Shop.h"
#include "Player.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace sf;

int main() {
    RenderWindow game(VideoMode(1280, 720), "Shop");
    Shop Bob;
    
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
    Texture fertiliser;
    Texture house;
    Texture worker;
    Texture board1;
    Texture board2;
    Texture board3;
    Texture shopBoard;

    // Load textures correctly
    if (!back.loadFromFile("bd1.jpg") ||  !board1.loadFromFile("sign.png") ||
        !board2.loadFromFile("sign.png")|| !board3.loadFromFile("sign.png") || !fertiliser.loadFromFile("file.png") ||
        !house.loadFromFile("Ghouse.png") || !worker.loadFromFile("farmer.png") || !shopBoard.loadFromFile("shop.png")) {
        std::cout << "Error loading background textures\n";
        return -1;
    }

    Sprite background(back);
    Sprite sign1(board1);
    Sprite sign2(board2);
    Sprite sign3(board3);
    Sprite shopSign(shopBoard);
    Sprite fert(fertiliser);
    Sprite greenhouse(house);
    Sprite farmer(worker);

    // Set scale
    fert.setScale(0.2f, 0.2f);
    greenhouse.setScale(0.35f, 0.35f);
    farmer.setScale(0.045, 0.045);
    shopSign.setScale(0.4, 0.4);
    sign1.setScale(0.4, 0.4);
    sign2.setScale(0.4, 0.4);
    sign3.setScale(0.4, 0.4);



    // Set positions and origins
    FloatRect fertDimensions = fert.getLocalBounds();
    fert.setOrigin(fertDimensions.width / 2, fertDimensions.height / 2);
    fert.setPosition(game.getSize().x/2 -325, game.getSize().y/2 - 20);

    FloatRect greenhouseDimensions = greenhouse.getLocalBounds();
    greenhouse.setOrigin(greenhouseDimensions.width / 2, greenhouseDimensions.height / 2);
    greenhouse.setPosition(game.getSize().x/2, game.getSize().y/2 - 20);

    FloatRect workerDimensions = farmer.getLocalBounds();
    farmer.setOrigin(workerDimensions.width / 2, workerDimensions.height / 2);
    farmer.setPosition(game.getSize().x/2 + 285, game.getSize().y/2 - 20);

    FloatRect signDimensions = sign1.getLocalBounds();
    sign1.setOrigin(signDimensions.width / 2, signDimensions.height / 2);
    sign1.setPosition(game.getSize().x/2 -325, game.getSize().y/2 - 20);

    FloatRect signDimensions2 = sign2.getLocalBounds();
    sign2.setOrigin(signDimensions.width / 2, signDimensions.height / 2);
    sign2.setPosition(game.getSize().x/2, game.getSize().y/2 - 20);

    FloatRect signDimensions3 = sign3.getLocalBounds();
    sign3.setOrigin(signDimensions3.width / 2, signDimensions3.height / 2);
    sign3.setPosition(game.getSize().x/2 + 285, game.getSize().y/2 - 20);

    FloatRect shopDimensions2 = shopSign.getLocalBounds();
    shopSign.setOrigin(shopDimensions2.width / 2, shopDimensions2.height / 2);
    shopSign.setPosition(game.getSize().x/2, game.getSize().y/2 - 175);

    
    Texture button;
    if (!button.loadFromFile("scrollsandblocks.png")) {
        return -1;
    }

    Sprite scrollButton(button);
    scrollButton.setPosition(game.getSize().x / 1.35 + 200, game.getSize().y / 1.9 + 220);
    scrollButton.setTextureRect(IntRect(192, 150, 32, 40));
    scrollButton.setScale(2, 2);
    scroll scroll({static_cast<float>(game.getSize().x) / 2, (static_cast<float>(game.getSize().y) / 2)-150}, 0.3f);
   
    Clock clock;
    while (game.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        Event event;

        while (game.pollEvent(event)) {
            if (event.type == Event::Closed) {
                game.close();
            }

            
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                Vector2i mousePosition = Mouse::getPosition(game);
                Vector2f worldPosition = game.mapPixelToCoords(mousePosition);

                // Check if the mouse position is within the bounds of the button sprite
                if (scrollButton.getGlobalBounds().contains(Vector2f(worldPosition)) && !Bob.checkIsPressed()) {
                    Bob.setIsPressed(true);

                    // Toggle open/close state based on the current state
                    if (!scroll.isOpen()) {
                        scroll.openScroll();  // Open the scroll
                    } else {
                        scroll.closeScroll(); // Close the scroll
                    }
                }
            }

            if (scroll.isOpen() == true && scroll.getLastFrame() == true) {
                 // Check for mouse button press 
                if (event.type == Event::MouseButtonPressed) {
                    Bob.setEnoughMoney(true);
                    if (event.mouseButton.button == Mouse::Left) {
                        // Get the mouse position relative to the window
                        Vector2i mousePosition = Mouse::getPosition(game);
                        Vector2f worldPosition = game.mapPixelToCoords(mousePosition);

                        // Check if the mouse position is within the bounds of the sprite
                        if (fert.getGlobalBounds().contains(Vector2f(worldPosition))) {
                            if (!Bob.checkIsPressed()) {
                                std::cout << "Fertiliser button clicked!" << std::endl;
                                if(!Bob.purchaseFertiliser()) {
                                    Bob.setEnoughMoney(false);
                                }
                                Bob.setIsPressed(true); // Set the flag to true when button is pressed
                            }
                        }

                        if (greenhouse.getGlobalBounds().contains(Vector2f(worldPosition))) {
                            if (!Bob.checkIsPressed()) {
                                std::cout << "Greenhouse button clicked!" << std::endl;
                                if(!Bob.purchaseGreenhouse()) {
                                    Bob.setEnoughMoney(false);
                                }
                                Bob.setIsPressed(true); // Set the flag to true when button is pressed
                            }
                        }

                        if (farmer.getGlobalBounds().contains(Vector2f(worldPosition))) {
                            if (!Bob.checkIsPressed()) {
                                std::cout << "Worker button clicked!" << std::endl;
                                if (!Bob.purchaseWorkers()) {
                                    Bob.setEnoughMoney(false);
                                }
                                Bob.setIsPressed(true); // Set the flag to true when button is pressed
                            }
                        }
                    }
                }
                std::stringstream upgrades;
                upgrades << Bob.printItems(Bob.checkEnoughMoney(), Bob.getFertiliserLevel(), Bob.getGreenhouseLevel(), Bob.getWorkersLevel()) << "\n";
                text.setString(upgrades.str()); 
            }

        // Handle mouse button release
        if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
            Bob.setIsPressed(false); // Reset the flag when the button is released
        }
    }

    scroll.update(deltaTime);
    game.clear();
    scroll.draw(game);
    game.draw(background);
    game.draw(scrollButton);
    if (scroll.isOpen()) {
        scroll.draw(game);
        game.draw(scrollButton);
        game.draw(text);
    
        if (scroll.getLastFrame()) {
            game.draw(sign1);
            game.draw(sign2);
            game.draw(sign3);
            game.draw(shopSign);
            game.draw(fert);
            game.draw(greenhouse);
            game.draw(farmer);
        }
    }
    game.display();
    }
}