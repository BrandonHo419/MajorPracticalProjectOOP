#include "createSprite.h"
#include "winDraw.h"

#ifndef SETPOSITION_H
#define SETPOSITION_H

class setPosition: public createSprite{
    private:

    protected:

    
    // End positions
    public:
    setPosition(){}


    const void setPos() const {
        createSprite cs;

    FloatRect minibackdropbounds2 = cs.foreground.getLocalBounds();
    cs.foreground.setOrigin(minibackdropbounds2.width / 2, minibackdropbounds2.height / 2);
    cs.foreground.setPosition(win.getSize().x / 2, win.getSize().y / 2);

    FloatRect fertDimensions = cs.fert.getLocalBounds();
    cs.fert.setOrigin(fertDimensions.width / 2, fertDimensions.height / 2);
    cs.fert.setPosition(win.getSize().x/2 -458, win.getSize().y/2 - 20);

    FloatRect greenhouseDimensions = cs.greenhouse.getLocalBounds();
    cs.greenhouse.setOrigin(greenhouseDimensions.width / 2, greenhouseDimensions.height / 2);
    cs.greenhouse.setPosition(win.getSize().x/2, win.getSize().y/2 - 20);

    FloatRect workerDimensions = cs.farmer.getLocalBounds();
    cs.farmer.setOrigin(workerDimensions.width / 2, workerDimensions.height / 2);
    cs.farmer.setPosition(win.getSize().x/2 + 458, win.getSize().y/2 - 20);

    FloatRect signDimensions = cs.shopSign1.getLocalBounds();
    cs.shopSign1.setOrigin(signDimensions.width / 2, signDimensions.height / 2);
    cs.shopSign1.setPosition(win.getSize().x/2 -458, win.getSize().y/2 - 20);

    FloatRect signDimensions2 = cs.shopSign2.getLocalBounds();
    cs.shopSign2.setOrigin(signDimensions.width / 2, signDimensions.height / 2);
    cs.shopSign2.setPosition(win.getSize().x/2, win.getSize().y/2 - 20);

    FloatRect signDimensions3 = cs.shopSign3.getLocalBounds();
    cs.shopSign3.setOrigin(signDimensions3.width / 2, signDimensions3.height / 2);
    cs.shopSign3.setPosition(win.getSize().x/2 + 458, win.getSize().y/2 - 20);

    FloatRect shopDimensions2 = cs.shopSign.getLocalBounds();
    cs.shopSign.setOrigin(shopDimensions2.width / 2, shopDimensions2.height / 2);
    cs.shopSign.setPosition(win.getSize().x/2, win.getSize().y/2 - 200);

    cs.blocks.setTextureRect(IntRect(0, 32*2, 96, 32));

    // New position
    cs.blueberries.setPosition(150, 100);
    cs.beetroot.setPosition(150, 200);
    cs.tomatos.setPosition(150, 300);
    cs.carrot.setPosition(150, 400);
    cs.strawberry.setPosition(150, 500);
    }

};

#endif