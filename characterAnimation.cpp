#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <chrono>

#include "Character.h"

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

  Character player({100.0f, 100.0f});

  // Timepoint for delta time management (possibly change to int clock)
  auto tp = std::chrono::steady_clock::now();

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
    }

    // get dt
    float dt;
    {
      const auto newTp = std::chrono::steady_clock::now();
      dt = std::chrono::duration<float>(newTp - tp).count();
      tp = newTp;
    }

    // Handle the input
    sf::Vector2f direction = {0.0f, 0.0f};
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {  // Up
      direction.y -= 1.0f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {  // Down
      direction.y += 1.0f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {  // Left
      direction.x -= 1.0f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {  // Right
      direction.x += 1.0f;
    }

    player.SetDirection(direction);

    // Update Player
    player.Update(dt);

    // Clear the window
    window.clear();

    // Draw the character
    player.Draw(window);

    window.display();
  }

  return 0;
}