#include "Requirements.h"
#ifndef LOADRECT_H
#define LOADRECT_H

class loadRect {
    public:
    
    RectangleShape DialogBox;

    private:

    
    protected:
    
    public:
    loadRect(){
        // Load Progress Bar Shapes

   
    DialogBox.setSize(Vector2f(400, 150));
    DialogBox.setFillColor(Color::Blue);
    DialogBox.setPosition(280,290);

    };

 
};

#endif