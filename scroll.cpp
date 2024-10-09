#include <SFML/Graphics.hpp>
using namespace sf;

class scroll{
public:
    // Constructor to set scroll values (like scale, position etc.) and add the frames to the vector
    scroll(const Vector2f& pos, float switchAnimation) : pos(pos), switchAnimationTime(switchAnimation), totalTime(0), 
    currentFrame(0) {
        texture.loadFromFile("scrollsandblocks.png");
        frames.push_back(IntRect(224, 150, 0, 0)); // Initial frame shows none of scroll
        frames.push_back(IntRect(224, 150, 95, 40));
        frames.push_back(IntRect(224, 225, 95, 94));
        sprite.setOrigin(frames[1].width / 2.f, frames[1].height / 2.f);
        sprite.setTexture(texture);
        sprite.setTextureRect(frames[0]);
        sprite.setScale(9.5,6);
        sprite.setPosition(pos);

    }
    
    // Function to update the animation
    void update(float deltaTime) {
        totalTime+= deltaTime; // Add time elapsed to total time

        // Check if the total time is more than the time each frame is to be open for and if the animation is in open state
        if (totalTime >= switchAnimationTime && open == true) {
            totalTime -= switchAnimationTime; // Reset timer
            // If the current frame is not the last it updates the scroll animation frame to the next one in the sequence
            if (currentFrame < frames.size() - 1) {
                currentFrame++;
                sprite.setTextureRect(frames[currentFrame]);
            
                // Check if it's the last frame, if so set last frame to true
                if (open && currentFrame == frames.size() - 1) {
                    lastFrame = true;
                } else {
                    lastFrame = false; // Reset last frame flag if it's not the last frame
                }   
            }
        }

        // If the time elapsed is more than time on each frame and animation is in the clsoe state, do the following:
        if (totalTime >= switchAnimationTime && close == true) {
            totalTime -= switchAnimationTime; // Reset timer
            // If not the first frame move the frame to the previous one in sequence
            if (currentFrame > 0) { 
                currentFrame--;
                sprite.setTextureRect(frames[currentFrame]);
            }
        }
    }

    // Draws animation
    void draw(RenderTarget& rt) const {
        rt.draw(sprite);
    }

    // Set aniamtion states
    void openScroll() {
        open = true;
        close = false;
    }

    // Set aniamtion states
    void closeScroll() {
        lastFrame = false;
        close = true;
        open = false;
    }

    bool isOpen() {
        return open;
    }

    bool getLastFrame() {
        return lastFrame;
    }

private:
    Vector2f pos; // Position of scroll
    Texture texture;
    Sprite sprite;
    bool open = false;
    bool close = false;
    std::vector<IntRect> frames; // Vector to store frames
    float switchAnimationTime; // Time on each frame
    float totalTime; // Time elapsed after last frame switch
    int currentFrame;
    bool lastFrame = false;
};
