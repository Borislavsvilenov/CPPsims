#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "objects/Particle.cpp"

float deltaTime;


int main() 
{
    deltaTime = 0.01;
    
    std::vector<Particle> particles;


    sf::RenderWindow window(sf::VideoMode(800, 800), "empty window", sf::Style::Titlebar | sf::Style::Close);
    sf::Event ev;

    particles.push_back(Particle(100.0, 100.0, 0.1, 0.0, 20.0));

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
        window.clear(sf::Color::White); //clear frame

        //render HERE & game code
        for (int point = 0; point < particles.size(); point++)
        {
            particles[point].update(deltaTime);
            particles[point].draw();
            window.draw(particles[point].sprite);
        }

        window.display(); //show new frame
    }

    return 0;
}