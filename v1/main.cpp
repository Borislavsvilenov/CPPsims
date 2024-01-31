#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main() 
{

    sf::RenderWindow window(sf::VideoMode(800, 800), "empty window", sf::Style::Titlebar | sf::Style::Close);
    sf::Event ev;

    sf::CircleShape point;
    point.setRadius(10);
    point.setFillColor(sf::Color::White);
    point.setPosition(200, 200);

    while (window.isOpen()) 
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

        //renderer
        window.clear(); //clear frame

        //render HERE
        window.draw(point);

        window.display(); //show new frame
    }

    return 0;
}