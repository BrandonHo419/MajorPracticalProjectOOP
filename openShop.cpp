#include <SFML/Graphics.hpp>
#include "scroll.cpp"
#include <iostream>
using namespace sf;

int main() {
    RenderWindow game(VideoMode(1280, 720), "Shop");
    
    Texture button;
    if (!button.loadFromFile("scrollsandblocks.png")) {
        return -1;
    }

    Sprite scrollButton(button);
    scrollButton.setPosition(game.getSize().x / 1.35 + 200, game.getSize().y / 1.9 + 220);
    scrollButton.setTextureRect(IntRect(192, 150, 32, 40));
    scrollButton.setScale(2, 2);
    scroll scroll({static_cast<float>(game.getSize().x) / 2, (static_cast<float>(game.getSize().y) / 2)-150}, 0.4f);
    

    Clock clock;
    bool isPressed = false; 
    bool scrollOpened = false;
    while (game.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        Event event;

        while (game.pollEvent(event)) {
            if (event.type == Event::Closed) {
                game.close();
            }

            // Handle mouse button press
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                Vector2i mousePosition = Mouse::getPosition(game);
                Vector2f worldPosition = game.mapPixelToCoords(mousePosition);

                // Check if the mouse position is within the bounds of the button sprite
                if (scrollButton.getGlobalBounds().contains(Vector2f(worldPosition)) && !isPressed) {
                    isPressed = true;

                    // Toggle open/close state based on the current state
                    if (!scrollOpened) {
                        scroll.openScroll();  // Open the scroll
                        scrollOpened = true;
                    } else {
                        scroll.closeScroll(); // Close the scroll
                        scrollOpened = false;
                    }
                }
            }

            // Handle mouse button release
            if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
                isPressed = false; // Reset the flag when the button is released
            }
        }

        scroll.update(deltaTime);
        game.clear();
        scroll.draw(game);
        game.draw(scrollButton);
        game.display();
    }
}