#include <iostream>
#include <vector>
#include <variant>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "objects/headers/PhysicsCircle.hpp"
#include "objects/headers/PhysicsRect.hpp"
#include "objects/headers/Circle.hpp"
#include "objects/headers/Rect.hpp"

int main () {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Temple of the fallen", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    sf::Event ev;

    sf::Clock clock;
    sf::Time dt;

    std::vector<Rect> rects;
    std::vector<Circle> circles;
    std::vector<PhysicsRect> physicsR;
    std::vector<PhysicsCircle> physicsC;

    Circle s1 = Circle(100.0f, 100.0f, 10.0f);
    circles.push_back(s1);
    PhysicsCircle r1 = PhysicsCircle(s1, true, true, 1, 0.0f, 0.0f, 0.0f, 0.0f);
    physicsC.push_back(r1);

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

        dt = clock.restart();

        for(int i = 0; i < physicsC.size(); i++) {
            physicsC[i].update(dt.asMilliseconds(), physicsC, physicsR);
        }

        window.display();
    }

    return 0;
}