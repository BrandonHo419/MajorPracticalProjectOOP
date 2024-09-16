#include <SFML/Graphics.hpp>

#ifndef BULLET_H
#define BULLET_H

using namespace sf;

class Bullet {
private:
    sf::RectangleShape body;
    bool fired;

public:
    Bullet() : fired(false), body(Vector2f(10, 5)) {
        body.setFillColor(Color::Red);
        body.setPosition(-1, -1);  // start off-screen
    }

    void draw(sf::RenderWindow* win) {
        win->draw(body);
    }

    void setPosition(Vector2f position) {
        body.setPosition(position);
    }

    void move() {
        body.move(0.5, 0);  // move to the right
    }

    bool isFired() const {
        return fired;
    }

    void use(Vector2f position) {
        body.setPosition(position);
        fired = true;
    }
};

#endif
