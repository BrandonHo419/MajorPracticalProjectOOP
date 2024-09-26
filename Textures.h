#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#ifndef TEXTURES_H
#define TEXTURES_H

using namespace sf;

void setupTextures(Texture& bd, Texture&minibd, Texture& avo, Texture& beet, Texture& apple, Texture& banana, Texture& cherry, Texture& shopButton, Texture& sign, Texture& sign2, Texture& sign3, Texture& sign4, Texture& sign5) {
    bd.loadFromFile("bd1.jpg");
    minibd.loadFromFile("minibd.jpg");
    avo.loadFromFile("avocado.png");
    beet.loadFromFile("beetroot.png");
    apple.loadFromFile("apple.png");
    banana.loadFromFile("banana.png");
    cherry.loadFromFile("cherry.png");
    shopButton.loadFromFile("shop.png");
    sign.loadFromFile("sign.png");
    sign2.loadFromFile("sign.png");
    sign3.loadFromFile("sign.png");
    sign4.loadFromFile("sign.png");
    sign5.loadFromFile("sign.png");

    
    
};

void setScales(RenderWindow& win, Sprite& minibackdrop, Sprite&avocado, Sprite&beetroot, Sprite&apples, Sprite&bananas, Sprite&cherries, Sprite&shop, Sprite&signs, Sprite&signs2, Sprite&signs3, Sprite&signs4, Sprite&signs5) {
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

    FloatRect minibackdropbounds = minibackdrop.getLocalBounds(); // Get the local boudns with FloatRect which gets dimension (width and height)
    minibackdrop.setOrigin(minibackdropbounds.width/2, minibackdropbounds.height/2); // this ensures it calculates relative to the center
    minibackdrop.setPosition(win.getSize().x/2, win.getSize().y/2); // sets the position

    FloatRect shopPlace = shop.getLocalBounds();
    shop.setOrigin(shopPlace.width/2, shopPlace.height/2);
    shop.setPosition(win.getSize().x/2, win.getSize().y/2 +235);

    FloatRect signsPlacement = signs.getLocalBounds();
    signs.setOrigin(signsPlacement.width/2, signsPlacement.height/2);
    signs.setPosition(win.getSize().x/2 - 458, signsPlacement.height/2 - 50);
    

    FloatRect signsPlacement2 = signs2.getLocalBounds();
    signs2.setOrigin(signsPlacement2.width/2, signsPlacement2.height/2);
    signs2.setPosition(win.getSize().x/2 - 458, signsPlacement2.height/2 + 50);

    FloatRect signsPlacement3 = signs3.getLocalBounds();
    signs3.setOrigin(signsPlacement3.width/2, signsPlacement3.height/2);
    signs3.setPosition(win.getSize().x/2 - 458, signsPlacement3.height/2 + 150);

    FloatRect signsPlacement4 = signs4.getLocalBounds();
    signs4.setOrigin(signsPlacement4.width/2, signsPlacement4.height/2);
    signs4.setPosition(win.getSize().x/2 - 453, signsPlacement4.height/2 + 250);

    FloatRect signsPlacement5 = signs5.getLocalBounds();
    signs5.setOrigin(signsPlacement5.width/2, signsPlacement5.height/2);
    signs5.setPosition(win.getSize().x/2 - 458, signsPlacement5.height/2 + 357);
};

#endif