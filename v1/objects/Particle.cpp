#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Particle
{
private:

public:
    sf::Vector2f posC;
    sf::Vector2f posL;
    sf::Vector2f accel;
    sf::Vector2f vel;
    sf::CircleShape sprite;

    Particle(float x, float y, float Vx, float Vy, int rad) : posC(x, y), posL(x - Vx, y - Vy), accel(0.0, 0.1)
    {
        sprite.setRadius(rad);
        sprite.setFillColor(sf::Color::White);
        sprite.setPosition(posC);
    }

    void update(float dt)
    {
        vel = posC - posL;
        posL = posC;
        posC += vel + accel * dt * dt;
    }

    void bounds(int radius)
    {
       
    }

    void draw()
    {
        sprite.setPosition(posC);
    }
};
