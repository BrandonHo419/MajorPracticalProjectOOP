#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

int main() {
    RenderWindow game(VideoMode(1280, 720), "Button");

    Texture avo;
    if (!avo.loadFromFile("avocado.png")) {
        std::cout << "Error loading background texture \n";
        return -1; 
    }

    Sprite avocado(avo);
    avocado.setScale(0.2f, 0.2f);
    avocado.setPosition(250.f, 200.f);

    bool isPressed = false;

    while (game.isOpen()) {
        Event event;
        while (game.pollEvent(event)) {
            if (event.type == Event::Closed) {
                game.close(); // Close the window 
            }

            // Check for mouse button press 
            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    // Get the mouse position relative to the window
                    Vector2i mousePosition = Mouse::getPosition(game);

                    // Check if the mouse position is within the bounds of the sprite
                    if (avocado.getGlobalBounds().contains(Vector2f(mousePosition))) {
                        if (!isPressed) {
                            std::cout << "Avocado button clicked!" << std::endl;
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

        game.clear(); // Clear the window
        game.draw(avocado); // Draw the sprite
        game.display(); // Display the current frame
    }

    return 0;
}