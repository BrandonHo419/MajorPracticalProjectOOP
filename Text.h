#ifndef TEXT_H
#define TEXT_H
#include <SFML/Graphics.hpp>
#include <string>
#include "Player.h"

class Text {
public:
    Text(const std::string& fontFile, const sf::Vector2f& position); // Initialies the text 
    void updateText(Player& player, const std::string& string, int typeOfUpdate); // Updates the text
    void draw(sf::RenderWindow& window); // Draws the text

private:
    sf::Font font;
    sf::Text text;
};

#endif
