#include "Requirements.h"
#include "Animation2.h"
#ifndef SCROLLANIMATION_H
#define SCROLLANIMATION_H


// class Scroll{
//  private:
//   enum class indexAnimation { scroll, Count };

//  public:
//   Scroll(const sf::Vector2f& position);
//   void Draw(sf::RenderTarget& rt) const;
//   void Update(float dt, float waitTime);

//  private:
//   sf::Vector2f position;
//   sf::Sprite sprite;
//   Animation animations[int(indexAnimation::Count)]; // Create an array of different animations
//   indexAnimation currentAnimation = indexAnimation::scroll;
// };


class Scroll {
 private:
  enum class indexAnimation { scroll, Count };

 public:
  Scroll(const sf::Vector2f& position) : position(position) {
      // Beets animation
      animations[int(indexAnimation::scroll)] = Animation2(0, 32*2, 96, 32, 2, 0);
  }

  void Draw(sf::RenderTarget& rt) const {
      rt.draw(sprite);
  }

  void Update(float dt, float waitTime) {
      animations[int(currentAnimation)].Updates(dt, waitTime);
      animations[int(currentAnimation)].ApplyAnimToSprite(sprite);
      sprite.setPosition(position);
  }

  FloatRect getGlobalBounds() {
    return sprite.getGlobalBounds();  
}


 private:
  sf::Vector2f position;
  sf::Sprite sprite;
  Animation2 animations[int(indexAnimation::Count)]; // Create an array of different animations
  indexAnimation currentAnimation = indexAnimation::scroll;
};

#endif


