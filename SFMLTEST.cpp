
#include <SFML/Graphics.hpp>  // Correct SFML include

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Works!");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }

    return 0;
}
