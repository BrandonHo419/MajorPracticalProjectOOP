#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Animation.h"

class Player {
 private:
  enum class indexAnimation {
    Upwards,
    UpwardsIdle,
    Downards,
    DownwardsIdle,
    Left,
    LeftIdle,
    Right,
    RightIdle,
    Count
  };  // Stores animations

 public:
  Player(const sf::Vector2f& position);   // Initialises the players position
  void Draw(sf::RenderTarget& rt) const;  // Draws the player
  void SetDirection(const sf::Vector2f& direction);  // Sets which direction the
                                                     // player is facing
  void Update(
      float dt, float waitTime,
      bool resetFrame);  // Updates the animation of the player every frame
  sf::Vector2f getCharPosition();  // Gets the player's/character position
  void setCharPosition(float x,
                       float y);  // Sets the player's/character position
  void setMoney(float cost);      // Sets the players money
  void addMoney(float revenue);   // Add to the player's money
  float getMoney();               // Gets the player's money
  std::string getMoneyStr();      // Gets the player's money as a string

 private:
  static constexpr float speed = 150.0f;  // How fast the player can move
  sf::Vector2f position;
  sf::Vector2f velocity = {0.f, 0.f};
  sf::Sprite sprite;
  Animation animations[int(
      indexAnimation::Count)];  // Create an array of different animations
  indexAnimation currentAnimation = indexAnimation::Upwards;

 protected:
  float money;
};

#endif