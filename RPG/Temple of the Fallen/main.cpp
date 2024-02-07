#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "objects/applyPhysics.cpp"
#include "objects/headers/Circle.hpp"
#include "objects/headers/Rect.hpp"

int main () {
    sf::RenderWindow window(sf::VideoMode(800, 800), "SIM AREA", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    sf::Event ev;

    while(window.isOpen())
    {
        while (window.pollEvent(ev))
        {
            switch (ev.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (ev.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
                break;  

            default:
                break;
            }
        }

        window.clear(sf::Color::Black);



        window.display();
    }

    return 0;
}