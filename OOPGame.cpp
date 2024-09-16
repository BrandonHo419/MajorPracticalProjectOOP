#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Player.h"

using namespace std;
using namespace sf;

class OOPGame {
private:
    sf::RenderWindow win;
    Player player;

public:
    OOPGame(int size, string title) : win(sf::VideoMode(size, size), title), player(10, 50, 50, 100) {
        // No need to dynamically allocate, managed by value
    }

    void run() {
        while (win.isOpen()) {
            Event e;
            while (win.pollEvent(e)) {
                if (e.type == Event::Closed) {
                    win.close();
                }

                if (Keyboard::isKeyPressed(Keyboard::A)) {
                    player.move_left(6);
                } else if (Keyboard::isKeyPressed(Keyboard::D)) {
                    player.move_right(6);
                } else if (Keyboard::isKeyPressed(Keyboard::W)) {
                    player.move_up(6);
                } else if (Keyboard::isKeyPressed(Keyboard::S)) {
                    player.move_down(6);
                } else if (Keyboard::isKeyPressed(Keyboard::Space)) {
                    player.fire();
                }
            }

            win.clear();
            player.draw(&win);
            win.display();
        }
    }

    ~OOPGame() {}
};

int main() {
    OOPGame g(690, "Game");
    g.run();
    return 0;
}
