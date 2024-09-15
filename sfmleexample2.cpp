#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

void move_left(CircleShape& a) {
    Vector2f pose = a.getPosition(); 
    pose.x = pose.x-1; 
    a.setPosition(pose);
}

void move_right(CircleShape& a) {
    Vector2f pose = a.getPosition(); 
    pose.x = pose.x+1; 
    a.setPosition(pose);
}

int main() {
    RenderWindow window(VideoMode(690, 690), "rawr");
    CircleShape shape(10.f);
    shape.setFillColor(Color::Blue);
    shape.setOrigin(Vector2f(5, 5)); // no idea what the vectors do rn but this sets the origin
    shape.setPosition(Vector2f(345, 345)); // this sets the POSITION (half way of 690, 690 is centre);
    //create infinite loop

    while (window.isOpen()) { //isOpen requires the () as it is a function

        Event event; // Creates an event

        while (window.pollEvent(event)) { //event is the parameter of class event and pollEvent calls that (can be renamed) 
            if(event.type == Event::Closed) { //allows for proper closing handling
                window.close();
            }
        }; 
        if(Keyboard::isKeyPressed(Keyboard::Left)) {
            move_left(shape); //passes shape parameter as its called via reference (i think)
        } // im getting this feeling will have quite a  bit of ctrl+c & ctrl+v (iywim lmao)
         if(Keyboard::isKeyPressed(Keyboard::Right)) {
            move_right(shape);
            // honestly watching the video around 15:30 did my head in with this part bc he changed smthn??
        };
        if(Keyboard::isKeyPressed(Keyboard::Up)) {
            Vector2f pose = shape.getPosition(); 
            pose.x = pose.y+1; // going up (on an y axis)
            shape.setPosition(pose);
        };
          if(Keyboard::isKeyPressed(Keyboard::Down)) {
            Vector2f pose = shape.getPosition(); 
            pose.x = pose.y-1; // going down (on an y axis)
            shape.setPosition(pose);
        }; //can one of u change it or create a lore accurate way (like the guy did in the vids)
        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;

};

//btw up and down doesnt work :(