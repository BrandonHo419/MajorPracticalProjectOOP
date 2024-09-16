
#include <SFML/Graphics.hpp>
#include "Bullet.h"

#ifndef PLAYER_H
#define PLAYER_H

using namespace sf;

class Player {
private:
    CircleShape body;
    int mag_size;
    Bullet* mag;

public:
    Player(float r, int x, int y, int a_mag_size) : body(r), mag_size(a_mag_size) {
        body.setPosition(x, y);
        body.setFillColor(Color::Green);
        body.setOrigin(r / 2, r / 2);  // sets it to center
        mag = new Bullet[mag_size];  // Allocate bullet array dynamically
    }

    void draw(RenderWindow* win) {
        win->draw(body);
        for (int i = 0; i < mag_size; i++) {
            if (mag[i].isFired()) {
                mag[i].move();
                mag[i].draw(win);
            }
        }
    }

    void move_right(int speed) {
        body.move(speed, 0);  // move right
    }

    void move_left(int speed) {
        body.move(-speed, 0);  // move left
    }

    void move_up(int speed) {
        body.move(0, -speed);  // move up
    }

    void move_down(int speed) {
        body.move(0, speed);  // move down
    }

    void fire() {
        for (int i = 0; i < mag_size; i++) {
            if (!mag[i].isFired()) {
                mag[i].use(body.getPosition());
                break;
            }
        }
    }

    ~Player() {
        delete[] mag;  // Free the dynamically allocated bullet array
    }
};

#endif

