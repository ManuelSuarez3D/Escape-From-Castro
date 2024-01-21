////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Assignment:      
//  Instructor:     David Burchill
//  Year / Term:    Fall 2023
//  File name:      Source.cpp
// 
//  Student name:   George P. Burdell
//  Student email:  gpburdell@hotmail.com
// 
//     I certify that this work is my work only, any work copied from Stack Overflow, textbooks, 
//     or elsewhere is properly cited. 
// 
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////

//  BUG 
//  list any and all bugs in your code 
//  1. I didnt get abc to work because of xyz, I tried ijk...
//

 
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "SFML works!");
    sf::CircleShape shape(20.f);
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(20.f, 20.f);
    shape.setPosition(1024 / 2.f, 768 / 2.f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}