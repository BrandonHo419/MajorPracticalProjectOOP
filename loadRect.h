#include "Requirements.h"
#ifndef LOADRECT_H
#define LOADRECT_H

class loadRect {
    public:
    RectangleShape bar;
    RectangleShape bar1;
    RectangleShape bar2;
    RectangleShape bar3;
    RectangleShape bar4;
    RectangleShape bar21;
    RectangleShape bar22;
    RectangleShape bar23;
    RectangleShape bar24;
    RectangleShape bar25;
    RectangleShape bar31;
    RectangleShape bar32;
    RectangleShape bar33;
    RectangleShape bar34;
    RectangleShape bar35;
    RectangleShape bar41;
    RectangleShape bar42;
    RectangleShape bar43;
    RectangleShape bar44;
    RectangleShape bar45;
    RectangleShape bar51;
    RectangleShape bar52;
    RectangleShape bar53;
    RectangleShape bar54;
    RectangleShape bar55;

    RectangleShape DialogBox;

    private:

    
    protected:
    
    public:
    loadRect(){
        // Load Progress Bar Shapes

    bar.setSize(Vector2f(40, 40));
    bar.setFillColor(Color::Black);
    bar.setPosition(290, 104);

     bar1.setSize(Vector2f(40, 40));
    bar1.setFillColor(Color::Black);
    bar1.setPosition(331, 104);
    
     bar2.setSize(Vector2f(40, 40));
    bar2.setFillColor(Color::Black);
    bar2.setPosition(372, 104);

     bar3.setSize(Vector2f(40, 40));
    bar3.setFillColor(Color::Black);
    bar3.setPosition(413, 104);

     bar4.setSize(Vector2f(40, 40));
    bar4.setFillColor(Color::Black);
    bar4.setPosition(454, 104);

     bar21.setSize(Vector2f(40, 40));
    bar21.setFillColor(Color::Black);
    bar21.setPosition(290, 204);

     bar22.setSize(Vector2f(40, 40));
    bar22.setFillColor(Color::Black);
    bar22.setPosition(331, 204);
    
     bar23.setSize(Vector2f(40, 40));
    bar23.setFillColor(Color::Black);
    bar23.setPosition(372, 204);

     bar24.setSize(Vector2f(40, 40));
    bar24.setFillColor(Color::Black);
    bar24.setPosition(413, 204);

     bar25.setSize(Vector2f(40, 40));
    bar25.setFillColor(Color::Black);
    bar25.setPosition(454, 204);

     bar31.setSize(Vector2f(40, 40));
    bar31.setFillColor(Color::Black);
    bar31.setPosition(290, 304);

     bar32.setSize(Vector2f(40, 40));
    bar32.setFillColor(Color::Black);
    bar32.setPosition(331, 304);
    
     bar33.setSize(Vector2f(40, 40));
    bar33.setFillColor(Color::Black);
    bar33.setPosition(372, 304);

     bar34.setSize(Vector2f(40, 40));
    bar34.setFillColor(Color::Black);
    bar34.setPosition(413, 304);

     bar35.setSize(Vector2f(40, 40));
    bar35.setFillColor(Color::Black);
    bar35.setPosition(454, 304);

     bar41.setSize(Vector2f(40, 40));
    bar41.setFillColor(Color::Black);
    bar41.setPosition(290, 404);

     bar42.setSize(Vector2f(40, 40));
    bar42.setFillColor(Color::Black);
    bar42.setPosition(331, 404);
    
     bar43.setSize(Vector2f(40, 40));
    bar43.setFillColor(Color::Black);
    bar43.setPosition(372, 404);

     bar44.setSize(Vector2f(40, 40));
    bar44.setFillColor(Color::Black);
    bar44.setPosition(413, 404);

     bar45.setSize(Vector2f(40, 40));
    bar45.setFillColor(Color::Black);
    bar45.setPosition(454, 404);

     bar51.setSize(Vector2f(40, 40));
    bar51.setFillColor(Color::Black);
    bar51.setPosition(290, 511);

     bar52.setSize(Vector2f(40, 40));
    bar52.setFillColor(Color::Black);
    bar52.setPosition(331, 511);
    
     bar53.setSize(Vector2f(40, 40));
    bar53.setFillColor(Color::Black);
    bar53.setPosition(372, 511);

     bar54.setSize(Vector2f(40, 40));
    bar54.setFillColor(Color::Black);
    bar54.setPosition(413, 511);

     bar55.setSize(Vector2f(40, 40));
    bar55.setFillColor(Color::Black);
    bar55.setPosition(454, 511);

    DialogBox.setSize(Vector2f(400, 150));
    DialogBox.setFillColor(Color::Blue);
    DialogBox.setPosition(280,290);

    };

 
};

#endif