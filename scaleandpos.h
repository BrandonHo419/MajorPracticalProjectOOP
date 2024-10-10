#include "Requirements.h"
#include "createSprite.h"

#ifndef SCALEANDPOS_H
#define SCALEANDPOS_H

class scaleandpos : public createSprite{
    private:
    public:
    
    protected:
    
    public:

    void getsetScale() {

        
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
   avocado.setPosition(225, 150);
    beetroot.setPosition(225, 300);
    apples.setPosition(225, 450);
    bananas.setPosition(225, 600);
    cherries.setPosition(225, 750);

    
    // End positions
    }
    
    scaleandpos(){
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
    };
    ~scaleandpos(){};
};
#endif