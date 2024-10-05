#include <SFML/Graphics.hpp>
using namespace sf;

class scroll{
public:
    bool open = false;
    bool close = false;
    scroll(const Vector2f& pos, float switchAnimation) : pos(pos), switchAnimationTime(switchAnimation), totalTime(0), 
    currentFrame(0) {
        texture.loadFromFile("scrollsandblocks.png");
        frames.push_back(IntRect(224, 150, 95, 40));
        //frames.push_back(IntRect(224, 190, 95, 33));
        frames.push_back(IntRect(224, 225, 95, 94));
        sprite.setOrigin(frames[0].width / 2.f, frames[0].height / 2.f);
        sprite.setTexture(texture);
        sprite.setTextureRect(frames[0]);
        sprite.setScale(9.5,6);
        sprite.setPosition(pos);

    }
    
    void update(float deltaTime) {
        totalTime+= deltaTime;

        if (totalTime >= switchAnimationTime && open == true) {
            totalTime -= switchAnimationTime;
            if (currentFrame < frames.size() - 1) {
                currentFrame++;
                sprite.setTextureRect(frames[currentFrame]);
            }
            
        }

        if (totalTime >= switchAnimationTime && close == true) {
            totalTime -= switchAnimationTime;
            if (currentFrame > 0) {
                currentFrame--;
                sprite.setTextureRect(frames[currentFrame]);
            }
        }
    }
    void draw(RenderTarget& rt) const {
        rt.draw(sprite);
    }

    void openScroll() {
        open = true;
        close = false;
    }

    void closeScroll() {
        close = true;
        open = false;
    }

private:
    Vector2f pos;
    Texture texture;
    Sprite sprite;
    std::vector<IntRect> frames;
    float switchAnimationTime;
    float totalTime;
    int currentFrame;
};
