#include "Animation.h"

Animation::Animation(int x, int y, int width, int height, int numOfFrames, int animationID) {
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
        for (int i =0; i < numOfFrames; i++) {
            frames[i] = {x, y + i * (height*2), width, height};
        }
    } else {
        for (int i =0; i < numOfFrames; i++) {
            frames[i] = {x + i *width, y, width, height};
        }
    }
}

void Animation::ApplyAnimToSprite(sf::Sprite& s) const {
    s.setTexture(texture);
    s.setTextureRect(frames[currentFrame]);
    s.setScale(sf::Vector2f(2, 2));
}

void Animation::Update(float dt, float waitTime) {
    time += dt;
    while (time >= waitTime) {
        time -= waitTime;
        NextAnimation();
    }
}

void Animation::NextAnimation() {
    if ( ++currentFrame >= frames.size()) {
        currentFrame = 0;
    }
}