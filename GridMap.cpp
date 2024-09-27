#include "GridMap.h"

GridMap::GridMap(float gridSizeF, unsigned gridSizeU, int mapSizeX,
                 int mapSizeY, float gridOffsetX, float gridOffsetY)
    : gridSizeF(gridSizeF),
      gridSizeU(gridSizeU),
      mapSizeX(mapSizeX),
      mapSizeY(mapSizeY),
      gridOffsetX(gridOffsetX),
      gridOffsetY(gridOffsetY) {
  // Tile Color
  tileColor = sf::Color(92, 64, 51); 

  // Initialize tiles
  for (int x = 0; x < mapSizeX; x++) {
    for (int y = 0; y < mapSizeY; y++) {
      //tileMap[x][y] = Tile(true, 100);
      tileMap[x][y].setSize(sf::Vector2f(gridSizeF, gridSizeF));
      tileMap[x][y].setFillColor(tileColor);
      tileMap[x][y].setOutlineColor(sf::Color::Black);
      tileMap[x][y].setOutlineThickness(3.f);
      tileMap[x][y].setPosition(x * gridSizeF + gridOffsetX,
                                y * gridSizeF + gridOffsetY);
    }
  }

  // Initialize tile selector
  tileSelector.setSize(sf::Vector2f(gridSizeF, gridSizeF));
  tileSelector.setFillColor(sf::Color::Transparent);
  tileSelector.setOutlineThickness(6.f);
  tileSelector.setOutlineColor(sf::Color::Green);
}

void GridMap::updateTileSelector(const sf::Vector2u& mousePosGrid) {
  tileSelector.setPosition(mousePosGrid.x * gridSizeF + gridOffsetX,
                           mousePosGrid.y * gridSizeF + gridOffsetY);
}

void GridMap::draw(sf::RenderWindow& window) {
  // Draw the grid tiles
  for (int x = 0; x < mapSizeX; x++) {
    for (int y = 0; y < mapSizeY; y++) {
      window.draw(tileMap[x][y]);
    }
  }

  // Draw the tile selector
  window.draw(tileSelector);
}

void GridMap::updateMouseGridPosition(const sf::Vector2i& mousePosWindow, sf::Vector2u& mousePosGrid) {
  if (mousePosWindow.x >= gridOffsetX) {
    mousePosGrid.x = (mousePosWindow.x - gridOffsetX) / gridSizeU;
  } else {
    mousePosGrid.x = mapSizeX;  // Out of bounds
  }
  if (mousePosWindow.y >= gridOffsetY) {
    mousePosGrid.y = (mousePosWindow.y - gridOffsetY) / gridSizeU;
  } else {
    mousePosGrid.y = mapSizeY;  // Out of bounds
  }
}