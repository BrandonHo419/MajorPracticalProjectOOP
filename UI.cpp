#include "UI.h"

#include <sstream>

UI::UI(const std::string& fontFile, const sf::Vector2f& position, int imageID, const sf::IntRect& spritepos) {
  if (!texture.loadFromFile(fontFile)) {
    throw std::runtime_error("Failed to load font");
  }
  sprite.setTexture(texture);
  sprite.setTextureRect(spritepos);
  switch (imageID) {
    case 0: // Create Players Balance Background
      sprite.setPosition(position);
      sprite.setScale(11, 4);
      break;
    case 1: // Create Fences
      fences.resize(38);
      for (int i = 0; i <10; i++) { // Top
        fences[i] = (sf::Sprite(texture, sf::IntRect(32,0,32,32)));
        fences[i].setPosition(position.x + i * 96.f, position.y);
        fences[i].setScale(3,3);
      }
      for (int i = 0; i <10; i++) { // Bottom
        fences[i+10] = (sf::Sprite(texture, sf::IntRect(32,0,32,32)));
        fences[i+10].setPosition(position.x + i * 96.f, (96.f * 10) - 32);
        fences[i+10].setScale(3,3);
      }
      for (int i = 0; i <7; i++) { // Left
        fences[i+20] = (sf::Sprite(texture, sf::IntRect(32,32,32,32)));
        fences[i+20].setPosition(0, ((96.f*3) + i * 96.f) - 32);
        fences[i+20].setScale(3,3);
      } 
      for (int i = 0; i <7; i++) { // Right
        fences[i+27] = (sf::Sprite(texture, sf::IntRect(32,32,32,32)));
        fences[i+27].setPosition(11*96.f, ((96.f*3) + i * 96.f) - 32);
        fences[i+27].setScale(3,3);
      }
      fences[34] = (sf::Sprite(texture, sf::IntRect(0,32*2,32,32))); // Top Left Corner
      fences[34].setPosition(0, (96.f*2) - 32);
      fences[34].setScale(3,3);
      fences[35] = (sf::Sprite(texture, sf::IntRect(0,32*4,32,32))); // Bottom Left Corner
      fences[35].setPosition(0, (96.f*10) - 32);
      fences[35].setScale(3,3);
      fences[36] = (sf::Sprite(texture, sf::IntRect(32*2,32*2,32,32))); // Top Right Corner
      fences[36].setPosition(96.f*11, (96.f*2) - 32);
      fences[36].setScale(3,3);
      fences[37] = (sf::Sprite(texture, sf::IntRect(32*2,32*4,32,32))); // Bottom Right Corner
      fences[37].setPosition(96.f*11, (96.f*10) - 32);
      fences[37].setScale(3,3);
      break;
    case 2: // Buttons
      sprite.setPosition(position);
      sprite.setScale(3, 3);
      break;
    case 3: // Scroll
      sprite.setPosition(position);
      sprite.setScale(7, 9);
    case 4: // Greenhouse
      sprite.setPosition(position);
      sprite.setScale(0.4, 0.4);
    default:
      break;
  }
}

void UI::draw(sf::RenderWindow& window, int imageID) 
{ 
  if (imageID == 1) { 
    for (auto& fence : fences) {
      window.draw(fence);
    }
  } else {
    window.draw(sprite);
  }
}

void UI::buttonPressed(int buttonType) {
  if (buttonType == 0) {
    sprite.setTextureRect(sf::IntRect(0,32,32,32));
  } else {
    sprite.setTextureRect(sf::IntRect(32,32,64,32));
  }
}

void UI::buttonNotPressed(int buttonType) {
  if (buttonType == 0) {
    sprite.setTextureRect(sf::IntRect(0,0,32,32));
  } else {
    sprite.setTextureRect(sf::IntRect(32,0,64,32));
  }
}

sf::FloatRect UI::getGlobalBounds() const {
  return sprite.getGlobalBounds();
}

bool UI::getWithinDimensions(const UI& button, sf::Vector2f worldPosition) {
  return button.getGlobalBounds().contains(worldPosition);
}

void UI::scrollBig() {
  sprite.setTextureRect(sf::IntRect(32*7,32*7,96,96));
  sprite.setScale(7, 9);
}

void UI::scrollSmall() {
  sprite.setTextureRect(sf::IntRect(32*7,32*5,96,32));
  sprite.setScale(7, 9);
}