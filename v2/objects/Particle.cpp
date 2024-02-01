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

    Particle(float x, float y, float dx, float dy, int rad) : pos(x, y), posL(x - dx, y - dy), vel(dx, dy), accel(0.0, 10.0)
    {
        radius = rad;
        sprite.setRadius(rad);
        sprite.setFillColor(sf::Color::White);
        sprite.setPosition(x - rad, y - rad);
    }

    void draw()
    {
        sprite.setPosition(pos.x - radius, pos.y - radius);
    }

};
