#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "objects/Particle.cpp"


int main()
{   
    std::vector<Particle> particles;

    sf::RenderWindow window(sf::VideoMode(800, 800), "SIM AREA", sf::Style::Titlebar | sf::Style::Close);
    sf::Event ev;

    sf::Clock clock;
    sf::Time deltaTime;

    particles.push_back(Particle(400.0f, 400.0f, 0.0f, -100.0f, 20));

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

        deltaTime = clock.restart();
        //Render Here
        for(int point = 0; point < particles.size(); point++)
        {
            particles[point].bounds(800.0, 800.0);
            particles[point].draw();
            particles[point].update(deltaTime.asSeconds());
            window.draw(particles[point].sprite);
        }

        window.display();
    }


    return 0;
}