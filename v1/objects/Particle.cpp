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
    float radius;
    

    Particle(float x, float y, float Vx, float Vy, int rad) : posC(x, y), posL(x - Vx, y - Vy), accel(0.0, 10.0)
    {   
        radius = rad;
        sprite.setRadius(rad);
        sprite.setFillColor(sf::Color::White);
        sprite.setPosition(posC);
    }

    void update(float dt)
    {
        vel = posC - posL;
        posL = posC;

        vel += accel * dt;
        posC += vel;
        
        return;
    }

    void bounds(float Brad, sf::Vector2f Bctr)
    {   
        sf::Vector2f dir = posC - Bctr;
        float dist = std::sqrt(dir.x * dir.x + dir.y * dir.y);
        if(Brad - radius < dist)
        {
            dir /= dist;

            posC = Bctr + dir * (Brad - radius);
        }
        return;
    }

    void draw()
    {
        sprite.setPosition(posC.x - radius, posC.y - radius);
        return;
    }
};
