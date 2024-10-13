#ifndef UI_H
#define UI_H
#include <SFML/Graphics.hpp>
#include <string>
#include "GridMap.h"

class UI {
public:
    UI(const std::string& fontFile, const sf::Vector2f& position, int imageID, const sf::IntRect& spritepos); // Sets the texture for static sprites
    void draw(sf::RenderWindow& window, int imageID);  // Draws the sprite
    void buttonPressed(const std::string& buttonType); // Changes the texture if the button is pressed
    void buttonNotPressed(const std::string& buttonType); // Changes the texture if the button is not pressed
    bool getWithinDimensions(const UI& button, sf::Vector2f worldPosition); // Checks if the mouse is within the bounds of the sprite
    void scrollSmall(); // Changes the scroll to a small version
    void scrollBig(); // Changes the scroll to a big version
    sf::FloatRect getGlobalBounds() const; // Retrieves globalBounds()

private:
    sf::Sprite sprite;
    sf::Texture texture;
    std::vector<sf::Sprite> fences; // Vector for the fences
};

#endif
