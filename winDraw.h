#include "Requirements.h"
#include "createSprite.h"
#include "loadRect.h"
#ifndef WINDRAW_H
#define WINDRAW_H

class winDraw: public createSprite, public loadRect{
    private:
    createSprite cs;
    loadRect lr;
    protected:
    RenderWindow& win;
     
    public:
    const void setPos() {

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

    FloatRect minibackdropbounds = minibackdrop.getLocalBounds(); // Get the local boudns with FloatRect which gets dimension (width and height)
    minibackdrop.setOrigin(minibackdropbounds.width/2, minibackdropbounds.height/2); // this ensures it calculates relative to the center
    minibackdrop.setPosition(win.getSize().x/2, win.getSize().y/2); // sets the position

    FloatRect shopPlace = cs.shop.getLocalBounds();
    cs.shop.setOrigin(shopPlace.width/2, shopPlace.height/2);
    cs.shop.setPosition(win.getSize().x/2, win.getSize().y/2 +235);

    FloatRect signsPlacement = cs.signs.getLocalBounds();
    cs.signs.setOrigin(signsPlacement.width/2, signsPlacement.height/2);
    cs.signs.setPosition(win.getSize().x/2 - 458, signsPlacement.height/2 - 50);
    

    FloatRect signsPlacement2 = cs.signs2.getLocalBounds();
    cs.signs2.setOrigin(signsPlacement2.width/2, signsPlacement2.height/2);
    cs.signs2.setPosition(win.getSize().x/2 - 458, signsPlacement2.height/2 + 50);

    FloatRect signsPlacement3 = cs.signs3.getLocalBounds();
    cs.signs3.setOrigin(signsPlacement3.width/2, signsPlacement3.height/2);
    cs.signs3.setPosition(win.getSize().x/2 - 458, signsPlacement3.height/2 + 150);

    FloatRect signsPlacement4 = cs.signs4.getLocalBounds();
    cs.signs4.setOrigin(signsPlacement4.width/2, signsPlacement4.height/2);
    cs.signs4.setPosition(win.getSize().x/2 - 453, signsPlacement4.height/2 + 250);

    FloatRect signsPlacement5 = cs.signs5.getLocalBounds();
    cs.signs5.setOrigin(signsPlacement5.width/2, signsPlacement5.height/2);
    cs.signs5.setPosition(win.getSize().x/2 - 458, signsPlacement5.height/2 + 357);

    cs.blocks.setTextureRect(IntRect(0, 32*2, 96, 32));

    // New position
    cs.blueberries.setPosition(150, 100);
    cs.beetroot.setPosition(150, 200);
    cs.tomatos.setPosition(150, 300);
    cs.carrot.setPosition(150, 400);
    cs.strawberry.setPosition(150, 500);
    }


    public:
    const void setScale() {
    setPos();
    cs.minibackdrop.setScale(2.0, 1.5);
    cs.strawberry.setScale(0.14, 0.14);
    cs.beetroot.setScale(0.14, 0.14);
    cs.carrot.setScale(0.14, 0.14);
    cs.blueberries.setScale(0.14, 0.14);
    cs.tomatos.setScale(0.2, 0.2);
    cs.shop.setScale(0.4, 0.4);
    cs.signs.setScale(0.4, 0.4);
    cs.signs2.setScale(0.4, 0.4);
    cs.signs3.setScale(0.4, 0.4);
    cs.signs4.setScale(0.4, 0.4);
    cs.signs5.setScale(0.4, 0.4);
    //setScales(win, cs.minibackdrop, cs.blueberries, cs.beetroot, cs.tomatos, cs.carrot, cs.strawberry, cs.shop, cs.signs, cs.signs2, cs.signs3, cs.signs4, cs.signs5); // also sets positions of these
    
    // shop scales
    cs.foreground.setScale(2.0, 1.5);
    cs.fert.setScale(0.2f, 0.2f);
    cs.greenhouse.setScale(0.35f, 0.35f);
    cs.farmer.setScale(0.045, 0.045);
    cs.shopSign.setScale(0.4, 0.4);
    cs.shopSign1.setScale(0.4, 0.4);
    cs.shopSign2.setScale(0.4, 0.4);
    cs.shopSign3.setScale(0.4, 0.4);
    //End scales

    };


    winDraw(RenderWindow& window): win(window){};
    
    const void drawStart() {
        setPos();
        setScale();
         // draw the windows
        win.clear();
        win.draw(cs.backdrop);
        win.draw(cs.minibackdrop);
        // 
        win.draw(cs.signs);
        win.draw(cs.signs2);
        win.draw(cs.signs3);
        win.draw(cs.signs4);
        win.draw(cs.signs5);
        //
        win.draw(lr.bar);
        win.draw(lr.bar1);
        win.draw(lr.bar2);
        win.draw(lr.bar3);
        win.draw(lr.bar4);
        win.draw(lr.bar21);
        win.draw(lr.bar22);
        win.draw(lr.bar23);
        win.draw(lr.bar24);
        win.draw(lr.bar25);
        win.draw(lr.bar31);
        win.draw(lr.bar32);
        win.draw(lr.bar33);
        win.draw(lr.bar34);
        win.draw(lr.bar35);
        win.draw(lr.bar41);
        win.draw(lr.bar42);
        win.draw(lr.bar43);
        win.draw(lr.bar44);
        win.draw(lr.bar45);
        win.draw(lr.bar51);
        win.draw(lr.bar52);
        win.draw(lr.bar53);
        win.draw(lr.bar54);
        win.draw(lr.bar55);
        //
        win.draw(cs.blueberries);
        win.draw(cs.beetroot);
        win.draw(cs.tomatos);
        win.draw(cs.carrot);
        win.draw(cs.strawberry);
        //
        win.draw(cs.shop);
       
        win.draw(cs.blocks);
        //
        win.display();
        cout << "test" << endl;
        
    }
    
    
};

#endif