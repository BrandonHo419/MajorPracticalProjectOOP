#include "GridMap.h"

#include <iostream>
#include <sstream>

GridMap::GridMap(float gridSizeF, unsigned gridSizeU, int mapSizeX,
                 int mapSizeY, float gridOffsetX, float gridOffsetY)
    : gridSizeF(gridSizeF),
      gridSizeU(gridSizeU),
      mapSizeX(mapSizeX),
      mapSizeY(mapSizeY),
      gridOffsetX(gridOffsetX),
      gridOffsetY(gridOffsetY),
      tilesPurchased(0) {
  // Tile Color (Brown)
  tileColor = sf::Color(92, 64, 51);

  // Initialize tiles
  for (int x = 0; x < mapSizeX; x++) {
    for (int y = 0; y < mapSizeY; y++) {
      tileMap[x][y].tileiIsLocked = true;
      tileMap[x][y].price = basePrice;
      tileMap[x][y].hasCrop = false;
      tileMap[x][y].plantedCrop = nullptr;
      tileMap[x][y].shape.setSize(sf::Vector2f(gridSizeF, gridSizeF));
      tileMap[x][y].shape.setFillColor(tileColor);
      tileMap[x][y].shape.setOutlineColor(sf::Color::Black);
      tileMap[x][y].shape.setOutlineThickness(3.f);
      tileMap[x][y].shape.setPosition(x * gridSizeF + gridOffsetX,
                                      y * gridSizeF + gridOffsetY);
    }
  }

  // Default tiles for player to begin using
  tileMap[5][3].tileiIsLocked = false;
  tileMap[5][3].price = 0;

  // Initialize tile selector
  tileSelector.setSize(sf::Vector2f(gridSizeF, gridSizeF));
  tileSelector.setFillColor(sf::Color::Transparent);
  tileSelector.setOutlineThickness(6.f);
  tileSelector.setOutlineColor(sf::Color::White);
}

void GridMap::updateTileSelector(const sf::Vector2u& mousePosGrid, bool cropSelected, bool cropDelete) {
  tileSelector.setPosition(mousePosGrid.x * gridSizeF + gridOffsetX,
                           mousePosGrid.y * gridSizeF + gridOffsetY);
  if (cropSelected) { // If player purchases a crop to plant
    tileSelector.setOutlineColor(sf::Color::Green);
  } else if (cropDelete) {
    tileSelector.setOutlineColor(sf::Color::Red);
  } else {
    tileSelector.setOutlineColor(sf::Color::White);
  }
}

