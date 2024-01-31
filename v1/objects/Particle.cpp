#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Particle
{
private:
    sf::Vector2f posC;
    sf::Vector2f posL;
    sf::Vector2f accel;

public:
    Particle(float x, float y, float Vx, float Vy) : posC(x, y), posL(x - Vx, y - Vy), accel(0.0, 0.1) {}

    void update(float dt) 
    {
        
    }
};


