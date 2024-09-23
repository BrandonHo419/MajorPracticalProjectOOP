#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

void avoGrowth(RenderWindow& win, RectangleShape& bar, RectangleShape&bar1, RectangleShape&bar2, RectangleShape&bar3, RectangleShape&bar4) {
    // lets say avo growth time is 25s
    int y = 1;
        this_thread::sleep_for(chrono::seconds(y));
        bar1.setFillColor(Color::Green);
        win.draw(bar1);
        win.display();
        this_thread::sleep_for(chrono::seconds(y));
        bar2.setFillColor(Color::Green);
        win.draw(bar2);
        win.display();
        this_thread::sleep_for(chrono::seconds(y));
        bar3.setFillColor(Color::Green);
        win.draw(bar3);
        win.display();
        this_thread::sleep_for(chrono::seconds(y));
        bar4.setFillColor(Color::Green);
        win.draw(bar4);

        win.display();
        this_thread::sleep_for(chrono::seconds(2));
        bar.setFillColor(Color::Black);
        bar1.setFillColor(Color::Black);
        bar2.setFillColor(Color::Black);
        bar3.setFillColor(Color::Black);
        bar4.setFillColor(Color::Black);
        win.draw(bar);
        win.draw(bar1);
        win.draw(bar2);
        win.draw(bar3);
        win.draw(bar4);
        win.display();
};