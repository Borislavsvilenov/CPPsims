#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "objects/Particle.cpp"

int main() 
{    
    std::vector<Particle> particles;
    float Brad = 300;
    sf::Vector2f Bctr(400.0, 400.0);
    sf::CircleShape bounds;
    bounds.setRadius(Brad);
    bounds.setFillColor(sf::Color::Black);
    bounds.setPosition(Bctr.x - Brad, Bctr.y - Brad);

    sf::RenderWindow window(sf::VideoMode(800, 800), "empty window", sf::Style::Titlebar | sf::Style::Close);
    sf::Event ev;

    sf::Clock clock;
    sf::Time deltaTime;

    particles.push_back(Particle(300.0, 300.0, 0.0, 0.01, 20.0));

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

        deltaTime = clock.restart();

        window.draw(bounds);

        //render HERE & game code
        for (int point = 0; point < particles.size(); point++)
        {   
            particles[point].bounds(Brad, Bctr);
            particles[point].update(deltaTime.asSeconds() / 200);
            particles[point].draw();
            window.draw(particles[point].sprite);
        }

        window.display(); //show new frame
    }

    return 0;
}