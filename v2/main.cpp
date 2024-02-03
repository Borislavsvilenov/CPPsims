#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "objects/Particle.cpp"

int main()
{   
    std::vector<Particle> particles;

    sf::RenderWindow window(sf::VideoMode(400, 800), "SIM AREA", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    sf::Event ev;

    sf::Clock clock;
    sf::Time deltaTime;

    int frameCounter = 0;
    int substeps = 1;
    float dt = 0.01;

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
            //particles[point].update(deltaTime.asSeconds() / 1);
            particles[point].update(dt);
            particles[point].checkCollision(particles, substeps);
            particles[point].bounds(400.0f, 800.0f);
            particles[point].draw();
            window.draw(particles[point].sprite);
        }
        if(frameCounter % 2 == 0)
        {
            particles.push_back(Particle(100.0f, 200.0f, 99.2f, 200.0f, 5));
        }

        frameCounter++;

        window.display();
    }


    return 0;
}