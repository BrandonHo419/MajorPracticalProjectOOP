#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <chrono>
#include <iostream>
#include <sstream>

#include "Character.h"
#include "GridMap.h"
#include "UI.h"
#include "Coin.h"
#include "Watermelon.h"
#include "Peas.h"
#include "Beets.h"
#include "Tomatoes.h"
#include "Asparagus.h"

int main() {
  // Window setup
  sf::RenderWindow window(sf::VideoMode(1920, 1080), "Grid Map and UI");
  window.setFramerateLimit(60);

  // Character
  Character player({100.0f, 100.0f});
  float charWaitTime = 0.1f; // animation per frame time also growth for plants

  // Coin
  Coin coin({400.0f, 25.0f});
  float coinWaitTime = 0.1f;

  // Watermelon
  Watermelon watermelon({1000.0f, 225.0f});
  float watermelonWaitTime = 6.5f; 

  // Peas
  Peas peas({400.0f, 225.0f});
  float peasWaitTime = 3.5f;

  // Beet
  Beets beet({600.0f, 225.0f});
  float beetWaitTime = 4.5f;

  // Tomato
  Tomatoes tomato({800.0f, 225.0f});
  float tomatoWaitTime = 5.5f;

  // Asparagus
  Asparagus asparagus({200.0f, 225.0f});
  float asparagusWaitTime = 2.5f;

  // Timepoint for delta time management (possibly change to int clock)
  auto tp = std::chrono::steady_clock::now();

  // Grid initialising
  float gridSizeF = 75.0f;
  unsigned gridSizeU = static_cast<unsigned>(gridSizeF);
  int const mapSizeX = 24;
  int const mapSizeY = 12;
  float const gridOffsetX = 50.0f;
  float const gridOffsetY = 150.0f;

  // Background texture
  sf::Texture backgroundTexture;
  if (!backgroundTexture.loadFromFile("Grass Background.jpg")) {
    std::cerr << "Error loading background texture" << std::endl;
    return -1;
  }
  sf::Sprite backdrop(backgroundTexture);
  backdrop.setScale(1920.f / backgroundTexture.getSize().x,
                    1080.f / backgroundTexture.getSize().y);

  // Create grid map and UI
  GridMap grid(gridSizeF, gridSizeU, mapSizeX, mapSizeY, gridOffsetX,
               gridOffsetY);
  UI ui("Albertson.ttf", sf::Vector2f(20.f, 20.f));

  // Mouse position variables
  sf::Vector2i mousePosWindow;
  sf::Vector2u mousePosGrid;

  while (window.isOpen()) {
    // Event handling
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
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

    // Update mouse position
    mousePosWindow = sf::Mouse::getPosition(window);
    grid.updateMouseGridPosition(mousePosWindow, mousePosGrid);


    // Update tile selector and UI and Player
    player.Update(dt, charWaitTime);
    coin.Update(dt, coinWaitTime);
    watermelon.Update(dt, watermelonWaitTime);
    peas.Update(dt, peasWaitTime);
    beet.Update(dt, beetWaitTime);
    tomato.Update(dt, tomatoWaitTime);
    asparagus.Update(dt, asparagusWaitTime);
    grid.updateTileSelector(mousePosGrid);
    ui.updateText(mousePosWindow, mousePosGrid);

    // Render
    window.clear();
    window.draw(backdrop);
    grid.draw(window);
    watermelon.Draw(window);
    peas.Draw(window);
    beet.Draw(window);
    tomato.Draw(window);
    asparagus.Draw(window);
    coin.Draw(window);
    player.Draw(window);
    ui.draw(window);
    window.display();
  }

  return 0;
}