#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#ifndef TEXTURES_H
#define TEXTURES_H

using namespace sf;

void setupTextures(Texture& bd, Texture&minibd) {
    bd.loadFromFile("bd1.png");
    minibd.loadFromFile("minibd.png");
    
};

void setScales(Sprite& minibackdrop, Sprite&avocado, Sprite&beetroot, Sprite&apples, Sprite&bananas, Sprite&cherries, Sprite&shop, Sprite&signs, Sprite&signs2, Sprite&signs3, Sprite&signs4, Sprite&signs5) {
    minibackdrop.setScale(2.0, 1.5);
    avocado.setScale(0.14, 0.14);
    beetroot.setScale(0.14, 0.14);
    apples.setScale(0.14, 0.14);
    bananas.setScale(0.14, 0.14);
    cherries.setScale(0.2, 0.2);
    shop.setScale(0.4, 0.4);
    signs.setScale(0.4, 0.4);
    signs2.setScale(0.4, 0.4);
    signs3.setScale(0.4, 0.4);
    signs4.setScale(0.4, 0.4);
    signs5.setScale(0.4, 0.4);
};

#endif