#include "Fences.h"

Fences::Fences(const std::string& textureFile, const sf::Vector2f& position,
               const sf::Vector2f& scaleSize, const sf::IntRect& spriteRect)
    : UIElement(textureFile, position, scaleSize, spriteRect) {
  fences.resize(38);
  for (int i = 0; i < 10; i++) {  // Top
    fences[i] = (sf::Sprite(texture, sf::IntRect(32, 0, 32, 32)));
    fences[i].setPosition(position.x + i * 96.f, position.y);
    fences[i].setScale(scaleSize.x, scaleSize.y);
  }
  for (int i = 0; i < 10; i++) {  // Bottom
    fences[i + 10] = (sf::Sprite(texture, sf::IntRect(32, 0, 32, 32)));
    fences[i + 10].setPosition(position.x + i * 96.f, (96.f * 10) - 32);
    fences[i + 10].setScale(scaleSize.x, scaleSize.y);
  }
  for (int i = 0; i < 7; i++) {  // Left
    fences[i + 20] = (sf::Sprite(texture, sf::IntRect(32, 32, 32, 32)));
    fences[i + 20].setPosition(0, ((96.f * 3) + i * 96.f) - 32);
    fences[i + 20].setScale(scaleSize.x, scaleSize.y);
  }
  for (int i = 0; i < 7; i++) {  // Right
    fences[i + 27] = (sf::Sprite(texture, sf::IntRect(32, 32, 32, 32)));
    fences[i + 27].setPosition(11 * 96.f, ((96.f * 3) + i * 96.f) - 32);
    fences[i + 27].setScale(scaleSize.x, scaleSize.y);
  }
  fences[34] = (sf::Sprite(texture, sf::IntRect(0, 32 * 2, 32, 32)));  // Top Left Corner
  fences[34].setPosition(0, (96.f * 2) - 32);
  fences[34].setScale(scaleSize.x, scaleSize.y);
  fences[35] = (sf::Sprite(texture, sf::IntRect(0, 32 * 4, 32, 32)));  // Bottom Left Corner
  fences[35].setPosition(0, (96.f * 10) - 32);
  fences[35].setScale(scaleSize.x, scaleSize.y);
  fences[36] = (sf::Sprite(texture, sf::IntRect(32 * 2, 32 * 2, 32, 32)));  // Top Right Corner
  fences[36].setPosition(96.f * 11, (96.f * 2) - 32);
  fences[36].setScale(scaleSize.x, scaleSize.y);
  fences[37] = (sf::Sprite(texture, sf::IntRect(32 * 2, 32 * 4, 32, 32)));  // Bottom Right Corner
  fences[37].setPosition(96.f * 11, (96.f * 10) - 32);
  fences[37].setScale(scaleSize.x, scaleSize.y);
};

void Fences::draw(sf::RenderWindow& window) { // Draws the fence
    for (auto& fence : fences) {
      window.draw(fence);
    }
};