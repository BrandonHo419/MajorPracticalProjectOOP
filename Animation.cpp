#include "Animation.h"

Animation::Animation(int x, int y, int width, int height, int numOfFrames,
                     int animationID) {
  switch (animationID) { // animationdID for selecting the correct sprite sheets
    case 1:
      texture.loadFromFile("Character Sprites.png");
      break;
    case 2:
      texture.loadFromFile("crops.png");
      break;
    default:
      break;
  }
  frames.resize(numOfFrames); // resizes the vector by the number of frames an animation has
  if (animationID == 2) { // Different sprite sheets are tiled differently, some horizontal, some vertical
    for (int i = 0; i < numOfFrames; i++) {
      frames[i] = {x, y + i * (height * 2), width, height}; // Crops sprite sheet
    }
  } else {
    for (int i = 0; i < numOfFrames; i++) {
      frames[i] = {x + i * width, y, width, height}; // Character sprite sheet
    }
  }
}

void Animation::ApplyAnimToSprite(sf::Sprite& s) const {
  s.setTexture(texture);
  s.setTextureRect(frames[currentFrame]);
}

void Animation::Update(float dt, float waitTime, bool resetFrame,
                       int animationID) {
  time += dt;
  if (animationID == 2) {
    if (resetFrame == true && isPaused == true) { // Resets the frame to 0 once character walks over the tile
      isPaused = false;
      currentFrame = 0;
      time = 0;
    }
  }

  if (animationID == 2) { // For crops, if the animation is paused it will not reset the frame until the condition is met
    if (isPaused == false) {
      while (time >= waitTime) {
        time -= waitTime;
        NextAnimation(resetFrame, animationID);
      }
    }
  } else if (animationID != 2) {
    while (time >= waitTime) {
      time -= waitTime;
      NextAnimation(resetFrame, animationID);
    }
  }
}

void Animation::NextAnimation(bool resetFrame, int animationID) {
  if (animationID == 2) {
    if (currentFrame == frames.size()-1) {
      isPaused = true; // Pause the animation on the last frame
    } else {
      currentFrame++;  // Increase frame count
    }
  } else if (++currentFrame >= frames.size()) {
    currentFrame = 0; // Reset to 0 for animations that are not crops
  }
}

float Animation::getTime() {
    return time;
}