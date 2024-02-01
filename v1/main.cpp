#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "objects/Particle.cpp"

float deltaTime;

int main() 
{
    deltaTime = 0.1;

    sf::RenderWindow window(sf::VideoMode(800, 800), "empty window", sf::Style::Titlebar | sf::Style::Close);
    sf::Event ev;

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

        //render HERE & game code
        for (int point = 0; point < particles.size(); point++)
        {
            particles[point].draw();
            window.draw(particles[point]);
        }

        window.display(); //show new frame
    }

    return 0;
}