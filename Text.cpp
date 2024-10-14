#include "Text.h"

#include <iomanip>
#include <sstream>

Texts::Texts(const std::string& fontFile, const sf::Vector2f& position,
             int fontSize) {
  if (!font.loadFromFile(fontFile)) {
    throw std::runtime_error("Failed to load font");
  }
  text.setCharacterSize(fontSize);
  text.setFont(font);
  text.setPosition(position);
}

void Texts::updateText(const std::string& string) {
  std::stringstream ss;
  ss << "" << string << "\n";
  text.setFillColor(sf::Color::White);
  text.setString(ss.str());
}

void Texts::updateTextInstructions(const std::string& string) {
  std::string currentText = text.getString();  // Get the current text
  currentText += string + "\n";  // Append the new text with a newline
  text.setFillColor(sf::Color::White);
  text.setString(currentText);  // Set the updated text
}

void Texts::draw(sf::RenderWindow& window) { window.draw(text); }