#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>

#include "Animation2.h"
#include "Audio.h"
#include "Beets.h"
#include "Blueberries.h"
#include "Carrots.h"
#include "Coin.h"
#include "Crop.h"
#include "DialogBox.h"
#include "GridMap.h"
#include "Player.h"
#include "RandomEvents.h"
#include "Requirements.h"
#include "ScrollAnimation.h"
#include "Shop.h"
#include "Strawberries.h"
#include "Text.h"
#include "Textures.h"
#include "Tomatoes.h"
#include "UI.h"
#include "drawShop.h"
#include "loadRect.h"
#include "mouseHandle.h"
#include "oldPlantGrowth.h"

using namespace std;

int main() {
  RenderWindow win(VideoMode(1920, 1080),
                   "Super Awesome Plant Game :3");  // need to redo res
  win.setFramerateLimit(60);
  Player p(Vector2f(200.f, 200.f));
  Font font;
  font.loadFromFile("Albertson.ttf");
  float funds = p.getMoney();
  cout << funds << endl;
  string fundsInString = to_string(funds);

  // load anim stf
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

  // Create grid map, text, buttons and scoll
  GridMap grid(gridSizeF, gridSizeU, mapSizeX, mapSizeY, gridOffsetX,
               gridOffsetY);
  Text2 balance("windows_command_prompt.ttf", sf::Vector2f(360.f, 0.f));
  Text2 crop("windows_command_prompt.ttf", sf::Vector2f(1250.f, 22.f));
  Text2 shop("windows_command_prompt.ttf", sf::Vector2f(1450.f, 22.f));
  Text2 more("windows_command_prompt.ttf", sf::Vector2f(1650.f, 22.f));
  UI balanceBackground("scrollsandblocks.png", sf::Vector2f(240.f, 20.f), 0,
                       sf::IntRect(32, 0, 64, 32));
  UI fence("fence.png", sf::Vector2f(96.f, 160.f), 1,
           sf::IntRect(32, 0, 32, 32));
  UI tomatoesButton("crops2.png", sf::Vector2f(1300.f, 288.f), 2,
                    sf::IntRect(32 * 28, 32 * 10, 32, 32));
  UI tomatoesBackground("scrollsandblocks.png", sf::Vector2f(1300.f, 288.f), 2,
                        sf::IntRect(0, 0, 32, 32));
  UI blueberriesButton("crops2.png", sf::Vector2f(1300.f, 388.f), 2,
                       sf::IntRect(32 * 23, 32 * 10, 32, 32));
  UI blueberriesBackground("scrollsandblocks.png", sf::Vector2f(1300.f, 388.f),
                           2, sf::IntRect(0, 0, 32, 32));
  UI carrotsButton("crops2.png", sf::Vector2f(1300.f, 488.f), 2,
                   sf::IntRect(32 * 6, 0, 32, 32));
  UI carrotsBackground("scrollsandblocks.png", sf::Vector2f(1300.f, 488.f), 2,
                       sf::IntRect(0, 0, 32, 32));
  UI beetsButton("crops2.png", sf::Vector2f(1300.f, 588.f), 2,
                 sf::IntRect(32 * 9, 0, 32, 32));
  UI beetsBackground("scrollsandblocks.png", sf::Vector2f(1300.f, 588.f), 2,
                     sf::IntRect(0, 0, 32, 32));
  UI strawberriesButton("crops2.png", sf::Vector2f(1300.f, 688.f), 2,
                        sf::IntRect(32 * 20, 32 * 10, 32, 32));
  UI strawberriesBackground("scrollsandblocks.png", sf::Vector2f(1300.f, 688.f),
                            2, sf::IntRect(0, 0, 32, 32));
  UI cropBackground("scrollsandblocks.png", sf::Vector2f(1230.f, 32.f), 2,
                    sf::IntRect(32, 0, 64, 32));
  UI shopBackground("scrollsandblocks.png", sf::Vector2f(1430.f, 32.f), 2,
                    sf::IntRect(32, 0, 64, 32));
  UI moreBackground("scrollsandblocks.png", sf::Vector2f(1630.f, 32.f), 2,
                    sf::IntRect(32, 0, 64, 32));
  UI scroll("scrollsandblocks.png", sf::Vector2f(1200.f, 160.f), 3,
            sf::IntRect(32 * 7, 32 * 7, 96, 96));

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
  // end

  sf::Text money;
  money.setFont(font);
  money.setString(fundsInString);
  money.setFillColor(Color::White);
  money.setPosition(920, 60);
  // utilise the classes

  Shop s;
  Animation anims;
  RandomEvents events;
  mouseHandle mh;
  Scroll sc(Vector2f(275.f, 152.f));
  sc.Update(1, 1);
  sc.Update(1, 1);
  loadRect lr;

  // open clock for progression
  Clock beetClock;
  Clock blueberryClock;
  Clock tomatoClock;
  Clock carrotClock;
  Clock strawberryClock;
  Clock dtt;
  //

  // plant stuff + shop
  bool isBeet = false;
  float beetModifier = 1000;  // timer more orles

  bool isAvo = false;
  float avoModifier = 1000;

  bool isApple = false;
  float appleModifier = 1000;

  bool isBanana = false;
  float bananaModifier = 1000;

  bool isCherry = false;
  float cherryModifier = 1000;

  bool isPressed = false;

  bool isUpgrade1 = false;

  // end plant stuff + shop

  // money functionality

  // end money

  // Load textures

  Texture bd;  // create something for backdrop
  Texture minibd;
  Texture avo;
  Texture beet;
  Texture apple;
  Texture banana;
  Texture cherry;
  Texture shopButton;
  Texture sign;
  Texture sign2;
  Texture sign3;
  Texture sign4;
  Texture sign5;

  Texture back;
  Texture fore;
  Texture fertiliser;
  Texture house;
  Texture worker;
  Texture board1;
  Texture board2;
  Texture board3;
  Texture shopBoard;
  Texture block;
  // End loading textures

  loadRect();

  // load from file
  bd.loadFromFile("bd1.jpg");
  minibd.loadFromFile("minibd.jpg");
  avo.loadFromFile("avocado.png");
  beet.loadFromFile("beetroot.png");
  apple.loadFromFile("apple.png");
  banana.loadFromFile("banana.png");
  cherry.loadFromFile("cherry.png");
  shopButton.loadFromFile("shop.png");
  sign.loadFromFile("sign.png");
  sign2.loadFromFile("sign.png");
  sign3.loadFromFile("sign.png");
  sign4.loadFromFile("sign.png");
  sign5.loadFromFile("sign.png");
  block.loadFromFile("scrollsandblocks.png");

  // end load from file

  if (!bd.loadFromFile("bd1.jpg")) {
    cerr << "Error loading background texture" << endl;
    return -1;  // Exit if the texture fails to load
  }

  if (!minibd.loadFromFile("minibd.jpg")) {
    cerr << "Error loading background texture" << endl;
    return -1;
  }

  if (!avo.loadFromFile("avocado.png")) {
    cerr << "Error loading avocado texture" << endl;
    return -1;
  };

  if (!beet.loadFromFile("beetroot.png")) {
    cerr << "Error loading beetroot texture" << endl;
    return -1;
  }

  // Create sprites for the GFX
  Sprite backdrop(bd);  // creates a sprite so it stays in systme memory
  Sprite minibackdrop(minibd);
  Sprite avocado(avo);
  Sprite beetroot(beet);
  Sprite apples(apple);
  Sprite bananas(banana);
  Sprite cherries(cherry);
  Sprite shops(shopButton);
  Sprite signs(sign);
  Sprite signs2(sign2);
  Sprite signs3(sign3);
  Sprite signs4(sign4);
  Sprite signs5(sign5);
  Sprite blocks;

  // Shop Sprites
  Sprite background(back);
  Sprite foreground(fore);
  Sprite shopSign1(board1);
  Sprite shopSign2(board2);
  Sprite shopSign3(board3);
  Sprite shopSign(shopBoard);
  Sprite fert(fertiliser);
  Sprite greenhouse(house);
  Sprite farmer(worker);

  // End sprites

  // Set Scales
  backdrop.setScale(2.0, 2.0);
  minibackdrop.setScale(2.0 * 1.5, 1.5 * 1.5);
  avocado.setScale(0.14 * 1.5, 0.14 * 1.5);
  beetroot.setScale(0.14 * 1.5, 0.14 * 1.5);
  apples.setScale(0.14 * 1.5, 0.14 * 1.5);
  bananas.setScale(0.14 * 1.5, 0.14 * 1.5);
  cherries.setScale(0.2 * 1.5, 0.2 * 1.5);
  shops.setScale(0.4 * 1.5, 0.4 * 1.5);
  signs.setScale(0.4 * 1.5, 0.4 * 1.5);
  signs2.setScale(0.4 * 1.5, 0.4 * 1.5);
  signs3.setScale(0.4 * 1.5, 0.4 * 1.5);
  signs4.setScale(0.4 * 1.5, 0.4 * 1.5);
  signs5.setScale(0.4 * 1.5, 0.4 * 1.5);
  blocks.setScale(1 * 1.5, 1 * 1.5);

  // Shop scales
  foreground.setScale(2.0 * 1.5, 1.5 * 1.5);
  fert.setScale(0.2 * 1.5, 0.2 * 1.5);
  greenhouse.setScale(0.35 * 1.5, 0.35 * 1.5);
  farmer.setScale(0.045 * 1.5, 0.045 * 1.5);
  shopSign.setScale(0.4 * 1.5, 0.4 * 1.5);
  shopSign1.setScale(0.4 * 1.5, 0.4 * 1.5);
  shopSign2.setScale(0.4 * 1.5, 0.4 * 1.5);
  shopSign3.setScale(0.4 * 1.5, 0.4 * 1.5);
  // End scales

  // Set positions
  FloatRect minibackdropbounds = minibackdrop.getLocalBounds();
  minibackdrop.setOrigin(minibackdropbounds.width / 2,
                         minibackdropbounds.height / 2);
  minibackdrop.setPosition(win.getSize().x / 2, win.getSize().y / 2);

  FloatRect shopPlace = shops.getLocalBounds();
  shops.setOrigin(shopPlace.width / 2, shopPlace.height / 2);
  shops.setPosition(win.getSize().x / 2,
                    win.getSize().y / 2 + 352.5f);  // 235 * 1.5

  FloatRect signsPlacement = signs.getLocalBounds();
  signs.setOrigin(signsPlacement.width / 2, signsPlacement.height / 2);
  signs.setPosition(win.getSize().x / 2 - 687,
                    signsPlacement.height / 2);  // -458 * 1.5

  FloatRect signsPlacement2 = signs2.getLocalBounds();
  signs2.setOrigin(signsPlacement2.width / 2, signsPlacement2.height / 2);
  signs2.setPosition(win.getSize().x / 2 - 687,
                     signsPlacement2.height / 2 + 175);  // +50 * 1.5

  FloatRect signsPlacement3 = signs3.getLocalBounds();
  signs3.setOrigin(signsPlacement3.width / 2, signsPlacement3.height / 2);
  signs3.setPosition(win.getSize().x / 2 - 687,
                     signsPlacement3.height / 2 + 350);  // +150 * 1.5

  FloatRect signsPlacement4 = signs4.getLocalBounds();
  signs4.setOrigin(signsPlacement4.width / 2, signsPlacement4.height / 2);
  signs4.setPosition(win.getSize().x / 2 - 679.5,
                     signsPlacement4.height / 2 + 525);  // +250 * 1.5

  FloatRect signsPlacement5 = signs5.getLocalBounds();
  signs5.setOrigin(signsPlacement5.width / 2, signsPlacement5.height / 2);
  signs5.setPosition(win.getSize().x / 2 - 687,
                     signsPlacement5.height / 2 + 700);  // +357 * 1.5

  FloatRect minibackdropbounds2 = foreground.getLocalBounds();
  foreground.setOrigin(minibackdropbounds2.width / 2,
                       minibackdropbounds2.height / 2);
  foreground.setPosition(win.getSize().x / 2, win.getSize().y / 2);

  FloatRect fertDimensions = fert.getLocalBounds();
  fert.setOrigin(fertDimensions.width / 2, fertDimensions.height / 2);
  fert.setPosition(win.getSize().x / 2 - 687,
                   win.getSize().y / 2 - 30);  // -20 * 1.5

  FloatRect greenhouseDimensions = greenhouse.getLocalBounds();
  greenhouse.setOrigin(greenhouseDimensions.width / 2,
                       greenhouseDimensions.height / 2);
  greenhouse.setPosition(win.getSize().x / 2,
                         win.getSize().y / 2 - 30);  // -20 * 1.5

  FloatRect workerDimensions = farmer.getLocalBounds();
  farmer.setOrigin(workerDimensions.width / 2, workerDimensions.height / 2);
  farmer.setPosition(win.getSize().x / 2 + 687,
                     win.getSize().y / 2 - 30);  // +458 * 1.5

  FloatRect signDimensions = shopSign1.getLocalBounds();
  shopSign1.setOrigin(signDimensions.width / 2, signDimensions.height / 2);
  shopSign1.setPosition(win.getSize().x / 2 - 687,
                        win.getSize().y / 2 - 30);  // -20 * 1.5

  FloatRect signDimensions2 = shopSign2.getLocalBounds();
  shopSign2.setOrigin(signDimensions.width / 2, signDimensions.height / 2);
  shopSign2.setPosition(win.getSize().x / 2,
                        win.getSize().y / 2 - 30);  // -20 * 1.5

  FloatRect signDimensions3 = shopSign3.getLocalBounds();
  shopSign3.setOrigin(signDimensions3.width / 2, signDimensions3.height / 2);
  shopSign3.setPosition(win.getSize().x / 2 + 687,
                        win.getSize().y / 2 - 30);  // +458 * 1.5

  FloatRect shopDimensions2 = shopSign.getLocalBounds();
  shopSign.setOrigin(shopDimensions2.width / 2, shopDimensions2.height / 2);
  shopSign.setPosition(win.getSize().x / 2,
                       win.getSize().y / 2 - 300);  // -200 * 1.5

  FloatRect bounds = events.message1.getLocalBounds();
  events.message1.setPosition(
      lr.DialogBox.getPosition().x +
          (lr.DialogBox.getSize().x - bounds.width) / 2,
      lr.DialogBox.getPosition().y +
          (lr.DialogBox.getSize().y - bounds.height) / 2 - bounds.top);

  // New position
  avocado.setPosition(225, 150);
  beetroot.setPosition(225, 315);
  apples.setPosition(225, 480);
  bananas.setPosition(225, 670);
  cherries.setPosition(225, 820);

  // End positions

  while (win.isOpen()) {
    sf::Event event;
    Event e;
    Event beet;
    while (win.pollEvent(event)) {
      if (event.type == sf::Event::Closed) win.close();

      // anim

      if (event.type == Event::MouseButtonPressed) {
        if (event.mouseButton.button == Mouse::Left) {
          Vector2i mousepos = Mouse::getPosition(win);
          Vector2f mouseposf(static_cast<float>(mousepos.x),
                             static_cast<float>(mousepos.y));
          if (sc.getGlobalBounds().contains(static_cast<Vector2f>(mouseposf))) {
            isUpgrade1 = true;
            float dt = dtt.restart().asSeconds();
            float waitTime = 0.01;
            dtt.restart();
            sc.Update(dt, waitTime);
            // add extra functionality
          }
        }
      }

      if (mh.handleMouse(event, signs,
                         win)) {  // returns a rectangle of bounds and
                                  // static_cast converts 2i to 2f
        if (funds >= 10) {
          funds = funds - 10;
          win.draw(money);
          win.display();
          isAvo = true;
          blueberryClock.restart();
          avoGrowth(funds, fundsInString, money, win, blueberryClock, isAvo,
                    avoModifier);  // calls function
        }
      }
      if (mh.handleMouse(event, signs2, win)) {
        if (funds >= 50) {
          funds = funds - 50;
          win.draw(money);
          win.display();
          isBeet = true;
          beetClock.restart();
          beetGrowth(funds, fundsInString, money, win, beetClock, beetModifier,
                     isBeet);
        }
      };

      if (mh.handleMouse(event, signs3, win)) {
        win.display();
        isApple = true;
        tomatoClock.restart();
        appleGrowth(funds, fundsInString, money, win, tomatoClock,
                    appleModifier, isApple);
      };

      if (mh.handleMouse(event, signs4, win)) {
        win.display();
        isBanana = true;
        carrotClock.restart();
        bananaGrowth(funds, fundsInString, money, win, carrotClock,
                     bananaModifier, isBanana);
      };
      if (mh.handleMouse(event, signs5, win)) {
        win.display();
        isCherry = true;
        strawberryClock.restart();
        cherryGrowth(funds, fundsInString, money, win, strawberryClock,
                     cherryModifier, isCherry);
      };
      if (mh.handleMouse(event, shops, win)) {
        drawShop(win);
        win.display();
      };

      if (events.eventOne == true) {
        while (events.eventOne == true) {
          win.draw(lr.DialogBox);
          win.draw(events.message1);
          win.display();
          if (mh.handleMouseR(event, lr.DialogBox, win)) {
            events.eventOne = false;
          }
        }
      }
      // Do Juans Main implementation (attempt anyway)
      // Update mouse position
      mousePosWindow = sf::Mouse::getPosition(win);
      worldPosition = win.mapPixelToCoords(mousePosWindow);

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
      p.SetDirection(direction);

      // Tomato Button
      tomatoesBackground.buttonNotPressed(0);
      if (tomatoesBackground.getWithinDimensions(
              tomatoesBackground,
              worldPosition)) {  // If mouse position is within in the
                                 // sprite
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
            grid.checkGrid() == true) {         // If the player owns a tile
                                                // that doesnt have a crop
          tomatoesBackground.buttonPressed(0);  // Changes button texture
          plantTomatoes = true;
          plantCrop = true;
        }
      }

      // Blueberries Button
      blueberriesBackground.buttonNotPressed(0);
      if (blueberriesBackground.getWithinDimensions(blueberriesBackground,
                                                    worldPosition)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
            grid.checkGrid() == true) {
          blueberriesBackground.buttonPressed(0);
          plantBlueberries = true;
          plantCrop = true;
        }
      }

      // Carrot Button
      carrotsBackground.buttonNotPressed(0);
      if (carrotsBackground.getWithinDimensions(carrotsBackground,
                                                worldPosition)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
            grid.checkGrid() == true) {
          carrotsBackground.buttonPressed(0);
          plantCarrots = true;
          plantCrop = true;
        }
      }

      // Beets Button
      beetsBackground.buttonNotPressed(0);
      if (beetsBackground.getWithinDimensions(beetsBackground, worldPosition)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
            grid.checkGrid() == true) {
          beetsBackground.buttonPressed(0);
          plantBeets = true;
          plantCrop = true;
        }
      }

      // Strawberries Button
      strawberriesBackground.buttonNotPressed(0);
      if (strawberriesBackground.getWithinDimensions(strawberriesBackground,
                                                     worldPosition)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
            grid.checkGrid() == true) {
          strawberriesBackground.buttonPressed(0);
          plantStrawberries = true;
          plantCrop = true;
        }
      }

      // Set the scroll to the bigger version
      scroll.scrollBig();

      // Shop Button
      shopBackground.buttonNotPressed(1);
      if (shopBackground.getWithinDimensions(shopBackground, worldPosition) &&
          sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        shopBackground.buttonPressed(1);
        scroll.scrollSmall();  // Sets the scroll to the smaller version
                               // temporarily
        openShop = true;
        if (openMore == true) {
          openMore = false;
        }
        if (openCrop == true) {
          openCrop = false;
        }  // Ensures that other bools are false
      }

      // Crops Button
      cropBackground.buttonNotPressed(1);
      if (cropBackground.getWithinDimensions(cropBackground, worldPosition) &&
          sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        cropBackground.buttonPressed(1);
        scroll.scrollSmall();
        openCrop = true;
        if (openShop == true) {
          openShop = false;
        }
        if (openMore == true) {
          openMore = false;
        }
      }

      // More Button
      moreBackground.buttonNotPressed(1);
      if (moreBackground.getWithinDimensions(moreBackground, worldPosition) &&
          sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        moreBackground.buttonPressed(1);
        scroll.scrollSmall();
        openMore = true;
        if (openShop == true) {
          openShop = false;
        }
        if (openCrop == true) {
          openCrop = false;
        }

        float dt;
        {
          const auto newTp = std::chrono::steady_clock::now();
          dt = std::chrono::duration<float>(newTp - tp).count();
          tp = newTp;
        }

        // std::cout << "OpenShop: " << openShop << ", OpenCrop: " <<
        // openCrop << ", OpenMore: " << openMore << std::endl;

        // Update tile selector, UI text, coin animation, and player's
        // grid position
        p.Update(dt, charWaitTime, false);
        grid.updateCharGridPosition(p.getCharPosition(), charPosGrid);
        coin.Update(dt, coinWaitTime, false);
        balance.updateText(p, "", 0);
        shop.updateText(p, "Shop", 1);
        crop.updateText(p, "Crop", 1);
        more.updateText(p, "More", 1);

        if (worldPosition.x >= gridOffsetX && worldPosition.y >= gridOffsetY &&
            worldPosition.x < gridSizeF * mapSizeX + gridOffsetX &&
            worldPosition.y <
                gridSizeF * mapSizeY +
                    gridOffsetY) {  // Checks if the mouse is on a tile
          grid.updateMouseGridPosition(worldPosition,
                                       mousePosGrid);  // Update grid position
          grid.updateTileSelector(mousePosGrid,
                                  plantCrop);  /// Update tile selection
          if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
              plantCrop == false) {              // Checks if the player is
                                                 // purchasing a tile or crop
            grid.purchaseGrid(mousePosGrid, p);  // Purchase a tile
          } else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
                     plantTomatoes == true) {
            if (grid.getIsLocked(mousePosGrid) == false &&
                grid.getHasCrop(mousePosGrid) ==
                    false) {  // Checks if the player has a tile
                              // with no crop on it
              Crop* newTomato =
                  new Tomatoes({mousePosGrid.x * gridSizeF + gridOffsetX,
                                mousePosGrid.y * gridSizeF +
                                    gridOffsetY});  // Dynamically create a
                                                    // crop to the position of
                                                    // the tile
              grid.plantCrop(mousePosGrid, newTomato,
                             p);      // Plant the crop
              plantTomatoes = false;  // Resets booleans to false
              plantCrop = false;
            }
          } else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
                     plantBlueberries == true) {
            if (grid.getIsLocked(mousePosGrid) == false &&
                grid.getHasCrop(mousePosGrid) == false) {
              Crop* newBlueberries =
                  new Blueberries({mousePosGrid.x * gridSizeF + gridOffsetX,
                                   mousePosGrid.y * gridSizeF + gridOffsetY});
              grid.plantCrop(mousePosGrid, newBlueberries, p);
              plantBlueberries = false;
              plantCrop = false;
            }
          } else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
                     plantCarrots == true) {
            if (grid.getIsLocked(mousePosGrid) == false &&
                grid.getHasCrop(mousePosGrid) == false) {
              Crop* newCarrots =
                  new Carrots({mousePosGrid.x * gridSizeF + gridOffsetX,
                               mousePosGrid.y * gridSizeF + gridOffsetY});
              grid.plantCrop(mousePosGrid, newCarrots, p);
              plantCarrots = false;
              plantCrop = false;
            }
          } else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
                     plantBeets == true) {
            if (grid.getIsLocked(mousePosGrid) == false &&
                grid.getHasCrop(mousePosGrid) == false) {
              Crop* newBeets =
                  new Beets({mousePosGrid.x * gridSizeF + gridOffsetX,
                             mousePosGrid.y * gridSizeF + gridOffsetY});
              grid.plantCrop(mousePosGrid, newBeets, p);
              plantBeets = false;
              plantCrop = false;
            }
          } else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
                     plantStrawberries == true) {
            if (grid.getIsLocked(mousePosGrid) == false &&
                grid.getHasCrop(mousePosGrid) == false) {
              Crop* newStrawberries =
                  new Strawberries({mousePosGrid.x * gridSizeF + gridOffsetX,
                                    mousePosGrid.y * gridSizeF + gridOffsetY});
              grid.plantCrop(mousePosGrid, newStrawberries, p);
              plantStrawberries = false;
              plantCrop = false;
            }
          }
        }

        // Boundary for the character
        if (p.getCharPosition().x < 0.f) {
          p.setCharPosition(0.f, p.getCharPosition().y);
        }
        if (p.getCharPosition().y < 96.f) {
          p.setCharPosition(p.getCharPosition().x, 96.f);
        }
        if (p.getCharPosition().x > gridSizeF * mapSizeX) {
          p.setCharPosition(gridSizeF * mapSizeX, p.getCharPosition().y);
        }
        if (p.getCharPosition().y > (gridSizeF * mapSizeY) + 64.f) {
          p.setCharPosition(p.getCharPosition().x,
                            (gridSizeF * mapSizeY) + 64.f);
        }
      }
      // flags
      if (isBeet == true) {
        if (beetClock.getElapsedTime().asMilliseconds() >= beetModifier) {
          beetGrowth(funds, fundsInString, money, win, beetClock, beetModifier,
                     isBeet);
        }
      };

      if (isAvo == true) {
        if (blueberryClock.getElapsedTime().asMilliseconds() >= avoModifier) {
          avoGrowth(funds, fundsInString, money, win, blueberryClock, isAvo,
                    avoModifier);
        }
      }
      if (isApple == true) {
        if (tomatoClock.getElapsedTime().asMilliseconds() >= appleModifier) {
          appleGrowth(funds, fundsInString, money, win, tomatoClock,
                      appleModifier, isApple);
        }
      }

      if (isBanana == true) {
        if (carrotClock.getElapsedTime().asMilliseconds() >= bananaModifier) {
          bananaGrowth(funds, fundsInString, money, win, carrotClock,
                       bananaModifier, isBanana);
        }
      }

      if (isCherry == true) {
        if (strawberryClock.getElapsedTime().asMilliseconds() >=
            cherryModifier) {
          appleGrowth(funds, fundsInString, money, win, strawberryClock,
                      cherryModifier, isCherry);
        }
      }

      if (isUpgrade1 == true) {
        if (dtt.getElapsedTime().asSeconds() >= 0.3) {
          float dt = dtt.restart().asSeconds();
          float waitTime = 0.3;
          sc.Update(dt, waitTime);
          isUpgrade1 = false;
        }
      }
    }

    float dt;
    {
      const auto newTp = std::chrono::steady_clock::now();
      dt = std::chrono::duration<float>(newTp - tp).count();
      tp = newTp;
    }

    // draw the windows
    win.clear();

    // implement juans

    win.draw(backdrop);
    balanceBackground.draw(win, 0);
    fence.draw(win, 1);
    grid.draw(win, dt, resetFrame, charPosGrid, p);
    coin.Draw(win);
    p.Draw(win);
    balance.draw(win);
    scroll.draw(win, 3);
    tomatoesBackground.draw(win, 2);
    tomatoesButton.draw(win, 2);
    blueberriesBackground.draw(win, 2);
    blueberriesButton.draw(win, 2);
    carrotsBackground.draw(win, 2);
    carrotsButton.draw(win, 2);
    beetsBackground.draw(win, 2);
    beetsButton.draw(win, 2);
    strawberriesBackground.draw(win, 2);
    strawberriesButton.draw(win, 2);
    shopBackground.draw(win, 2);
    shop.draw(win);
    cropBackground.draw(win, 2);
    crop.draw(win);
    moreBackground.draw(win, 2);
    more.draw(win);

    // end juan RAWR
    win.draw(backdrop);
    win.draw(minibackdrop);
    //
    win.draw(signs);
    win.draw(signs2);
    win.draw(signs3);
    win.draw(signs4);
    win.draw(signs5);
    //

    //
    win.draw(avocado);
    win.draw(beetroot);
    win.draw(apples);
    win.draw(bananas);
    win.draw(cherries);
    //
    win.draw(shops);
    win.draw(money);
    //

    win.draw(blocks);
    events.genRand();

    win.display();
  };

  return 0;
};
