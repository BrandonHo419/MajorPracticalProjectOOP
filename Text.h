#ifndef TEXT_H
#define TEXT_H
#include <SFML/Graphics.hpp>
#include <string>

class Text {
public:
    Text(const std::string& fontFile, const sf::Vector2f& position, int fontSize); // Initialies the text 
    void updateText(const std::string& string); // Updates the text
    void updateTextInstructions(const std::string& string); // Updates the text (game isntructions)
    void draw(sf::RenderWindow& window); // Draws the text

private:
    sf::Font font;
    sf::Text text;
};

#endif