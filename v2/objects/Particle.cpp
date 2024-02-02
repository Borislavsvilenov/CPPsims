#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Particle
{
private:
    
public:
    sf::Vector2f pos;
    sf::Vector2f posL;
    sf::Vector2f vel;
    sf::Vector2f accel;
    sf::CircleShape sprite;
    int radius;

    Particle(float x, float y, float dx, float dy, int rad) : pos(x, y), posL(x - dx, y - dy), vel(dx, dy), accel(0.0, 100.0)
    {
        radius = rad;
        sprite.setRadius(rad);
        sprite.setFillColor(sf::Color::White);
        sprite.setPosition(x - rad, y - rad);
    }

    void update(float dt)
    {
        vel += accel * dt;

        posL = pos;

        pos += vel * dt;
    }

    void bounds(float width, float heigth)
    {
        if(pos.x > width - radius)
        {
            pos.x = width - radius;
            vel.x *= - 0.3f;
        } else if(pos.x < 0 + radius)
        {
            pos.x = 0 + radius;
            vel.x *= - 0.3f;
        }
        if(pos.y > heigth - radius)
        {
            pos.y = heigth -radius;
            vel.y *= - 0.3f;
        } else if(pos.y < 0 + radius)
        {
            pos.y = 0 + radius;
            vel.y *= - 0.3f;
        }
    }

    void draw()
    {
        sprite.setPosition(pos.x - radius, pos.y - radius);
    }

};
