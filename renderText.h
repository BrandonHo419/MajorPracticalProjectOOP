#include "Requirements.h"
#ifndef RENDERTEXT_H
#define RENDERTEXT_H

class renderText {
    private:

    protected:
    
    public:
    // Load textures
   
    Texture bd; // create something for backdrop
    Texture minibd;
    Texture avo;
    Texture beet;
    Texture apple;
    Texture banana;
    Texture cherry;
    Texture shopButton;
    Texture sign;
    Texture sign2;
    Texture sign3;
    Texture sign4;
    Texture sign5;
    

    Texture back;
    Texture fore;
    Texture fertiliser;
    Texture house;
    Texture worker;
    Texture board1;
    Texture board2;
    Texture board3;
    Texture shopBoard;
    Texture block;
    // End loading textures

    public:


    renderText(){
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
    block.loadFromFile("scrollsandblocks.png");
    };

    ~renderText(){}
};

#endif