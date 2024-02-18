#include <iostream>
#include <vector>
#include <variant>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "objects/PhysicsCircle.hpp"
#include "objects/PhysicsRect.hpp"
#include "objects/Circle.hpp"
#include "objects/Rect.hpp"

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

    circles.push_back(Circle(100.0f, 100.0f, 10.0f));
    physicsC.push_back(PhysicsCircle(&circles[0], true, true, 1, 0.0f, 0.0f, 0.0f, 0.0f));

    rects.push_back(Rect(100.0f, 100.0f, 10.0f, 10.0f));
    physicsR.push_back(PhysicsRect(&rects[0], true, true, 1, 0.0f, 0.0f, 0.0f, 0.0f));

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

        //for(int i = 0; i < physicsC.size(); i++) { //here
        //    physicsC[i].update(dt.asSeconds(), physicsC, physicsR);
        //}

        window.display();
    }

    return 0;
}
