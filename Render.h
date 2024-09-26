#include "Requirements.h"
#ifndef RENDER_H
#define RENDER_H



class Render {
    private:


    protected:
        

    public:
    Render(){}
    void renderDefault() {
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
    // End loading textures

    // Load Progress Bar Shapes

    RectangleShape bar(Vector2f(40, 40));
    bar.setFillColor(Color::Black);
    bar.setPosition(290, 104);

    RectangleShape bar1(Vector2f(40, 40));
    bar1.setFillColor(Color::Black);
    bar1.setPosition(331, 104);
    
    RectangleShape bar2(Vector2f(40, 40));
    bar2.setFillColor(Color::Black);
    bar2.setPosition(372, 104);

    RectangleShape bar3(Vector2f(40, 40));
    bar3.setFillColor(Color::Black);
    bar3.setPosition(413, 104);

    RectangleShape bar4(Vector2f(40, 40));
    bar4.setFillColor(Color::Black);
    bar4.setPosition(454, 104);

    RectangleShape bar21(Vector2f(40, 40));
    bar21.setFillColor(Color::Black);
    bar21.setPosition(290, 204);

    RectangleShape bar22(Vector2f(40, 40));
    bar22.setFillColor(Color::Black);
    bar22.setPosition(331, 204);
    
    RectangleShape bar23(Vector2f(40, 40));
    bar23.setFillColor(Color::Black);
    bar23.setPosition(372, 204);

    RectangleShape bar24(Vector2f(40, 40));
    bar24.setFillColor(Color::Black);
    bar24.setPosition(413, 204);

    RectangleShape bar25(Vector2f(40, 40));
    bar25.setFillColor(Color::Black);
    bar25.setPosition(454, 204);

    RectangleShape bar31(Vector2f(40, 40));
    bar31.setFillColor(Color::Black);
    bar31.setPosition(290, 304);

    RectangleShape bar32(Vector2f(40, 40));
    bar32.setFillColor(Color::Black);
    bar32.setPosition(331, 304);
    
    RectangleShape bar33(Vector2f(40, 40));
    bar33.setFillColor(Color::Black);
    bar33.setPosition(372, 304);

    RectangleShape bar34(Vector2f(40, 40));
    bar34.setFillColor(Color::Black);
    bar34.setPosition(413, 304);

    RectangleShape bar35(Vector2f(40, 40));
    bar35.setFillColor(Color::Black);
    bar35.setPosition(454, 304);

    RectangleShape bar41(Vector2f(40, 40));
    bar41.setFillColor(Color::Black);
    bar41.setPosition(290, 404);

    RectangleShape bar42(Vector2f(40, 40));
    bar42.setFillColor(Color::Black);
    bar42.setPosition(331, 404);
    
    RectangleShape bar43(Vector2f(40, 40));
    bar43.setFillColor(Color::Black);
    bar43.setPosition(372, 404);

    RectangleShape bar44(Vector2f(40, 40));
    bar44.setFillColor(Color::Black);
    bar44.setPosition(413, 404);

    RectangleShape bar45(Vector2f(40, 40));
    bar45.setFillColor(Color::Black);
    bar45.setPosition(454, 404);

    RectangleShape bar51(Vector2f(40, 40));
    bar51.setFillColor(Color::Black);
    bar51.setPosition(290, 511);

    RectangleShape bar52(Vector2f(40, 40));
    bar52.setFillColor(Color::Black);
    bar52.setPosition(331, 511);
    
    RectangleShape bar53(Vector2f(40, 40));
    bar53.setFillColor(Color::Black);
    bar53.setPosition(372, 511);

    RectangleShape bar54(Vector2f(40, 40));
    bar54.setFillColor(Color::Black);
    bar54.setPosition(413, 511);

    RectangleShape bar55(Vector2f(40, 40));
    bar55.setFillColor(Color::Black);
    bar55.setPosition(454, 511);


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

    
    }

    ~Render(){}
};
#endif