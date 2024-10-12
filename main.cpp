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
#include "Weather.h"
#include "Shop.h"

int main() {
  // Window setup
  sf::RenderWindow window(sf::VideoMode(1920, 1080), "Grid Map and UI");
  window.setFramerateLimit(60);

  // Player
  Player player({200.0f, 200.0f});
  float charWaitTime = 0.1f;  // animation per frame time also growth for plants

  // Weather
  Weather weather;

  // Shop
  Shop shop;

  // Grid initialising
  float gridSizeF = 96.0f;
  unsigned gridSizeU = static_cast<unsigned>(gridSizeF);
  int const mapSizeX = 10;
  int const mapSizeY = 7;
  float const gridOffsetX = 96.0f;
  float const gridOffsetY = 256.0f;

  // Coin
  //Coin coin({270.0f, 40.0f});
  //float coinWaitTime = 0.1f;

  // Timepoint for delta time management 
  auto tp = std::chrono::steady_clock::now();

  float salePrice;

  // Background texture
  sf::Texture backgroundTexture;
  if (!backgroundTexture.loadFromFile("TileableBackGround.png")) {
    std::cerr << "Error loading background texture" << std::endl;
    return -1;
  }
  sf::Sprite backdrop(backgroundTexture);
  backdrop.setScale(1920.f / backgroundTexture.getSize().x, 1080.f / backgroundTexture.getSize().y);
  // CHANGE BACKGROUND TO BUTTON AND BUTTON TO ICON
  // Create grid map, text, buttons and scoll
  GridMap grid(gridSizeF, gridSizeU, mapSizeX, mapSizeY, gridOffsetX, gridOffsetY);
  Text balance("windows_command_prompt.ttf", sf::Vector2f(290.f, 0.f), 120);
  Text crop("windows_command_prompt.ttf", sf::Vector2f(1250.f, 22.f), 80);
  Text strawberriesText("windows_command_prompt.ttf", sf::Vector2f(1370.f, 268.f), 40);
  Text strawberriesSellInfo("windows_command_prompt.ttf", sf::Vector2f(1370.f, 308.f), 30);
  Text strawberriesGrowthInfo("windows_command_prompt.ttf", sf::Vector2f(1370.f, 338.f), 30);
  Text blueberriesText("windows_command_prompt.ttf", sf::Vector2f(1370.f, 398.f), 40);
  Text blueberriesSellInfo("windows_command_prompt.ttf", sf::Vector2f(1370.f, 438.f), 30);
  Text blueberriesGrowthInfo("windows_command_prompt.ttf", sf::Vector2f(1370.f, 468.f), 30);
  Text carrotsText("windows_command_prompt.ttf", sf::Vector2f(1370.f, 528.f), 40);
  Text carrotsSellInfo("windows_command_prompt.ttf", sf::Vector2f(1370.f, 568.f), 30);
  Text carrotsGrowthInfo("windows_command_prompt.ttf", sf::Vector2f(1370.f, 598.f), 30);
  Text beetsText("windows_command_prompt.ttf", sf::Vector2f(1370.f, 658.f), 40);
  Text beetsSellInfo("windows_command_prompt.ttf", sf::Vector2f(1370.f, 698.f), 30);
  Text beetsGrowthInfo("windows_command_prompt.ttf", sf::Vector2f(1370.f, 728.f), 30);
  Text tomatoesText("windows_command_prompt.ttf", sf::Vector2f(1370.f, 788.f), 40);
  Text tomatoesSellInfo("windows_command_prompt.ttf", sf::Vector2f(1370.f, 828.f), 30);
  Text tomatoesGrowthInfo("windows_command_prompt.ttf", sf::Vector2f(1370.f, 858.f), 30);
  Text more("windows_command_prompt.ttf", sf::Vector2f(1650.f, 22.f), 80);
  Text weatherText("windows_command_prompt.ttf", sf::Vector2f(1410.f, 288.f), 80);
  Text location("windows_command_prompt.ttf", sf::Vector2f(1240.f, 388.f), 40);
  Text temperature("windows_command_prompt.ttf", sf::Vector2f(1240.f, 428.f), 40);
  Text rainfall("windows_command_prompt.ttf", sf::Vector2f(1240.f, 468.f), 40);
  Text shopText("windows_command_prompt.ttf", sf::Vector2f(1450.f, 22.f), 80);
  Text fertiliserText("windows_command_prompt.ttf", sf::Vector2f(1240.f, 388.f), 40);
  Text fertiliserInfo("windows_command_prompt.ttf", sf::Vector2f(1240.f, 438.f), 30);
  Text fertiliserUnlocked("windows_command_prompt.ttf", sf::Vector2f(1240.f, 468.f), 30);
  Text greenhouseText("windows_command_prompt.ttf", sf::Vector2f(1240.f, 528.f), 40);
  Text greenhouseInfo("windows_command_prompt.ttf", sf::Vector2f(1240.f, 578.f), 30);
  Text greenhouseUnlocked("windows_command_prompt.ttf", sf::Vector2f(1240.f, 608.f), 30);

  UI balanceBackground("scrollsandblocks.png", sf::Vector2f(240.f, 20.f), 0, sf::IntRect(32, 0, 64, 32));
  UI fence("fence.png", sf::Vector2f(96.f, 160.f), 1, sf::IntRect(32, 0, 32, 32));
  UI strawberriesButton("crops2.png", sf::Vector2f(1260.f, 278.f), 2, sf::IntRect(32*20, 32*10, 32, 32));
  UI strawberriesBackground("scrollsandblocks.png",sf::Vector2f(1260.f, 278.f), 2, sf::IntRect(0, 0, 32, 32));
  UI blueberriesButton("crops2.png", sf::Vector2f(1260.f, 408.f), 2, sf::IntRect(32*23, 32*10, 32, 32));
  UI blueberriesBackground("scrollsandblocks.png",sf::Vector2f(1260.f, 408.f), 2, sf::IntRect(0, 0, 32, 32));
  UI carrotsButton("crops2.png", sf::Vector2f(1260.f, 538.f), 2, sf::IntRect(32*6, 0, 32, 32));
  UI carrotsBackground("scrollsandblocks.png",sf::Vector2f(1260.f, 538.f), 2, sf::IntRect(0, 0, 32, 32));
  UI beetsButton("crops2.png", sf::Vector2f(1260.f, 668.f), 2, sf::IntRect(32*9, 0, 32, 32));
  UI beetsBackground("scrollsandblocks.png",sf::Vector2f(1260.f, 668.f), 2, sf::IntRect(0, 0, 32, 32));
  UI tomatoesButton("crops2.png", sf::Vector2f(1260.f, 798.f), 2, sf::IntRect(32*28, 32*10, 32, 32));
  UI tomatoesBackground("scrollsandblocks.png",sf::Vector2f(1260.f, 798.f), 2, sf::IntRect(0, 0, 32, 32));
  UI cropBackground("scrollsandblocks.png",sf::Vector2f(1230.f, 32.f), 2, sf::IntRect(32, 0, 64, 32));
  UI shopBackground("scrollsandblocks.png",sf::Vector2f(1430.f, 32.f), 2, sf::IntRect(32, 0, 64, 32));
  UI moreBackground("scrollsandblocks.png",sf::Vector2f(1630.f, 32.f), 2, sf::IntRect(32, 0, 64, 32));
  UI scroll("scrollsandblocks.png", sf::Vector2f(1200.f, 160.f), 3, sf::IntRect(32*7, 32*7, 96, 96));
  UI fertiliserButton("scrollsandblocks.png", sf::Vector2f(1670.f, 408.f), 2, sf::IntRect(0, 0, 32, 32));
  UI fertiliserIcon("Crop_Spritesheet.png", sf::Vector2f(1695.f, 430.f), 2, sf::IntRect(16*6, 16*7, 16, 16));
  UI greenhouseButton("scrollsandblocks.png", sf::Vector2f(1670.f, 548.f), 2, sf::IntRect(0, 0, 32, 32));
  UI greenhouseIcon("Ghouse.png", sf::Vector2f(1672.f, 550.f), 4, sf::IntRect(0, 0, 225, 225));
  
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
  bool openShop = true;
  bool openCrop = false;
  bool openMore = false;
  bool lastFrame = false;
  bool haveFertiliser = false;
  bool haveGreenhouse = false;
  // Timer
  float timeForWeather = 60.f*5;
  float time = 0;
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

    time += dt;
    if (time >= timeForWeather) {
      time -= timeForWeather;
      //std::cout << "5 minutes" << std::endl; // Change to 30 seconds once final is complete
      weather.requestWeather();
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

    if (openCrop) {
      // Tomato Button
      if (!plantBlueberries && !plantBeets && !plantCarrots &&
          !plantStrawberries && !plantCrop) {  // Ensures the player can't buy another crop before placing it in a tile
        tomatoesBackground.buttonNotPressed(0);
        if (tomatoesBackground.getWithinDimensions(tomatoesBackground, worldPosition) && player.getMoney() >= shop.getCropPrice("Tomatoes")) {  // If mouse position is within in the sprite
          if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && grid.checkGrid() == true) {  // If the player owns a tile that doesnt have a crop
            tomatoesBackground.buttonPressed(0);  // Changes button texture
            plantTomatoes = true;
            plantCrop = true;
          }
        }
      }

      // Blueberries Button
      if (!plantTomatoes && !plantBeets && !plantCarrots &&
          !plantStrawberries && !plantCrop) {
        blueberriesBackground.buttonNotPressed(0);
        if (blueberriesBackground.getWithinDimensions(blueberriesBackground, worldPosition) && player.getMoney() >= shop.getCropPrice("Blueberries")) {
          if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && grid.checkGrid() == true) {
            blueberriesBackground.buttonPressed(0);
            plantBlueberries = true;
            plantCrop = true;
          }
        }
      }

      // Carrot Button
      if (!plantTomatoes && !plantBlueberries && !plantBeets &&
          !plantStrawberries && !plantCrop) {
        carrotsBackground.buttonNotPressed(0);
        if (carrotsBackground.getWithinDimensions(carrotsBackground, worldPosition) && player.getMoney() >= shop.getCropPrice("Carrots")) {
          if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && grid.checkGrid() == true) {
            carrotsBackground.buttonPressed(0);
            plantCarrots = true;
            plantCrop = true;
          }
        }
      }

      // Beets Button
      if (!plantTomatoes && !plantBlueberries && !plantCarrots &&
          !plantStrawberries && !plantCrop) {
        beetsBackground.buttonNotPressed(0);
        if (beetsBackground.getWithinDimensions(beetsBackground, worldPosition) && player.getMoney() >= shop.getCropPrice("Beets")) {
          if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && grid.checkGrid() == true) {
            beetsBackground.buttonPressed(0);
            plantBeets = true;
            plantCrop = true;
          }
        }
      }

      // Strawberries Button
      if (!plantTomatoes && !plantBlueberries && !plantBeets && !plantCarrots &&
          !plantCrop) {
        strawberriesBackground.buttonNotPressed(0);
        if (strawberriesBackground.getWithinDimensions(strawberriesBackground, worldPosition) && player.getMoney() >= shop.getCropPrice("Strawberries")) {
          if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && grid.checkGrid() == true) {
            strawberriesBackground.buttonPressed(0);
            plantStrawberries = true;
            plantCrop = true;
          }
        }
      }
    }

    // Set the scroll to the bigger version
    scroll.scrollBig();
    lastFrame = true;

    // Shop Button
    shopBackground.buttonNotPressed(1);
    if (shopBackground.getWithinDimensions(shopBackground, worldPosition) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        shopBackground.buttonPressed(1);
        scroll.scrollSmall(); // Sets the scroll to the smaller version temporarily
        openShop = true;
        lastFrame = false;
        if (openMore == true) {openMore = false;}
        if (openCrop == true) {openCrop = false;} // Ensures that other bools are false
    }

    // Shop Buttons
    if (openShop) {
      // Fertiliser
      fertiliserButton.buttonNotPressed(0);
      if (fertiliserButton.getWithinDimensions(fertiliserButton, worldPosition)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && player.getMoney() >= shop.getFertiliserPrice() && haveFertiliser == false) { 
          shop.purchaseFertiliser(player);
          fertiliserButton.buttonPressed(0);
          haveFertiliser = true;
        }
      }
      // Seeds
      greenhouseButton.buttonNotPressed(0);
      if (greenhouseButton.getWithinDimensions(greenhouseButton, worldPosition)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && player.getMoney() >= shop.getGreenhousePrice() && haveGreenhouse == false) { 
          shop.purchaseGreenhouse(player);
          greenhouseButton.buttonPressed(0);
          haveGreenhouse = true;
        }
      }
    }


    // Crops Button
    cropBackground.buttonNotPressed(1);
    if (cropBackground.getWithinDimensions(cropBackground, worldPosition) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        cropBackground.buttonPressed(1);
        scroll.scrollSmall();
        openCrop = true;
        lastFrame = false;
        if (openShop == true) {openShop = false;}
        if (openMore == true) {openMore = false;}
    }

    // More Button
    moreBackground.buttonNotPressed(1);
    if (moreBackground.getWithinDimensions(moreBackground, worldPosition) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        moreBackground.buttonPressed(1);
        scroll.scrollSmall();
        openMore = true;
        lastFrame = false;
        if (openShop == true) {openShop = false;}
        if (openCrop == true) {openCrop = false;}
    }

    //std::cout << "OpenShop: " << openShop << ", OpenCrop: " << openCrop << ", OpenMore: " << openMore << std::endl; 

    // Update tile selector, UI text, coin animation, and player's grid position
    player.Update(dt, charWaitTime, false);
    grid.updateCharGridPosition(player.getCharPosition(), charPosGrid);
    //coin.Update(dt, coinWaitTime, false);
    balance.updateText("$" + player.getMoneyStr());
    shopText.updateText("Shop");
    crop.updateText("Crop");
    more.updateText("More");
    weatherText.updateText("Weather");
    location.updateText("Location : " + weather.getLocation());
    temperature.updateText("Temperature : " + weather.getTemperatureString());
    rainfall.updateText("Rainfall : " + weather.getRainfallString());
    fertiliserText.updateText("Fertiliser: $" + shop.getFertiliserPriceStr());
    fertiliserInfo.updateText("Reduces Growth Speed : " + shop.getFertiliserModifierStr());
    fertiliserUnlocked.updateText("Unlocked!");
    greenhouseText.updateText("Greenhouse: $" + shop.getGreenhousePriceStr());
    greenhouseInfo.updateText("Increase Sell Value : " + shop.getGreenhouseModifierStr());
    greenhouseUnlocked.updateText("Unlocked!");
    strawberriesText.updateText("Strawberries: $" + shop.getCropPriceStr("Strawberries"));
    strawberriesSellInfo.updateText("Sell Value: $" + shop.getCropSellValueStr("Strawberries"));
    strawberriesGrowthInfo.updateText("Growth Time per Stage (sec): " + shop.getCropGrowthTimeStr("Strawberries"));
    blueberriesText.updateText("Blueberries: $" + shop.getCropPriceStr("Blueberries"));
    blueberriesSellInfo.updateText("Sell Value: $" + shop.getCropSellValueStr("Blueberries"));
    blueberriesGrowthInfo.updateText("Growth Time per Stage (sec): " + shop.getCropGrowthTimeStr("Blueberries"));
    carrotsText.updateText("Carrots: $" + shop.getCropPriceStr("Carrots"));
    carrotsSellInfo.updateText("Sell Value: $" + shop.getCropSellValueStr("Carrots"));
    carrotsGrowthInfo.updateText("Growth Time per Stage (sec): " + shop.getCropGrowthTimeStr("Carrots"));
    beetsText.updateText("Beets: $" + shop.getCropPriceStr("Beets"));
    beetsSellInfo.updateText("Sell Value: $" + shop.getCropSellValueStr("Beets"));
    beetsGrowthInfo.updateText("Growth Time per Stage (sec): " + shop.getCropGrowthTimeStr("Beets"));
    tomatoesText.updateText("Tomatoes: $" + shop.getCropPriceStr("Tomatoes"));
    tomatoesSellInfo.updateText("Sell Value: $" + shop.getCropSellValueStr("Tomatoes"));
    tomatoesGrowthInfo.updateText("Growth Time per Stage (sec): " + shop.getCropGrowthTimeStr("Tomatoes"));

    if (worldPosition.x >= gridOffsetX && worldPosition.y >= gridOffsetY &&
        worldPosition.x < gridSizeF * mapSizeX + gridOffsetX &&
        worldPosition.y < gridSizeF * mapSizeY + gridOffsetY) {  // Checks if the mouse is on a tile
      grid.updateMouseGridPosition(worldPosition, mousePosGrid);  // Update grid position
      grid.updateTileSelector(mousePosGrid, plantCrop); /// Update tile selection
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && plantCrop == false) {  // Checks if the player is purchasing a tile or crop
        grid.purchaseGrid(mousePosGrid, player); // Purchase a tile
      } else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && plantTomatoes == true) {
        if (grid.getIsLocked(mousePosGrid) == false && grid.getHasCrop(mousePosGrid) == false) { // Checks if the player has a tile with no crop on it
          Crop* newTomato = new Tomatoes({mousePosGrid.x * gridSizeF + gridOffsetX, mousePosGrid.y * gridSizeF + gridOffsetY}, shop.getCropGrowthTime("Tomatoes"), shop.getCropSellValue("Tomatoes")); // Dynamically create a crop to the position of the tile
          grid.plantCrop(mousePosGrid, newTomato, player); // Plant the crop
          player.setMoney(shop.getCropPrice("Tomatoes")); // Subtract player's money
          shop.afterPurchaseCrop("Tomatoes");
          plantTomatoes = false; // Resets booleans to false
          plantCrop = false;
          std::cout << "Tomatoes Created!" << std::endl;
        }
      } else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && plantBlueberries == true) {
        if (grid.getIsLocked(mousePosGrid) == false && grid.getHasCrop(mousePosGrid) == false) {
          Crop* newBlueberries = new Blueberries({mousePosGrid.x * gridSizeF + gridOffsetX, mousePosGrid.y * gridSizeF + gridOffsetY}, shop.getCropGrowthTime("Blueberries"), shop.getCropSellValue("Blueberries"));
          grid.plantCrop(mousePosGrid, newBlueberries, player);
          player.setMoney(shop.getCropPrice("Blueberries"));
          shop.afterPurchaseCrop("Blueberries");
          plantBlueberries = false;
          plantCrop = false;
          std::cout << "Blueberries Created!" << std::endl;
        }
      } else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && plantCarrots == true) {
        if (grid.getIsLocked(mousePosGrid) == false && grid.getHasCrop(mousePosGrid) == false) {
          Crop* newCarrots = new Carrots({mousePosGrid.x * gridSizeF + gridOffsetX, mousePosGrid.y * gridSizeF + gridOffsetY}, shop.getCropGrowthTime("Carrots"), shop.getCropSellValue("Carrots"));
          grid.plantCrop(mousePosGrid, newCarrots, player);
          player.setMoney(shop.getCropPrice("Carrots"));
          shop.afterPurchaseCrop("Carrots");
          plantCarrots = false;
          plantCrop = false;
          std::cout << "Carrots Created!" << std::endl;
        }
      } else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && plantBeets == true) {
        if (grid.getIsLocked(mousePosGrid) == false && grid.getHasCrop(mousePosGrid) == false) {
          Crop* newBeets = new Beets({mousePosGrid.x * gridSizeF + gridOffsetX, mousePosGrid.y * gridSizeF + gridOffsetY}, shop.getCropGrowthTime("Beets"), shop.getCropSellValue("Beets"));
          grid.plantCrop(mousePosGrid, newBeets, player);
          player.setMoney(shop.getCropPrice("Beets"));
          shop.afterPurchaseCrop("Beets");
          plantBeets = false;
          plantCrop = false;
          std::cout << "Beets Created!" << std::endl;
        }
      } else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && plantStrawberries == true) {
        if (grid.getIsLocked(mousePosGrid) == false && grid.getHasCrop(mousePosGrid) == false) {
          Crop* newStrawberries = new Strawberries({mousePosGrid.x * gridSizeF + gridOffsetX, mousePosGrid.y * gridSizeF + gridOffsetY}, shop.getCropGrowthTime("Strawberries"), shop.getCropSellValue("Strawberries"));
          grid.plantCrop(mousePosGrid, newStrawberries, player);
          player.setMoney(shop.getCropPrice("Strawberries"));
          shop.afterPurchaseCrop("Strawberries");
          plantStrawberries = false;
          plantCrop = false;
          std::cout << "Strawberries Created!" << std::endl;
        }
      }
    }

    // Boundary for the player
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

    // Update Variables
    grid.updateVariables(shop.getCropGrowthTime("Strawberries"), shop.getCropSellValue("Strawberries"), "Strawberries");
    grid.updateVariables(shop.getCropGrowthTime("Blueberries"), shop.getCropSellValue("Blueberries"), "Blueberries");
    grid.updateVariables(shop.getCropGrowthTime("Carrots"), shop.getCropSellValue("Carrots"), "Carrots");
    grid.updateVariables(shop.getCropGrowthTime("Beets"), shop.getCropSellValue("Beets"), "Beets");
    grid.updateVariables(shop.getCropGrowthTime("Tomatoes"), shop.getCropSellValue("Tomatoes"), "Tomatoes");

    // Render
    window.clear();
    window.draw(backdrop);
    balanceBackground.draw(window, 0);
    fence.draw(window, 1);
    grid.draw(window, dt, resetFrame, charPosGrid, player);
    //coin.Draw(window);
    player.Draw(window);
    balance.draw(window);
    scroll.draw(window, 3);
    moreBackground.draw(window, 2);
    more.draw(window);
    shopBackground.draw(window, 2);
    shopText.draw(window);
    cropBackground.draw(window, 2);
    crop.draw(window);

    if (openMore && lastFrame) {
      weatherText.draw(window);
      location.draw(window);
      temperature.draw(window);
      rainfall.draw(window);
    } else if (openCrop && lastFrame){
      strawberriesBackground.draw(window, 2);
      strawberriesButton.draw(window, 2);
      strawberriesText.draw(window);
      strawberriesSellInfo.draw(window);
      strawberriesGrowthInfo.draw(window);
      blueberriesBackground.draw(window, 2);
      blueberriesButton.draw(window, 2);
      blueberriesText.draw(window);
      blueberriesSellInfo.draw(window);
      blueberriesGrowthInfo.draw(window);
      carrotsBackground.draw(window, 2);
      carrotsButton.draw(window, 2);
      carrotsText.draw(window);
      carrotsSellInfo.draw(window);
      carrotsGrowthInfo.draw(window);
      beetsBackground.draw(window, 2);
      beetsButton.draw(window, 2);
      beetsText.draw(window);
      beetsSellInfo.draw(window);
      beetsGrowthInfo.draw(window);
      tomatoesBackground.draw(window, 2);
      tomatoesButton.draw(window, 2);
      tomatoesText.draw(window);
      tomatoesSellInfo.draw(window);
      tomatoesGrowthInfo.draw(window);
    } else if (openShop && lastFrame){
      fertiliserText.draw(window);
      fertiliserInfo.draw(window);
      fertiliserButton.draw(window, 2);
      fertiliserIcon.draw(window, 2);
      if (haveFertiliser) {
        fertiliserUnlocked.draw(window);
      }
      greenhouseText.draw(window);
      greenhouseButton.draw(window, 2);
      greenhouseIcon.draw(window, 2);
      greenhouseInfo.draw(window);
      if (haveGreenhouse) {
        greenhouseUnlocked.draw(window);
      }
    }
    window.display();
  }

  return 0;
}