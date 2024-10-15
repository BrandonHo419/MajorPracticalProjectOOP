#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <chrono>
#include <iostream>
#include <sstream>

#include "Audio.h"
#include "Beets.h"
#include "Blueberries.h"
#include "Carrots.h"
#include "Crop.h"
#include "GridMap.h"
#include "Player.h"
#include "RandomEvents.h"
#include "Shop.h"
#include "Strawberries.h"
#include "Text.h"
#include "Tomatoes.h"
#include "UI.h"
#include "Weather.h"

int main() {
  // Window setup
  sf::RenderWindow window(sf::VideoMode(1920, 1080), "Crop Planting Simulator");
  window.setFramerateLimit(60);

  RandomEvents events;  // events
  Audio audio;

  // Player
  Player player({200.0f, 200.0f});
  float charWaitTime = 0.1f;  // animation per frame time also growth for plants

  // Weather
  Weather weather;
  weather.requestWeather();

  // Shop
  Shop shop;
  shop.weatherAffected(weather.getTemperature(), weather.getRainfall());

  // Grid initialising
  float gridSizeF = 96.0f;
  unsigned gridSizeU = static_cast<unsigned>(gridSizeF);
  int const mapSizeX = 10;
  int const mapSizeY = 7;
  float const gridOffsetX = 96.0f;
  float const gridOffsetY = 256.0f;

  // Timepoint for delta time management
  auto tp = std::chrono::steady_clock::now();

  // Background texture
  sf::Texture backgroundTexture;
  if (!backgroundTexture.loadFromFile("TileableBackGround.png")) {
    std::cerr << "Error loading background texture" << std::endl;
    return -1;
  }
  sf::Sprite backdrop(backgroundTexture);
  backdrop.setScale(1920.f / backgroundTexture.getSize().x,
                    1080.f / backgroundTexture.getSize().y);

  // Create grid map and text
  GridMap grid(gridSizeF, gridSizeU, mapSizeX, mapSizeY, gridOffsetX,
               gridOffsetY);
  Texts balance("windows_command_prompt.ttf", sf::Vector2f(290.f, 0.f), 120);
  Texts crop("windows_command_prompt.ttf", sf::Vector2f(1250.f, 22.f), 80);
  Texts strawberriesText("windows_command_prompt.ttf",
                         sf::Vector2f(1370.f, 268.f), 40);
  Texts strawberriesSellInfo("windows_command_prompt.ttf",
                             sf::Vector2f(1370.f, 308.f), 30);
  Texts strawberriesGrowthInfo("windows_command_prompt.ttf",
                               sf::Vector2f(1370.f, 338.f), 30);
  Texts blueberriesText("windows_command_prompt.ttf",
                        sf::Vector2f(1370.f, 398.f), 40);
  Texts blueberriesSellInfo("windows_command_prompt.ttf",
                            sf::Vector2f(1370.f, 438.f), 30);
  Texts blueberriesGrowthInfo("windows_command_prompt.ttf",
                              sf::Vector2f(1370.f, 468.f), 30);
  Texts carrotsText("windows_command_prompt.ttf", sf::Vector2f(1370.f, 528.f),
                    40);
  Texts carrotsSellInfo("windows_command_prompt.ttf",
                        sf::Vector2f(1370.f, 568.f), 30);
  Texts carrotsGrowthInfo("windows_command_prompt.ttf",
                          sf::Vector2f(1370.f, 598.f), 30);
  Texts beetsText("windows_command_prompt.ttf", sf::Vector2f(1370.f, 658.f),
                  40);
  Texts beetsSellInfo("windows_command_prompt.ttf", sf::Vector2f(1370.f, 698.f),
                      30);
  Texts beetsGrowthInfo("windows_command_prompt.ttf",
                        sf::Vector2f(1370.f, 728.f), 30);
  Texts tomatoesText("windows_command_prompt.ttf", sf::Vector2f(1370.f, 788.f),
                     40);
  Texts tomatoesSellInfo("windows_command_prompt.ttf",
                         sf::Vector2f(1370.f, 828.f), 30);
  Texts tomatoesGrowthInfo("windows_command_prompt.ttf",
                           sf::Vector2f(1370.f, 858.f), 30);
  Texts deleteCrop("windows_command_prompt.ttf", sf::Vector2f(1050.f, 22.f),
                   80);
  Texts more("windows_command_prompt.ttf", sf::Vector2f(1650.f, 22.f), 80);
  Texts weatherText("windows_command_prompt.ttf", sf::Vector2f(1410.f, 288.f),
                    80);
  Texts location("windows_command_prompt.ttf", sf::Vector2f(1240.f, 388.f), 40);
  Texts temperature("windows_command_prompt.ttf", sf::Vector2f(1240.f, 428.f),
                    40);
  Texts rainfall("windows_command_prompt.ttf", sf::Vector2f(1240.f, 468.f), 40);
  Texts temperatureModifier("windows_command_prompt.ttf",
                            sf::Vector2f(1240.f, 508.f), 40);
  Texts rainfallModifier("windows_command_prompt.ttf",
                         sf::Vector2f(1240.f, 548.f), 40);
  Texts shopText("windows_command_prompt.ttf", sf::Vector2f(1450.f, 22.f), 80);
  Texts fertiliserText("windows_command_prompt.ttf",
                       sf::Vector2f(1240.f, 388.f), 40);
  Texts fertiliserInfo("windows_command_prompt.ttf",
                       sf::Vector2f(1240.f, 438.f), 30);
  Texts fertiliserUnlocked("windows_command_prompt.ttf",
                           sf::Vector2f(1240.f, 468.f), 30);
  Texts greenhouseText("windows_command_prompt.ttf",
                       sf::Vector2f(1240.f, 528.f), 40);
  Texts greenhouseInfo("windows_command_prompt.ttf",
                       sf::Vector2f(1240.f, 578.f), 30);
  Texts greenhouseUnlocked("windows_command_prompt.ttf",
                           sf::Vector2f(1240.f, 608.f), 30);
  Texts gameInstruction("windows_command_prompt.ttf",
                        sf::Vector2f(1230.f, 620.f), 30);

  gameInstruction.updateTextInstructions(
      "To play this game you can buy crops and plant");
  gameInstruction.updateTextInstructions(
      "them in the grid to the left. Move the player");
  gameInstruction.updateTextInstructions(
      "around using WASD, to pick up the money after");
  gameInstruction.updateTextInstructions(
      "the crop has finsihed growing. Visit the shop,");
  gameInstruction.updateTextInstructions(
      "to buy upgrades which increase the sale value");
  gameInstruction.updateTextInstructions("or decrease crop growth time.");
  gameInstruction.updateTextInstructions(
      "View the weather conditions as these impact");
  gameInstruction.updateTextInstructions(
      "crop growth time. Temperatures above 30 and");
  gameInstruction.updateTextInstructions(
      "below 15 will increase growth time and rainfall");
  gameInstruction.updateTextInstructions(
      "above 0 will decrease growth time. The 'Del'");
  gameInstruction.updateTextInstructions(
      "button will delete a crop of your choice. Every");
  gameInstruction.updateTextInstructions(
      "2 minutes, recieve $200 and new weather.");

  shopText.updateText("Shop");
  crop.updateText("Crop");
  more.updateText("More");
  deleteCrop.updateText("Del");
  weatherText.updateText("Weather");
  fertiliserUnlocked.updateText("Unlocked!");
  greenhouseUnlocked.updateText("Unlocked!");

  // Create Buttons
  UI balanceBackground("scrollsandblocks.png", sf::Vector2f(240.f, 20.f), 0,
                       sf::IntRect(32, 0, 64, 32));
  UI fence("fence.png", sf::Vector2f(96.f, 160.f), 1,
           sf::IntRect(32, 0, 32, 32));
  UI strawberriesIcon("crops2.png", sf::Vector2f(1260.f, 278.f), 2,
                      sf::IntRect(32 * 20, 32 * 10, 32, 32));
  UI strawberriesButton("scrollsandblocks.png", sf::Vector2f(1260.f, 278.f), 2,
                        sf::IntRect(0, 0, 32, 32));
  UI blueberriesIcon("crops2.png", sf::Vector2f(1260.f, 408.f), 2,
                     sf::IntRect(32 * 23, 32 * 10, 32, 32));
  UI blueberriesButton("scrollsandblocks.png", sf::Vector2f(1260.f, 408.f), 2,
                       sf::IntRect(0, 0, 32, 32));
  UI carrotsIcon("crops2.png", sf::Vector2f(1260.f, 538.f), 2,
                 sf::IntRect(32 * 6, 0, 32, 32));
  UI carrotsButton("scrollsandblocks.png", sf::Vector2f(1260.f, 538.f), 2,
                   sf::IntRect(0, 0, 32, 32));
  UI beetsIcon("crops2.png", sf::Vector2f(1260.f, 668.f), 2,
               sf::IntRect(32 * 9, 0, 32, 32));
  UI beetsButton("scrollsandblocks.png", sf::Vector2f(1260.f, 668.f), 2,
                 sf::IntRect(0, 0, 32, 32));
  UI tomatoesIcon("crops2.png", sf::Vector2f(1260.f, 798.f), 2,
                  sf::IntRect(32 * 28, 32 * 10, 32, 32));
  UI tomatoesButton("scrollsandblocks.png", sf::Vector2f(1260.f, 798.f), 2,
                    sf::IntRect(0, 0, 32, 32));
  UI deleteButton("scrollsandblocks.png", sf::Vector2f(1010.f, 32.f), 2,
                  sf::IntRect(32, 0, 64, 32));
  UI cropButton("scrollsandblocks.png", sf::Vector2f(1230.f, 32.f), 2,
                sf::IntRect(32, 0, 64, 32));
  UI shopButton("scrollsandblocks.png", sf::Vector2f(1430.f, 32.f), 2,
                sf::IntRect(32, 0, 64, 32));
  UI moreButton("scrollsandblocks.png", sf::Vector2f(1630.f, 32.f), 2,
                sf::IntRect(32, 0, 64, 32));
  UI scroll("scrollsandblocks.png", sf::Vector2f(1200.f, 160.f), 3,
            sf::IntRect(32 * 7, 32 * 7, 96, 96));
  UI fertiliserButton("scrollsandblocks.png", sf::Vector2f(1670.f, 408.f), 2,
                      sf::IntRect(0, 0, 32, 32));
  UI fertiliserIcon("Crop_Spritesheet.png", sf::Vector2f(1695.f, 430.f), 2,
                    sf::IntRect(16 * 6, 16 * 7, 16, 16));
  UI greenhouseButton("scrollsandblocks.png", sf::Vector2f(1670.f, 548.f), 2,
                      sf::IntRect(0, 0, 32, 32));
  UI greenhouseIcon("Ghouse.png", sf::Vector2f(1672.f, 550.f), 4,
                    sf::IntRect(0, 0, 225, 225));

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
  bool deleteACrop = false;
  // Timer
  float timeForWeather = 120.f;  // 2 minutes
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
    if (time >= timeForWeather) {  // Call for different weather every 2 minutes
      time -= timeForWeather;
      weather.requestWeather();
      shop.weatherAffected(weather.getTemperature(), weather.getRainfall());
      player.addMoney(200);  // To prevent the player being locked out of buying
                             // crops if they can't afford any crop
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
          !plantStrawberries && !plantCrop &&
          !deleteACrop) {  // Ensures the player can't buy another crop before
                           // placing it in a tile
        tomatoesButton.buttonNotPressed("Small");
        if (tomatoesButton.getWithinDimensions(tomatoesButton, worldPosition) &&
            player.getMoney() >=
                shop.getCropVar(
                    "Tomatoes",
                    "Price")) {  // If mouse position is within in the sprite
                                 // and player can afford it
          if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
              grid.checkGridFor("No Crop") ==
                  true) {  // If the player owns a tile that doesnt have a crop
            tomatoesButton.buttonPressed("Small");  // Changes button texture
            plantTomatoes = true;
            plantCrop = true;
          }
        }
      }

      // Blueberries Button
      if (!plantTomatoes && !plantBeets && !plantCarrots &&
          !plantStrawberries && !plantCrop && !deleteACrop) {
        blueberriesButton.buttonNotPressed("Small");
        if (blueberriesButton.getWithinDimensions(blueberriesButton,
                                                  worldPosition) &&
            player.getMoney() >= shop.getCropVar("Blueberries", "Price")) {
          if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
              grid.checkGridFor("No Crop") == true) {
            blueberriesButton.buttonPressed("Small");
            plantBlueberries = true;
            plantCrop = true;
          }
        }
      }

      // Carrot Button
      if (!plantTomatoes && !plantBlueberries && !plantBeets &&
          !plantStrawberries && !plantCrop && !deleteACrop) {
        carrotsButton.buttonNotPressed("Small");
        if (carrotsButton.getWithinDimensions(carrotsButton, worldPosition) &&
            player.getMoney() >= shop.getCropVar("Carrots", "Price")) {
          if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
              grid.checkGridFor("No Crop") == true) {
            carrotsButton.buttonPressed("Small");
            plantCarrots = true;
            plantCrop = true;
          }
        }
      }

      // Beets Button
      if (!plantTomatoes && !plantBlueberries && !plantCarrots &&
          !plantStrawberries && !plantCrop && !deleteACrop) {
        beetsButton.buttonNotPressed("Small");
        if (beetsButton.getWithinDimensions(beetsButton, worldPosition) &&
            player.getMoney() >= shop.getCropVar("Beets", "Price")) {
          if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
              grid.checkGridFor("No Crop") == true) {
            beetsButton.buttonPressed("Small");
            plantBeets = true;
            plantCrop = true;
          }
        }
      }

      // Strawberries Button
      if (!plantTomatoes && !plantBlueberries && !plantBeets && !plantCarrots &&
          !plantCrop && !deleteACrop) {
        strawberriesButton.buttonNotPressed("Small");
        if (strawberriesButton.getWithinDimensions(strawberriesButton,
                                                   worldPosition) &&
            player.getMoney() >= shop.getCropVar("Strawberries", "Price")) {
          if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
              grid.checkGridFor("No Crop") == true) {
            strawberriesButton.buttonPressed("Small");
            plantStrawberries = true;
            plantCrop = true;
          }
        }
      }
    }

    // Set the scroll to the bigger version
    scroll.scrollBig();
    lastFrame = true;

    // Delete Button
    deleteButton.buttonNotPressed("Long");
    if (deleteButton.getWithinDimensions(deleteButton, worldPosition) &&
        sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      if (grid.checkGridFor("Delete") == true) {  // Check the player has a crop
        deleteButton.buttonPressed("Long");
        deleteACrop = true;
      }
    }

    // Shop Button
    shopButton.buttonNotPressed("Long");
    if (shopButton.getWithinDimensions(shopButton, worldPosition) &&
        sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      shopButton.buttonPressed("Long");
      scroll
          .scrollSmall();  // Sets the scroll to the smaller version temporarily
      openShop = true;
      lastFrame = false;
      if (openMore == true) {
        openMore = false;
      }
      if (openCrop == true) {
        openCrop = false;
      }  // Ensures that other bools are false
    }

    // Shop Buttons
    if (openShop) {
      // Fertiliser
      fertiliserButton.buttonNotPressed("Small");
      if (fertiliserButton.getWithinDimensions(fertiliserButton,
                                               worldPosition)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
            player.getMoney() >= shop.getItemPrice("Fertiliser") &&
            haveFertiliser == false) {
          shop.purchaseFertiliser(player);  // Purchase the fertiliser
          fertiliserButton.buttonPressed("Small");
          haveFertiliser = true;
        }
      }
      // Greenhouse
      greenhouseButton.buttonNotPressed("Small");
      if (greenhouseButton.getWithinDimensions(greenhouseButton,
                                               worldPosition)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
            player.getMoney() >= shop.getItemPrice("Greenhouse") &&
            haveGreenhouse == false) {
          shop.purchaseGreenhouse(player);
          greenhouseButton.buttonPressed("Small");
          haveGreenhouse = true;
        }
      }
    }

    // Crops Button
    cropButton.buttonNotPressed("Long");
    if (cropButton.getWithinDimensions(cropButton, worldPosition) &&
        sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      cropButton.buttonPressed("Long");
      scroll.scrollSmall();
      openCrop = true;
      lastFrame = false;
      if (openShop == true) {
        openShop = false;
      }
      if (openMore == true) {
        openMore = false;
      }
    }

    // More Button
    moreButton.buttonNotPressed("Long");
    if (moreButton.getWithinDimensions(moreButton, worldPosition) &&
        sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      moreButton.buttonPressed("Long");
      scroll.scrollSmall();
      openMore = true;
      lastFrame = false;
      if (openShop == true) {
        openShop = false;
      }
      if (openCrop == true) {
        openCrop = false;
      }
    }

    // Update tile selector and player's grid position
    player.Update(dt, charWaitTime, false);
    grid.updateCharGridPosition(player.getCharPosition(), charPosGrid);

    // Update the text
    balance.updateText("$" + player.getMoneyStr());
    location.updateText("Location : " + weather.getLocation());
    temperature.updateText("Temperature : " + weather.getTemperatureString());
    rainfall.updateText("Rainfall : " + weather.getRainfallString());
    temperatureModifier.updateText("Temperature Modifer: " +
                                   shop.getWeatherModfiersStr("Temperature"));
    rainfallModifier.updateText("Rainfall Modifier: " +
                                shop.getWeatherModfiersStr("Rainfall"));
    fertiliserText.updateText("Fertiliser: $" +
                              shop.getItemVarStr("Fertiliser", "Price"));
    fertiliserInfo.updateText("Reduces Growth Speed : " +
                              shop.getItemVarStr("Fertiliser", "Modifier"));
    greenhouseText.updateText("Greenhouse: $" +
                              shop.getItemVarStr("Greenhouse", "Price"));
    greenhouseInfo.updateText("Increase Sell Value : " +
                              shop.getItemVarStr("Greenhouse", "Modifier"));
    strawberriesText.updateText("Strawberries: $" +
                                shop.getCropVarStr("Strawberries", "Price"));
    strawberriesSellInfo.updateText(
        "Sell Value: $" + shop.getCropVarStr("Strawberries", "Sell Value"));
    strawberriesGrowthInfo.updateText(
        "Growth Time per Stage (sec): " +
        shop.getCropVarStr("Strawberries", "Growth"));
    blueberriesText.updateText("Blueberries: $" +
                               shop.getCropVarStr("Blueberries", "Price"));
    blueberriesSellInfo.updateText(
        "Sell Value: $" + shop.getCropVarStr("Blueberries", "Sell Value"));
    blueberriesGrowthInfo.updateText(
        "Growth Time per Stage (sec): " +
        shop.getCropVarStr("Blueberries", "Growth"));
    carrotsText.updateText("Carrots: $" +
                           shop.getCropVarStr("Carrots", "Price"));
    carrotsSellInfo.updateText("Sell Value: $" +
                               shop.getCropVarStr("Carrots", "Sell Value"));
    carrotsGrowthInfo.updateText("Growth Time per Stage (sec): " +
                                 shop.getCropVarStr("Carrots", "Growth"));
    beetsText.updateText("Beets: $" + shop.getCropVarStr("Beets", "Price"));
    beetsSellInfo.updateText("Sell Value: $" +
                             shop.getCropVarStr("Beets", "Sell Value"));
    beetsGrowthInfo.updateText("Growth Time per Stage (sec): " +
                               shop.getCropVarStr("Beets", "Growth"));
    tomatoesText.updateText("Tomatoes: $" +
                            shop.getCropVarStr("Tomatoes", "Price"));
    tomatoesSellInfo.updateText("Sell Value: $" +
                                shop.getCropVarStr("Tomatoes", "Sell Value"));
    tomatoesGrowthInfo.updateText("Growth Time per Stage (sec): " +
                                  shop.getCropVarStr("Tomatoes", "Growth"));

    if (worldPosition.x >= gridOffsetX && worldPosition.y >= gridOffsetY &&
        worldPosition.x < gridSizeF * mapSizeX + gridOffsetX &&
        worldPosition.y <
            gridSizeF * mapSizeY +
                gridOffsetY) {  // Checks if the mouse is on a tile
      grid.updateMouseGridPosition(worldPosition,
                                   mousePosGrid);  // Update grid position
      grid.updateTileSelector(mousePosGrid, plantCrop,
                              deleteACrop);  /// Update tile selection
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && plantCrop == false &&
          deleteACrop ==
              false) {  // Checks if the player is purchasing a tile or crop
        grid.purchaseGrid(mousePosGrid, player);  // Purchase a tile
      } else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
                 deleteACrop == true && grid.getHasCrop(mousePosGrid) == true) {
        grid.deleteCrop(mousePosGrid);
        deleteACrop = false;
      } else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
                 plantTomatoes == true) {
        if (grid.getIsLocked(mousePosGrid) == false &&
            grid.getHasCrop(mousePosGrid) ==
                false) {  // Checks if the player has a tile with no crop on it
          Crop* newTomato = new Tomatoes(
              {mousePosGrid.x * gridSizeF + gridOffsetX,
               mousePosGrid.y * gridSizeF + gridOffsetY},
              shop.getCropVar("Tomatoes", "Growth"),
              shop.getCropVar("Tomatoes",
                              "Sell Value"));  // Dynamically create a crop to
                                               // the position of the tile
          grid.plantCrop(mousePosGrid, newTomato, player);  // Plant the crop
          player.setMoney(
              shop.getCropVar("Tomatoes", "Price"));  // Subtract player's money
          shop.afterPurchaseCrop(
              "Tomatoes");  // Applies new price and sell values to Tomatoes
          plantTomatoes = false;  // Resets booleans to false
          plantCrop = false;
          std::cout << "Tomatoes Created!" << std::endl;
        }
      } else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
                 plantBlueberries == true) {
        if (grid.getIsLocked(mousePosGrid) == false &&
            grid.getHasCrop(mousePosGrid) == false) {
          Crop* newBlueberries =
              new Blueberries({mousePosGrid.x * gridSizeF + gridOffsetX,
                               mousePosGrid.y * gridSizeF + gridOffsetY},
                              shop.getCropVar("Blueberries", "Growth"),
                              shop.getCropVar("Blueberries", "Sell Value"));
          grid.plantCrop(mousePosGrid, newBlueberries, player);
          player.setMoney(shop.getCropVar("Blueberries", "Price"));
          shop.afterPurchaseCrop("Blueberries");
          plantBlueberries = false;
          plantCrop = false;
          std::cout << "Blueberries Created!" << std::endl;
        }
      } else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
                 plantCarrots == true) {
        if (grid.getIsLocked(mousePosGrid) == false &&
            grid.getHasCrop(mousePosGrid) == false) {
          Crop* newCarrots =
              new Carrots({mousePosGrid.x * gridSizeF + gridOffsetX,
                           mousePosGrid.y * gridSizeF + gridOffsetY},
                          shop.getCropVar("Carrots", "Growth"),
                          shop.getCropVar("Carrots", "Sell Value"));
          grid.plantCrop(mousePosGrid, newCarrots, player);
          player.setMoney(shop.getCropVar("Carrots", "Price"));
          shop.afterPurchaseCrop("Carrots");
          plantCarrots = false;
          plantCrop = false;
          std::cout << "Carrots Created!" << std::endl;
        }
      } else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
                 plantBeets == true) {
        if (grid.getIsLocked(mousePosGrid) == false &&
            grid.getHasCrop(mousePosGrid) == false) {
          Crop* newBeets = new Beets({mousePosGrid.x * gridSizeF + gridOffsetX,
                                      mousePosGrid.y * gridSizeF + gridOffsetY},
                                     shop.getCropVar("Beets", "Growth"),
                                     shop.getCropVar("Beets", "Sell Value"));
          grid.plantCrop(mousePosGrid, newBeets, player);
          player.setMoney(shop.getCropVar("Beets", "Price"));
          shop.afterPurchaseCrop("Beets");
          plantBeets = false;
          plantCrop = false;
          std::cout << "Beets Created!" << std::endl;
        }
      } else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
                 plantStrawberries == true) {
        if (grid.getIsLocked(mousePosGrid) == false &&
            grid.getHasCrop(mousePosGrid) == false) {
          Crop* newStrawberries =
              new Strawberries({mousePosGrid.x * gridSizeF + gridOffsetX,
                                mousePosGrid.y * gridSizeF + gridOffsetY},
                               shop.getCropVar("Strawberries", "Growth"),
                               shop.getCropVar("Strawberries", "Sell Value"));
          grid.plantCrop(mousePosGrid, newStrawberries, player);
          player.setMoney(shop.getCropVar("Strawberries", "Price"));
          shop.afterPurchaseCrop("Strawberries");
          plantStrawberries = false;
          plantCrop = false;
          std::cout << "Strawberries Created!" << std::endl;
        }
      }
    }

    // Boundary for the player
    if (player.getCharPosition().x < 0.f) {
      player.setCharPosition(0.f, player.getCharPosition().y);
    }
    if (player.getCharPosition().y < gridSizeF) {
      player.setCharPosition(player.getCharPosition().x, 96.f);
    }
    if (player.getCharPosition().x > gridSizeF * mapSizeX) {
      player.setCharPosition(gridSizeF * mapSizeX, player.getCharPosition().y);
    }
    if (player.getCharPosition().y > (gridSizeF * mapSizeY) + 64.f) {
      player.setCharPosition(player.getCharPosition().x,
                             (gridSizeF * mapSizeY) + 64.f);
    }

    // Update Variables such as the growth and sell value from the shop into the
    // crops on the grid
    grid.updateVariables(shop.getCropVar("Strawberries", "Growth"),
                         shop.getCropVar("Strawberries", "Sell Value"),
                         "Strawberries");
    grid.updateVariables(shop.getCropVar("Blueberries", "Growth"),
                         shop.getCropVar("Blueberries", "Sell Value"),
                         "Blueberries");
    grid.updateVariables(shop.getCropVar("Carrots", "Growth"),
                         shop.getCropVar("Carrots", "Sell Value"), "Carrots");
    grid.updateVariables(shop.getCropVar("Beets", "Growth"),
                         shop.getCropVar("Beets", "Sell Value"), "Beets");
    grid.updateVariables(shop.getCropVar("Tomatoes", "Growth"),
                         shop.getCropVar("Tomatoes", "Sell Value"), "Tomatoes");

    // Render
    window.clear();
    window.draw(backdrop);
    balanceBackground.draw(window, 0);
    fence.draw(window, 1);
    grid.draw(window, dt, resetFrame, charPosGrid, player);
    player.Draw(window);
    balance.draw(window);
    scroll.draw(window, 3);
    moreButton.draw(window, 2);
    deleteButton.draw(window, 2);
    deleteCrop.draw(window);
    more.draw(window);
    shopButton.draw(window, 2);
    shopText.draw(window);
    cropButton.draw(window, 2);
    crop.draw(window);

    if (openMore && lastFrame) {  // If More is Clicked and the Scroll is Big
      weatherText.draw(window);
      location.draw(window);
      temperature.draw(window);
      rainfall.draw(window);
      temperatureModifier.draw(window);
      rainfallModifier.draw(window);
      gameInstruction.draw(window);
    } else if (openCrop &&
               lastFrame) {  // If Crop is Clicked and the Scroll is Big
      strawberriesButton.draw(window, 2);
      strawberriesIcon.draw(window, 2);
      strawberriesText.draw(window);
      strawberriesSellInfo.draw(window);
      strawberriesGrowthInfo.draw(window);
      blueberriesButton.draw(window, 2);
      blueberriesIcon.draw(window, 2);
      blueberriesText.draw(window);
      blueberriesSellInfo.draw(window);
      blueberriesGrowthInfo.draw(window);
      carrotsButton.draw(window, 2);
      carrotsIcon.draw(window, 2);
      carrotsText.draw(window);
      carrotsSellInfo.draw(window);
      carrotsGrowthInfo.draw(window);
      beetsButton.draw(window, 2);
      beetsIcon.draw(window, 2);
      beetsText.draw(window);
      beetsSellInfo.draw(window);
      beetsGrowthInfo.draw(window);
      tomatoesButton.draw(window, 2);
      tomatoesIcon.draw(window, 2);
      tomatoesText.draw(window);
      tomatoesSellInfo.draw(window);
      tomatoesGrowthInfo.draw(window);
    } else if (openShop &&
               lastFrame) {  // If Shop is Clicked and the Scroll is Big
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
    audio.playSounds();
    events.checkRand();
  }

  return 0;
}