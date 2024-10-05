#include "Requirements.h"
#ifndef LOADTEXTURES_H
#define LOADTEXTURES_H

class loadTextures {
    private:

    public:
    void loadRectangles() {
        
    }
    
    public:
    struct allTextures {
    Texture bd; 
    Texture minibd;
    Texture blueberry;
    Texture beet;
    Texture tomato;
    Texture carrots;
    Texture strawberries;
    Texture shopButton;
    Texture sign;
    Texture sign2;
    Texture sign3;
    Texture sign4;
    Texture sign5;
    Texture block;

    Texture back;
    Texture fore;
    Texture fertiliser;
    Texture house;
    Texture worker;
    Texture board1;
    Texture board2;
    Texture board3;
    Texture shopBoard;


    };
    
    protected:
    
    public:
    
    loadTextures(){};

    allTextures at;

    void assignTextures() {
    at.bd.loadFromFile("bd1.jpg");
    at.minibd.loadFromFile("minibd.jpg");
    at.blueberry.loadFromFile("avocado.png");
    at.beet.loadFromFile("beetroot.png");
    at.tomato.loadFromFile("apple.png");
    at.carrots.loadFromFile("banana.png");
    at.strawberries.loadFromFile("cherry.png");
    at.shopButton.loadFromFile("shop.png");
    at.sign.loadFromFile("sign.png");
    at.sign2.loadFromFile("sign.png");
    at.sign3.loadFromFile("sign.png");
    at.sign4.loadFromFile("sign.png");
    at.sign5.loadFromFile("sign.png");
    at.block.loadFromFile("scrollsandblocks.png");

    
    }

    const allTextures& getTextures() const {
        return at;
    }
    ~loadTextures(){};
};

#endif