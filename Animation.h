#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

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

class Animation {
 public:
    Animation() = default;
    Animation(int x, int y, int width, int height, int numOfFrames, int animationID)  {
        switch (animationID) {
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
        if (animationID == 2 || animationID == 0) {
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

    void Update(float dt, float waitTime) {
        time += dt;
        while (time >= waitTime) {
            time -= waitTime;
            NextAnimation();
        }
    }

 private:
    void NextAnimation() {
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


