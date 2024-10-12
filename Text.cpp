#include "Text.h"
#include <iomanip>
#include <sstream>

Text::Text(const std::string& fontFile, const sf::Vector2f& position, int fontSize) {
    if (!font.loadFromFile(fontFile)) {
        throw std::runtime_error("Failed to load font");
    }
    text.setCharacterSize(fontSize);
    text.setFont(font);
    text.setPosition(position);
}

void Text::updateText(const std::string& string) {
    std::stringstream ss;
    ss << "" << string << "\n";
    text.setFillColor(sf::Color::White);
    text.setString(ss.str());
}

void Text::draw(sf::RenderWindow& window) {
    window.draw(text);
}