#ifndef GRIDMAP_H
#define GRIDMAP_H
#include <SFML/Graphics.hpp>

#include "Crop.h"
#include "Player.h"

class GridMap {
 public:
  GridMap(float gridSizeF, unsigned gridSizeU, int mapSizeX, int mapSizeY,
          float gridOffsetX, float gridOffsetY); // Initialises variables
  void updateTileSelector(const sf::Vector2u& mousePosGrid, bool cropSelected, bool cropDelete); // Update tile selector according to the position of the mouse
  void draw(sf::RenderWindow& window, float dt, bool& resetFrame, sf::Vector2u& charPosGrid, Player& player); // Draws the grid
  void updateMouseGridPosition(const sf::Vector2f& worldPosition, sf::Vector2u& mousePosGrid); // Updates the grid position from the mouse
  void updateCharGridPosition(const sf::Vector2f& charPos, sf::Vector2u& charPosGrid); // Ensures a boundary for the player
  void purchaseGrid(const sf::Vector2u& mousePosGrid, Player& player); // For purchasing a tile
  void plantCrop(const sf::Vector2u& mousePosGrid, Crop* crop, Player& player); // For planting a crop on a tile
  bool getIsLocked(const sf::Vector2u& mousePosGrid); // Gets if the tile is locked
  bool getHasCrop(const sf::Vector2u& mousePosGrid); // Gets if the tile has a crop
  bool checkGridFor(const std::string action); // Checks the grid for unlocked tiles with no crops
  void updateVariables(float growthTime, float sellValue, std::string cropName); // Update all crops variables from the shop
  void deleteCrop(const sf::Vector2u& mousePosGrid); // Delete a crop

  struct Tile { // Struct for each tile 
    sf::RectangleShape shape;
    bool tileiIsLocked;
    bool hasCrop;
    float price;
    sf::Texture tileTexture;
    sf::Sprite sprite;
    Crop* plantedCrop;
    Tile() : tileiIsLocked(false), hasCrop(false), plantedCrop(nullptr) {}

    ~Tile() {
      if (plantedCrop)
        delete plantedCrop;  // Clean up dynamically allocated crops
    }
  };

 private:
  float gridSizeF; // Size of a tile
  unsigned gridSizeU; // Size of a tile as an unsigned int
  int const mapSizeX; // X amount of tiles
  int const mapSizeY; // Y amount of tiles
  float const gridOffsetX; // Positions the grid off by x
  float const gridOffsetY; // Positions the grid off by y
  float const basePrice = 50; // Price of each
  float const priceIncrease = 200; // For every tile purchased, it increases the price
  int tilesPurchased; // Amount of tiles purchases/unlocked

  Tile tileMap[18][8];
  sf::RectangleShape tileSelector;
  sf::Color tileColor;
  sf::Font font;
  sf::Text text;
};

#endif
