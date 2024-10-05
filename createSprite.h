#include "Requirements.h"
#include "loadTextures.h"
#ifndef CREATESPRITE_H
#define CREATESPRITE_H

class createSprite : public loadTextures {
public:
    sf::Sprite backdrop;
    sf::Sprite minibackdrop;
    sf::Sprite blueberries;
    sf::Sprite beetroot;
    sf::Sprite tomatos;
    sf::Sprite carrot;
    sf::Sprite strawberry;
    sf::Sprite shop;
    sf::Sprite signs;
    sf::Sprite signs2;
    sf::Sprite signs3;
    sf::Sprite signs4;
    sf::Sprite signs5;
    sf::Sprite blocks;

    // Shop Sprites
    sf::Sprite background;
    sf::Sprite foreground;
    sf::Sprite shopSign1;
    sf::Sprite shopSign2;
    sf::Sprite shopSign3;
    sf::Sprite shopSign;
    sf::Sprite fert;
    sf::Sprite greenhouse;
    sf::Sprite farmer;

    private:

    protected:

public:
    createSprite() {
        // Load textures
        assignTextures();

        backdrop.setTexture(getTextures().bd);
        minibackdrop.setTexture(getTextures().minibd);
        blueberries.setTexture(getTextures().blueberry);
        beetroot.setTexture(getTextures().beet);
        tomatos.setTexture(getTextures().tomato);
        carrot.setTexture(getTextures().carrots);
        strawberry.setTexture(getTextures().strawberries);
        shop.setTexture(getTextures().shopButton);
        signs.setTexture(getTextures().sign);
        signs2.setTexture(getTextures().sign2);
        signs3.setTexture(getTextures().sign3);
        signs4.setTexture(getTextures().sign4);
        signs5.setTexture(getTextures().sign5);
        blocks.setTexture(getTextures().block);


        background.setTexture(getTextures().back);
        foreground.setTexture(getTextures().fore);
        shopSign1.setTexture(getTextures().board1);
        shopSign2.setTexture(getTextures().board2);
        shopSign3.setTexture(getTextures().board3);
        shopSign.setTexture(getTextures().shopBoard);
        fert.setTexture(getTextures().fertiliser);
        greenhouse.setTexture(getTextures().house);
        farmer.setTexture(getTextures().worker);
    }

    ~createSprite() {}
};

#endif
