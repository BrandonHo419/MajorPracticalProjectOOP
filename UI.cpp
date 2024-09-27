#include "UI.h"
#include <sstream>

UI::UI(const std::string& fontFile, const sf::Vector2f& position) {
    if (!font.loadFromFile("Albertson.ttf")) {
        throw std::runtime_error("Failed to load font");
    }

    text.setFont(font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setPosition(position);
}

void UI::updateText(const sf::Vector2i& mousePosWindow, const sf::Vector2u& mousePosGrid) {
    std::stringstream ss;
    ss << "Window: " << mousePosWindow.y << " " << mousePosWindow.x << "\n"
       << "Grid: " << mousePosGrid.y << " " << mousePosGrid.x << "\n";
    text.setString(ss.str());
}

void UI::draw(sf::RenderWindow& window) {
    window.draw(text);
}