void GridMap::draw(sf::RenderWindow& window, float dt, bool& resetFrame, sf::Vector2u& charPosGrid, Player& player) {
  std::vector<sf::Text> texts;  // Collect text objects
  if (!font.loadFromFile("Albertson.otf")) {
    throw std::runtime_error("Failed to load font");
  }
  // Draw the grid tiles
  for (int x = 0; x < mapSizeX; x++) {
    for (int y = 0; y < mapSizeY; y++) {
      if (tileMap[x][y].tileiIsLocked == false) {
        if (!tileMap[x][y].tileTexture.loadFromFile("plowed_soil.png")) {
          throw std::runtime_error("Failed to load texture");
        }
        tileMap[x][y].sprite.setTexture(tileMap[x][y].tileTexture);
        tileMap[x][y].sprite.setTextureRect(sf::IntRect(0, 160, 32, 32));
        tileMap[x][y].sprite.setPosition(x * gridSizeF + gridOffsetX,
                                         y * gridSizeF + gridOffsetY);
        tileMap[x][y].sprite.setScale(sf::Vector2f(3, 3));
        // Adjacent squares
        if (x + 1 < mapSizeX && tileMap[x + 1][y].tileiIsLocked == true) {  // Right Square
          text.setFont(font);
          text.setCharacterSize(28);
          text.setFillColor(sf::Color::Yellow);
          text.setPosition((x + 1) * gridSizeF + gridOffsetX,
                           y * gridSizeF + gridOffsetY);
          std::stringstream ss;
          ss << "" << "\n";
          ss << "  $" << tileMap[x + 1][y].price << "\n"; // Shows the price of the square
          text.setString(ss.str());
          texts.push_back(text);
        }
        if (x > 0 && tileMap[x - 1][y].tileiIsLocked == true) {  // Left Square
          text.setFont(font);
          text.setCharacterSize(28);
          text.setFillColor(sf::Color::Yellow);
          text.setPosition((x - 1) * gridSizeF + gridOffsetX,
                           y * gridSizeF + gridOffsetY);
          std::stringstream ss;
          ss << "" << "\n";
          ss << "  $" << tileMap[x - 1][y].price << "\n";
          text.setString(ss.str());
          texts.push_back(text);
        }
        if (y > 0 && tileMap[x][y - 1].tileiIsLocked == true) {  // Up Square
          text.setFont(font);
          text.setCharacterSize(28);
          text.setFillColor(sf::Color::Yellow);
          text.setPosition(x * gridSizeF + gridOffsetX,
                           (y - 1) * gridSizeF + gridOffsetY);
          std::stringstream ss;
          ss << "" << "\n";
          ss << "  $" << tileMap[x][y - 1].price << "\n";
          text.setString(ss.str());
          texts.push_back(text);
        }
        if (y + 1 < mapSizeY && tileMap[x][y + 1].tileiIsLocked == true) {  // Down Square
          text.setFont(font);
          text.setCharacterSize(28);
          text.setFillColor(sf::Color::Yellow);
          text.setPosition(x * gridSizeF + gridOffsetX,
                           (y + 1) * gridSizeF + gridOffsetY);
          std::stringstream ss;
          ss << "" << "\n";
          ss << "  $" << tileMap[x][y + 1].price << "\n";
          text.setString(ss.str());
          texts.push_back(text);
        }
      }
      window.draw(tileMap[x][y].shape);
      window.draw(tileMap[x][y].sprite);
      if (tileMap[x][y].hasCrop) {
                bool resetFrame = (x == charPosGrid.x && y == charPosGrid.y); // If the player is over a tile with a crop
                tileMap[x][y].plantedCrop->Update(dt, tileMap[x][y].plantedCrop->getGrowthTime(), resetFrame, player); //Animate the crop
                tileMap[x][y].plantedCrop->Draw(window);  // Draw any crop that exists on the tile
      }
    }
  }

  // Draw all texts for purchasing a tile
  for (const auto& t : texts) {
    window.draw(t);
  }

  // Draw the tile selector
  window.draw(tileSelector);
}

void GridMap::updateMouseGridPosition(const sf::Vector2f& worldPosition,
                                      sf::Vector2u& mousePosGrid) {
  if (worldPosition.x >= gridOffsetX) {
    mousePosGrid.x = (worldPosition.x - gridOffsetX) / gridSizeU;
    if (mousePosGrid.x >= mapSizeX) {
      mousePosGrid.x = mapSizeX - 1;  // Set to max index
    }
  } else {
    mousePosGrid.x = 0;
  }

  if (worldPosition.y >= gridOffsetY) {
    mousePosGrid.y = (worldPosition.y - gridOffsetY) / gridSizeU;
    if (mousePosGrid.y >= mapSizeY) {
      mousePosGrid.y = mapSizeY - 1;  // Set to max index
    }
  } else {
    mousePosGrid.y = 0;
  }
}

void GridMap::updateCharGridPosition(const sf::Vector2f& charPos,
                                      sf::Vector2u& charPosGrid) {
  if (charPos.x >= 0) { // Boundary for the player 
    charPosGrid.x = charPos.x / gridSizeU;
    if (charPosGrid.x >= mapSizeX) {
      charPosGrid.x = mapSizeX - 1;  // Set to max index
    }
  } else {
    charPosGrid.x = 0;
  }

  if (charPos.y >= 0) {
    charPosGrid.y = (charPos.y / gridSizeU)-1;
    if (charPosGrid.y >= mapSizeY) {
      charPosGrid.y = mapSizeY - 1;  // Set to max index
    }
  } else {
    charPosGrid.y = 0;
  }

  //std::cout << "X: " << charPosGrid.x << ", Y: " << charPosGrid.y << std::endl;
}

