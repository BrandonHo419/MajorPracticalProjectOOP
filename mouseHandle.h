#include "Player.h"
#include "Requirements.h"

#ifndef MOUSEHANDLE_H
#define MOUSEHANDLE_H

class mouseHandle {
 private:
 protected:
 public:
  mouseHandle() {}

  bool handleMouse(Event& e, Sprite SpriteToGetBoundsFor,
                   RenderWindow& window) {
    if (e.type == Event::MouseButtonPressed) {  // checks if it is a mouse press
      if (e.mouseButton.button ==
          Mouse::Left) {  // checks whether it was a left mouse button press
        Vector2i mousepos = Mouse::getPosition(
            window);  // retrieves the current mouse position (x and y)
        if (SpriteToGetBoundsFor.getGlobalBounds().contains(
                static_cast<Vector2f>(mousepos))) {
          return true;
        }
      }
    };

    return false;
  };

  bool handleMouseR(Event& e, RectangleShape RectangleShapeToGetBounds,
                    RenderWindow& window) {
    if (e.type == Event::MouseButtonPressed) {
      if (e.mouseButton.button == Mouse::Left) {
        Vector2i mousepos = Mouse::getPosition(window);
        if (RectangleShapeToGetBounds.getGlobalBounds().contains(
                static_cast<Vector2f>(mousepos))) {
          return true;
        }
      }
    };
    return false;
  }

  ~mouseHandle() {};
};

#endif
