#include "Requirements.h"
#include <chrono>

class Animation {
    private:
    Texture texture; 
    static constexpr int nFrames = 9;
    static constexpr float holdTime = 0.1f ;
    IntRect frames [nFrames];
    int iFrame =0;
    float time = 0.0f;

    void Advance() {
        if(iFrame >= nFrames) {
            iFrame = 0;
        }
    }
    protected:

    public:
    Animation(int x, int y, int width, int height) {
        texture.loadFromFile("animPack.png");
        for(int i = 0; i < nFrames; i++) {
            frames[i] = {x + i * width, y, width, height};
        }
    }

    void applyToSprite(Sprite& s) const {
        s.setTexture( texture );
        s.setTextureRect( frames [iFrame]);
    }

    void update(float dt) {
        time+=dt;
        while (time >= holdTime) {
            time -= holdTime;
            Advance();
        }
    }   

};


class Character {
    private:
    Vector2f pos;
    Vector2f vel = {0.0f, 0.0f};
    Sprite sprite;
    Animation rightWalk;
    static constexpr float speed = 100.0f; // 3 pixels per sec

    protected:

    public:
    Character(const Vector2f& pos) : pos(pos), rightWalk(96, 96*5, 96, 96) {
        
        sprite.setTextureRect({0,0,100,150});
    }
    void draw(RenderTarget& rt) const {
        rt.draw(sprite);
    }
    void setDirection(const Vector2f& dir) {
        vel = dir*speed;
    };
    void update(float dt) {     
        pos += vel* dt;
        rightWalk.update(dt);
        rightWalk.applyToSprite(sprite);
        sprite.setPosition(pos);
    }
};

int main() {
    RenderWindow win(VideoMode (1280 , 720), "Anim test");
    Texture t;
    Character anim({100.0f, 100.0f});

    // time point for delta time measurement
    auto tp = chrono::steady_clock::now();
    
     while (win.isOpen())
    {
        sf::Event event;
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                win.close();
        }

        //get dt
    float dt;{
        const auto new_tp = chrono::steady_clock::now()
; dt = chrono::duration<float>(new_tp - tp).count();
tp = new_tp;
    }

    // handle input

    sf::Vector2f dir = {0.0f, 0.0f};
    if(Keyboard::isKeyPressed(Keyboard::Up)) {
        dir.y -=1.0f;
    };
    if(Keyboard::isKeyPressed(Keyboard::Down)) {
        dir.y +=1.0f;
    };
    if(Keyboard::isKeyPressed(Keyboard::Left)) {
        dir.x -=1.0f;
    };
    if(Keyboard::isKeyPressed(Keyboard::Right)) {
        dir.x +=1.0f;
    };
        anim.setDirection(dir);
        anim.update(dt);
        win.clear();
        anim.draw(win);
        win.display();
    }
    

    return 0;
};