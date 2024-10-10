#include "Text.h"
#include <sstream>

Text2::Text2(const std::string& fontFile, const sf::Vector2f& position) {
    if (!font.loadFromFile(fontFile)) {
        throw std::runtime_error("Failed to load font");
    }

    text.setFont(font);
    text.setPosition(position);
}

void Text2::updateText(Player& player, const std::string& string, int typeOfUpdate) {
    std::stringstream ss;
    if (typeOfUpdate == 0) {
        ss << " " << player.getMoney() << "\n";
        text.setCharacterSize(120);
        text.setFillColor(sf::Color::Yellow);
    } else {
        ss << "" << string << "\n";
        text.setCharacterSize(80);
        text.setFillColor(sf::Color::White);
    }
    text.setString(ss.str());
}

void Text2::draw(sf::RenderWindow& window) {
    window.draw(text);
}