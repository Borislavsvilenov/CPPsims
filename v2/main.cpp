#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


int main()
{   
    sf::RenderWindow window(sf::VideoMode(800, 800), "empty window", sf::Style::Titlebar | sf::Style::Close);
    sf::Event ev;

    sf::Clock clock;
    sf::Time deltaTime;

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
        

        window.display();
    }


    return 0;
}