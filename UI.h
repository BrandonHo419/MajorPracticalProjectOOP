#ifndef UI_H
#define UI_H
#include <SFML/Graphics.hpp>
#include <string>

class UI {
public:
    UI(const std::string& fontFile, const sf::Vector2f& position);
    void updateText(const sf::Vector2i& mousePosWindow, const sf::Vector2u& mousePosGrid);
    void draw(sf::RenderWindow& window);

private:
    sf::Font font;
    sf::Text text;
};

#endif
