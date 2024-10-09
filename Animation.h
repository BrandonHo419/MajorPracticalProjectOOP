#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class Animation {
 public:
    Animation() = default;
    Animation(int x, int y, int width, int height, int numOfFrames, int animationID); // Calculates the frame according to a sprite sheet
    void ApplyAnimToSprite(sf::Sprite& s) const; // Applies frame to sprite
    void Update(float dt, float waitTime, bool resetFrame, int animationID); // Calculates how long the frame should last
    float getTime(); // Gets the time
 private:
    void NextAnimation(bool resetFrame, int animationID); // Adds or resets the currentFrame
 private:
    sf::Texture texture;
    std::vector<sf::IntRect> frames; // Vector of the frames an animation has
    int currentFrame = 0;
    float time = 0.0f; // Keeps track of time elapsed until next frame 
    bool isPaused = false; // For pausing the animation for crops
};

#endif