#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main() {
    

    RenderWindow win(VideoMode(800, 600), "Basic Shapes"); // no equal sign
    CircleShape player(50); // creates circle with radius of 50 pixel
    player.setFillColor(Color::Blue);
    player.setPosition(100, 100);

    RectangleShape obstacle(Vector2f(120, 60)); // 120 x 60 pixel (Vector 2f defines a mathematical vector using x and y )
    obstacle.setFillColor(Color::Red);
    obstacle.setPosition(400,300);


    

    while(win.isOpen()) {
        Event e;
        while(win.pollEvent(e)) {
            if(e.type == Event::Closed) {
                win.close();
            }
        }

    win.clear();
    win.draw(player);
    win.draw(obstacle);
    win.display();

   
    }
    return 0;
}