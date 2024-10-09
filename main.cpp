#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <chrono>
#include <iostream>
#include <sstream>

#include "Blueberries.h"
#include "Beets.h"
#include "Player.h"
#include "Coin.h"
#include "GridMap.h"
#include "Carrots.h"
#include "Tomatoes.h"
#include "Text.h"
#include "Strawberries.h"
#include "UI.h"
#include "Crop.h"

int main() {
  // Window setup
  sf::RenderWindow window(sf::VideoMode(1920, 1080), "Grid Map and UI");
  window.setFramerateLimit(60);

  // Player
  Player player({200.0f, 200.0f});
  float charWaitTime = 0.1f;  // animation per frame time also growth for plants

  // Grid initialising
  float gridSizeF = 96.0f;
  unsigned gridSizeU = static_cast<unsigned>(gridSizeF);
  int const mapSizeX = 10;
  int const mapSizeY = 7;
  float const gridOffsetX = 96.0f;
  float const gridOffsetY = 256.0f;

  // Coin
  Coin coin({270.0f, 40.0f});
  float coinWaitTime = 0.1f;

  // Timepoint for delta time management 
  auto tp = std::chrono::steady_clock::now();

  // Background texture
  sf::Texture backgroundTexture;
  if (!backgroundTexture.loadFromFile("TileableBackGround.png")) {
    std::cerr << "Error loading background texture" << std::endl;
    return -1;
  }
  sf::Sprite backdrop(backgroundTexture);
  backdrop.setScale(1920.f / backgroundTexture.getSize().x, 1080.f / backgroundTexture.getSize().y);

  // Create grid map, text, buttons and scoll
  GridMap grid(gridSizeF, gridSizeU, mapSizeX, mapSizeY, gridOffsetX, gridOffsetY);
  Text balance("windows_command_prompt.ttf", sf::Vector2f(360.f, 0.f));
  Text crop("windows_command_prompt.ttf", sf::Vector2f(1250.f, 22.f));
  Text shop("windows_command_prompt.ttf", sf::Vector2f(1450.f, 22.f));
  Text more("windows_command_prompt.ttf", sf::Vector2f(1650.f, 22.f));
  UI balanceBackground("scrollsandblocks.png", sf::Vector2f(240.f, 20.f), 0, sf::IntRect(32, 0, 64, 32));
  UI fence("fence.png", sf::Vector2f(96.f, 160.f), 1, sf::IntRect(32, 0, 32, 32));
  UI tomatoesButton("crops2.png", sf::Vector2f(1300.f, 288.f), 2, sf::IntRect(32*28, 32*10, 32, 32));
  UI tomatoesBackground("scrollsandblocks.png",sf::Vector2f(1300.f, 288.f), 2, sf::IntRect(0, 0, 32, 32));
  UI blueberriesButton("crops2.png", sf::Vector2f(1300.f, 388.f), 2, sf::IntRect(32*23, 32*10, 32, 32));
  UI blueberriesBackground("scrollsandblocks.png",sf::Vector2f(1300.f, 388.f), 2, sf::IntRect(0, 0, 32, 32));
  UI carrotsButton("crops2.png", sf::Vector2f(1300.f, 488.f), 2, sf::IntRect(32*6, 0, 32, 32));
  UI carrotsBackground("scrollsandblocks.png",sf::Vector2f(1300.f, 488.f), 2, sf::IntRect(0, 0, 32, 32));
  UI beetsButton("crops2.png", sf::Vector2f(1300.f, 588.f), 2, sf::IntRect(32*9, 0, 32, 32));
  UI beetsBackground("scrollsandblocks.png",sf::Vector2f(1300.f, 588.f), 2, sf::IntRect(0, 0, 32, 32));
  UI strawberriesButton("crops2.png", sf::Vector2f(1300.f, 688.f), 2, sf::IntRect(32*20, 32*10, 32, 32));
  UI strawberriesBackground("scrollsandblocks.png",sf::Vector2f(1300.f, 688.f), 2, sf::IntRect(0, 0, 32, 32));
  UI cropBackground("scrollsandblocks.png",sf::Vector2f(1230.f, 32.f), 2, sf::IntRect(32, 0, 64, 32));
  UI shopBackground("scrollsandblocks.png",sf::Vector2f(1430.f, 32.f), 2, sf::IntRect(32, 0, 64, 32));
  UI moreBackground("scrollsandblocks.png",sf::Vector2f(1630.f, 32.f), 2, sf::IntRect(32, 0, 64, 32));
  UI scroll("scrollsandblocks.png", sf::Vector2f(1200.f, 160.f), 3, sf::IntRect(32*7, 32*7, 96, 96));

  // Mouse and character position variables
  sf::Vector2i mousePosWindow;
  sf::Vector2f worldPosition;
  sf::Vector2u mousePosGrid = {0, 0};
  sf::Vector2u charPosGrid;
  // Boolean variables for buttons
  bool plantTomatoes = false;
  bool plantBlueberries = false;
  bool plantCarrots = false;
  bool plantBeets = false;
  bool plantStrawberries = false;
  bool plantCrop = false;
  bool resetFrame = false;
  bool openShop = false;
  bool openCrop = false;
  bool openMore = false;
  while (window.isOpen()) {
    // Event handling
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
    // Update mouse position
    mousePosWindow = sf::Mouse::getPosition(window);
    worldPosition = window.mapPixelToCoords(mousePosWindow);

    // get deltaTime
    float dt;
    {
      const auto newTp = std::chrono::steady_clock::now();
      dt = std::chrono::duration<float>(newTp - tp).count();
      tp = newTp;
    }

    // Handle the input for the player
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

    // Set the direction of the player
    player.SetDirection(direction);

    // Tomato Button
    tomatoesBackground.buttonNotPressed(0);
    if (tomatoesBackground.getWithinDimensions(tomatoesBackground, worldPosition)) { // If mouse position is within in the sprite
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && grid.checkGrid() == true) {  // If the player owns a tile that doesnt have a crop
          tomatoesBackground.buttonPressed(0); // Changes button texture
          plantTomatoes = true;
          plantCrop = true;
        }
    }

    // Blueberries Button
    blueberriesBackground.buttonNotPressed(0);
    if (blueberriesBackground.getWithinDimensions(blueberriesBackground, worldPosition)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && grid.checkGrid() == true) {  
          blueberriesBackground.buttonPressed(0);
          plantBlueberries = true;
          plantCrop = true;
        }
    }

    // Carrot Button
    carrotsBackground.buttonNotPressed(0);
    if (carrotsBackground.getWithinDimensions(carrotsBackground, worldPosition)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && grid.checkGrid() == true) {  
          carrotsBackground.buttonPressed(0);
          plantCarrots = true;
          plantCrop = true;
        }
    }

    // Beets Button
    beetsBackground.buttonNotPressed(0);
    if (beetsBackground.getWithinDimensions(beetsBackground, worldPosition)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && grid.checkGrid() == true) { 
          beetsBackground.buttonPressed(0);
          plantBeets = true;
          plantCrop = true;
        }
    }

    // Strawberries Button
    strawberriesBackground.buttonNotPressed(0);
    if (strawberriesBackground.getWithinDimensions(strawberriesBackground, worldPosition)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && grid.checkGrid() == true) { 
          strawberriesBackground.buttonPressed(0);
          plantStrawberries = true;
          plantCrop = true;
        }
    }

    // Set the scroll to the bigger version
    scroll.scrollBig();

    // Shop Button
    shopBackground.buttonNotPressed(1);
    if (shopBackground.getWithinDimensions(shopBackground, worldPosition) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        shopBackground.buttonPressed(1);
        scroll.scrollSmall(); // Sets the scroll to the smaller version temporarily
        openShop = true;
        if (openMore == true) {openMore = false;}
        if (openCrop == true) {openCrop = false;} // Ensures that other bools are false
    }

    // Crops Button
    cropBackground.buttonNotPressed(1);
    if (cropBackground.getWithinDimensions(cropBackground, worldPosition) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        cropBackground.buttonPressed(1);
        scroll.scrollSmall();
        openCrop = true;
        if (openShop == true) {openShop = false;}
        if (openMore == true) {openMore = false;}
    }

    // More Button
    moreBackground.buttonNotPressed(1);
    if (moreBackground.getWithinDimensions(moreBackground, worldPosition) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        moreBackground.buttonPressed(1);
        scroll.scrollSmall();
        openMore = true;
        if (openShop == true) {openShop = false;}
        if (openCrop == true) {openCrop = false;}
    }

    //std::cout << "OpenShop: " << openShop << ", OpenCrop: " << openCrop << ", OpenMore: " << openMore << std::endl;

    // Update tile selector, UI text, coin animation, and player's grid position
    player.Update(dt, charWaitTime, false);
    grid.updateCharGridPosition(player.getCharPosition(), charPosGrid);
    coin.Update(dt, coinWaitTime, false);
    balance.updateText(player,"", 0);
    shop.updateText(player,"Shop", 1);
    crop.updateText(player,"Crop", 1);
    more.updateText(player,"More", 1);

    if (worldPosition.x >= gridOffsetX && worldPosition.y >= gridOffsetY &&
        worldPosition.x < gridSizeF * mapSizeX + gridOffsetX &&
        worldPosition.y < gridSizeF * mapSizeY + gridOffsetY) {  // Checks if the mouse is on a tile
      grid.updateMouseGridPosition(worldPosition, mousePosGrid);  // Update grid position
      grid.updateTileSelector(mousePosGrid, plantCrop); /// Update tile selection
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && plantCrop == false) {  // Checks if the player is purchasing a tile or crop
        grid.purchaseGrid(mousePosGrid, player); // Purchase a tile
      } else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && plantTomatoes == true) {
        if (grid.getIsLocked(mousePosGrid) == false && grid.getHasCrop(mousePosGrid) == false) { // Checks if the player has a tile with no crop on it
          Crop* newTomato = new Tomatoes({mousePosGrid.x * gridSizeF + gridOffsetX, mousePosGrid.y * gridSizeF + gridOffsetY}); // Dynamically create a crop to the position of the tile
          grid.plantCrop(mousePosGrid, newTomato, player); // Plant the crop
          plantTomatoes = false; // Resets booleans to false
          plantCrop = false;
        }
      } else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && plantBlueberries == true) {
        if (grid.getIsLocked(mousePosGrid) == false && grid.getHasCrop(mousePosGrid) == false) {
          Crop* newBlueberries = new Blueberries({mousePosGrid.x * gridSizeF + gridOffsetX, mousePosGrid.y * gridSizeF + gridOffsetY});
          grid.plantCrop(mousePosGrid, newBlueberries, player);
          plantBlueberries = false;
          plantCrop = false;
        }
      } else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && plantCarrots == true) {
        if (grid.getIsLocked(mousePosGrid) == false && grid.getHasCrop(mousePosGrid) == false) {
          Crop* newCarrots = new Carrots({mousePosGrid.x * gridSizeF + gridOffsetX, mousePosGrid.y * gridSizeF + gridOffsetY});
          grid.plantCrop(mousePosGrid, newCarrots, player);
          plantCarrots = false;
          plantCrop = false;
        }
      } else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && plantBeets == true) {
        if (grid.getIsLocked(mousePosGrid) == false && grid.getHasCrop(mousePosGrid) == false) {
          Crop* newBeets = new Beets({mousePosGrid.x * gridSizeF + gridOffsetX, mousePosGrid.y * gridSizeF + gridOffsetY});
          grid.plantCrop(mousePosGrid, newBeets, player);
          plantBeets = false;
          plantCrop = false;
        }
      } else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && plantStrawberries == true) {
        if (grid.getIsLocked(mousePosGrid) == false && grid.getHasCrop(mousePosGrid) == false) {
          Crop* newStrawberries = new Strawberries({mousePosGrid.x * gridSizeF + gridOffsetX, mousePosGrid.y * gridSizeF + gridOffsetY});
          grid.plantCrop(mousePosGrid, newStrawberries, player);
          plantStrawberries = false;
          plantCrop = false;
        }
      }
    }

    // Boundary for the character
    if(player.getCharPosition().x < 0.f) {
      player.setCharPosition(0.f, player.getCharPosition().y);
    }
    if(player.getCharPosition().y < 96.f) {
      player.setCharPosition(player.getCharPosition().x, 96.f);
    }
    if(player.getCharPosition().x > gridSizeF*mapSizeX) {
      player.setCharPosition(gridSizeF*mapSizeX, player.getCharPosition().y);
    }
    if(player.getCharPosition().y > (gridSizeF*mapSizeY)+64.f) {
      player.setCharPosition(player.getCharPosition().x, (gridSizeF*mapSizeY)+64.f);
    }

    // Render
    window.clear();
    window.draw(backdrop);
    balanceBackground.draw(window, 0);
    fence.draw(window, 1);
    grid.draw(window, dt, resetFrame, charPosGrid, player);
    coin.Draw(window);
    player.Draw(window);
    balance.draw(window);
    scroll.draw(window, 3);
    tomatoesBackground.draw(window, 2);
    tomatoesButton.draw(window, 2);
    blueberriesBackground.draw(window, 2);
    blueberriesButton.draw(window, 2);
    carrotsBackground.draw(window, 2);
    carrotsButton.draw(window, 2);
    beetsBackground.draw(window, 2);
    beetsButton.draw(window, 2);
    strawberriesBackground.draw(window, 2);
    strawberriesButton.draw(window, 2);
    shopBackground.draw(window, 2);
    shop.draw(window);
    cropBackground.draw(window, 2);
    crop.draw(window);
    moreBackground.draw(window, 2);
    more.draw(window);
    window.display();
  }

  return 0;
}