void GridMap::purchaseGrid(const sf::Vector2u& mousePosGrid, Player& player) {
  // Check if the tile is available for purchase
  if (tileMap[mousePosGrid.x][mousePosGrid.y].tileiIsLocked == true) {
    if ((mousePosGrid.x + 1 < mapSizeX &&
         tileMap[mousePosGrid.x + 1][mousePosGrid.y].tileiIsLocked == false) ||
        (mousePosGrid.x > 0 &&
         tileMap[mousePosGrid.x - 1][mousePosGrid.y].tileiIsLocked == false) ||
        (mousePosGrid.y + 1 < mapSizeY &&
         tileMap[mousePosGrid.x][mousePosGrid.y + 1].tileiIsLocked == false) ||
        (mousePosGrid.y > 0 &&
         tileMap[mousePosGrid.x][mousePosGrid.y - 1].tileiIsLocked == false)) { // Checks the player does not already own the crop
      if (player.getMoney() >= tileMap[mousePosGrid.x][mousePosGrid.y].price) { // Checks if the player can afford the tile
        player.setMoney(tileMap[mousePosGrid.x][mousePosGrid.y].price); // Subtracts the player's money from the price of a tile
        tileMap[mousePosGrid.x][mousePosGrid.y].tileiIsLocked = false;
        tileMap[mousePosGrid.x][mousePosGrid.y].price = 0;
        tilesPurchased += 1;
        for (int x = 0; x < mapSizeX; x++) {
          for (int y = 0; y < mapSizeY; y++) {
            if (tileMap[x][y].tileiIsLocked == true) {
              tileMap[x][y].price = tileMap[x][y].price + (tilesPurchased * priceIncrease); // Increases price of all tiles
            }
          }
        }
        //std::cout << "Land Purchased!" << std::endl;
      } else {
        //std::cout << "Invalid Purchase" << std::endl;
      }
    }
  } else {
    //std::cout << "Land already owned" << std::endl;
  }
}

void GridMap::plantCrop(const sf::Vector2u& mousePosGrid, Crop* crop, Player& player) {
  tileMap[mousePosGrid.x][mousePosGrid.y].plantedCrop = crop;
  tileMap[mousePosGrid.x][mousePosGrid.y].hasCrop = true;
}

bool GridMap::getIsLocked(const sf::Vector2u& mousePosGrid) {
  return tileMap[mousePosGrid.x][mousePosGrid.y].tileiIsLocked;
}

bool GridMap::getHasCrop(const sf::Vector2u& mousePosGrid) {
  return tileMap[mousePosGrid.x][mousePosGrid.y].hasCrop;
}

bool GridMap::checkGridFor(const std::string action) {
  for (int x = 0; x < mapSizeX; x++) {
    for (int y = 0; y < mapSizeY; y++) {
      if (action == "Delete") {
        if (tileMap[x][y].tileiIsLocked == false && tileMap[x][y].hasCrop == true) { // If there is a crop
          return true;
        } 
      } else {
        if (tileMap[x][y].tileiIsLocked == false && tileMap[x][y].hasCrop == false) { // If there isnt a crop
          return true;
        }
      }
    }
  }
  return false;
}

void GridMap::updateVariables(float growthTime, float sellValue, std::string cropName) {
  for (int x = 0; x < mapSizeX; x++) {
    for (int y = 0; y < mapSizeY; y++) {
      if (tileMap[x][y].hasCrop == true && tileMap[x][y].plantedCrop->getCropType() == cropName) { // Update all variables
        tileMap[x][y].plantedCrop->setGrowthTime(growthTime);
        tileMap[x][y].plantedCrop->setSellValue(sellValue);
      } 
    }
  }
}

void GridMap::deleteCrop(const sf::Vector2u& mousePosGrid) { // Delete a crop
  delete tileMap[mousePosGrid.x][mousePosGrid.y].plantedCrop;
  tileMap[mousePosGrid.x][mousePosGrid.y].hasCrop = false;
}