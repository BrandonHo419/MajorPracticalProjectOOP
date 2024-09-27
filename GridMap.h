#ifndef GRIDMAP_H
#define GRIDMAP_H
#include <SFML/Graphics.hpp>

class GridMap {
 public:
  GridMap(float gridSizeF, unsigned gridSizeU, int mapSizeX, int mapSizeY, float gridOffsetX, float gridOffsetY);
  void updateTileSelector(const sf::Vector2u& mousePosGrid);
  void draw(sf::RenderWindow& window);
  void updateMouseGridPosition(const sf::Vector2i& mousePosWindow, sf::Vector2u& mousePosGrid);

 private:
  float gridSizeF;
  unsigned gridSizeU;
  int const mapSizeX;
  int const mapSizeY;
  float const gridOffsetX;
  float const gridOffsetY;

  sf::RectangleShape tileMap[24][12];
  sf::RectangleShape tileSelector;
  sf::Color tileColor;

};

#endif
