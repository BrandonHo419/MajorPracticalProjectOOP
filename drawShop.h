#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#ifndef DRAWSHOP_H
#define DRAWSHOP_H

using namespace std;
using namespace sf;

void drawShop(RenderWindow& win) {
    Texture shopbd;
    shopbd.loadFromFile("beetroot.png");
    Sprite shopbg(shopbd);
    shopbg.setScale(1, 1);
    shopbg.setPosition(480, 200);
    win.draw(shopbg);
    win.display();

   
};

#endif