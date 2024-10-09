#include "Requirements.h"
#include "renderText.h"
#ifndef CREATESPRITE_H
#define CREATESPRITE_H

class createSprite: public renderText{
public:
    // end load from file

    // Create sprites for the GFX
    Sprite backdrop; 
    Sprite minibackdrop;
    Sprite avocado;
    Sprite beetroot;
    Sprite apples;
    Sprite bananas;
    Sprite cherries;
    Sprite shop;
    Sprite signs;
    Sprite signs2;
    Sprite signs3;
    Sprite signs4;
    Sprite signs5;
    Sprite blocks;

    // Shop Sprites
    Sprite background;
    Sprite foreground;
    Sprite shopSign1;
    Sprite shopSign2;
    Sprite shopSign3;
    Sprite shopSign;
    Sprite fert;
    Sprite greenhouse;
    Sprite farmer;

    // End sprites

private:

protected:

public:
    createSprite() {
        
    }

    void createandset() {
        // Create sprites for the GFX
    Sprite backdrop(bd); // creates a sprite so it stays in systme memory
    Sprite minibackdrop(minibd);
    Sprite avocado(avo);
    Sprite beetroot(beet);
    Sprite apples(apple);
    Sprite bananas(banana);
    Sprite cherries(cherry);
    Sprite shop(shopButton);
    Sprite signs(sign);
    Sprite signs2(sign2);
    Sprite signs3(sign3);
    Sprite signs4(sign4);
    Sprite signs5(sign5);
    Sprite blocks;

// Shop Sprites
    Sprite background(back);
    Sprite foreground(fore);
    Sprite shopSign1(board1);
    Sprite shopSign2(board2);
    Sprite shopSign3(board3);
    Sprite shopSign(shopBoard);
    Sprite fert(fertiliser);
    Sprite greenhouse(house);
    Sprite farmer(worker);

    // further

        // Set Scales
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
    blocks.setScale(1, 1);

    
    
    // shop scales
    foreground.setScale(2.0, 1.5);
    fert.setScale(0.2f, 0.2f);
    greenhouse.setScale(0.35f, 0.35f);
    farmer.setScale(0.045, 0.045);
    shopSign.setScale(0.4, 0.4);
    shopSign1.setScale(0.4, 0.4);
    shopSign2.setScale(0.4, 0.4);
    shopSign3.setScale(0.4, 0.4);
    //End scales

    

    // New position
    avocado.setPosition(150, 100);
    beetroot.setPosition(150, 200);
    apples.setPosition(150, 300);
    bananas.setPosition(150, 400);
    cherries.setPosition(150, 500);
    
    // End positions
    }

    ~createSprite() {}
};

#endif
