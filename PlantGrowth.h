#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

void avoGrowth(float& funds, string& fundsInString, Text& money, RenderWindow& win, RectangleShape& bar, RectangleShape&bar1, RectangleShape&bar2, RectangleShape&bar3, RectangleShape&bar4) {
    // lets say avo growth time is 25s
    float profit = 100;
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
        funds = funds+100;
        fundsInString = to_string(funds);
        money.setString(fundsInString);
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
        win.draw(money);
        win.display();
};

void beetGrowth(float& funds, string& fundsInString, Text& money, RenderWindow& win, RectangleShape& bar21, RectangleShape&bar22, RectangleShape&bar23, RectangleShape&bar24, RectangleShape&bar25) {
    // lets say avo growth time is 25s
    float profit = 50;
    int y = 1;
        this_thread::sleep_for(chrono::seconds(y));
        bar22.setFillColor(Color::Green);
        win.draw(bar22);
        win.display();
        this_thread::sleep_for(chrono::seconds(y));
        bar23.setFillColor(Color::Green);
        win.draw(bar23);
        win.display();
        this_thread::sleep_for(chrono::seconds(y));
        bar24.setFillColor(Color::Green);
        win.draw(bar24);
        win.display();
        this_thread::sleep_for(chrono::seconds(y));
        bar25.setFillColor(Color::Green);
        win.draw(bar25);

        win.display();
        this_thread::sleep_for(chrono::seconds(2));
        funds = funds+profit;
        fundsInString = to_string(funds);
        money.setString(fundsInString);
        bar21.setFillColor(Color::Black);
        bar22.setFillColor(Color::Black);
        bar23.setFillColor(Color::Black);
        bar24.setFillColor(Color::Black);
        bar25.setFillColor(Color::Black);
        win.draw(bar21);
        win.draw(bar22);
        win.draw(bar23);
        win.draw(bar24);
        win.draw(bar25);
        win.draw(money);
        win.display();
};