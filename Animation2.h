#ifndef ANIMATION2_H
#define ANIMATION2_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Requirements.h"

// class Animation {
//  public:
   //  Animation() = default;
   //  Animation(int x, int y, int width, int height, int numOfFrames, int animationID);
   //  void ApplyAnimToSprite(sf::Sprite& s) const;
   //  void Update(float dt, float waitTime);
//  private:
   //  void NextAnimation();
//  private:
    //static constexpr float waitTime = 0.1f;
   //  sf::Texture texture;
   //  std::vector<sf::IntRect> frames; 
   //  int currentFrame = 0;
   //  float time = 0.0f; // Keep track fo time elapsed until next frame 
// };

class Animation2 {
 public:
    Animation2() = default;
    Animation2(int x, int y, int width, int height, int numOfFrames, int animation2ID)  {
        switch (animation2ID) {
            case 0:
                texture.loadFromFile("scrollsandblocks.png");
                break;
            case 1:
                texture.loadFromFile("coin_gold.png");
                break;
            case 2:
                texture.loadFromFile("crops.png");
                break;
            default:
                break;
        }
        frames.resize(numOfFrames);
        if (animation2ID == 2 || animation2ID == 0) {
            for (int i = 0; i < numOfFrames; i++) {
                frames[i] = {x, y + i * (height * 2), width, height};
            }
        } else {
            for (int i = 0; i < numOfFrames; i++) {
                frames[i] = {x + i * width, y, width, height};
            }
        }
    }

    void ApplyAnimToSprite(sf::Sprite& s) const {
        s.setTexture(texture);
        s.setTextureRect(frames[currentFrame]);
        s.setScale(sf::Vector2f(1.2, 1.2));
    }

    void Updates(float dt, float waitTime) {
        time += dt;
        while (time >= waitTime) {
            time -= waitTime;
            NextAnimation2();
        }
    }

 private:
    void NextAnimation2() {
        if (++currentFrame >= frames.size()) {
            currentFrame = 0;
        }
    }

 private:
    sf::Texture texture;
    std::vector<sf::IntRect> frames;
    int currentFrame = 0;
    float time = 0.0f;  // Keep track of time elapsed until next frame
};

#endif


