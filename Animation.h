#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Animation {
 public:
    Animation() = default;
    Animation(int x, int y, int width, int height, int numOfFrames, int animationID);
    void ApplyAnimToSprite(sf::Sprite& s) const;
    void Update(float dt, float waitTime);
 private:
    void NextAnimation();
 private:
    //static constexpr float waitTime = 0.1f;
    sf::Texture texture;
    std::vector<sf::IntRect> frames; 
    int currentFrame = 0;
    float time = 0.0f; // Keep track fo time elapsed until next frame 
};

#endif