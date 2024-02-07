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

    Particle(float x, float y, float dx, float dy, int rad) : pos(x, y), posL(dx, dy), vel(dx, dy), accel(0.0f, 1000.0f)
    {
        radius = rad;
        sprite.setRadius(rad);
        sprite.setFillColor(sf::Color::White);
        sprite.setPosition(x - rad, y - rad);
    }

    void update(float dt)
    {
        vel = pos - posL;

        posL = pos;

        pos = pos + vel + (accel * dt * dt);
    }

    void collide(Particle &p2, float d)
    {
        if(d != 0)
        {
            float overlap = (radius + p2.radius - d) / 2;
            sf::Vector2f normal = (pos - p2.pos) / d;

            pos += normal * overlap;
            p2.pos -= normal * overlap;
        }
    }

    void checkCollision(std::vector<Particle> &particles, int sstep)
    {
        for(int step = 0; step < sstep; step++)
        {
            for(int i = 0; i < particles.size(); i++)
            {
                Particle &p2 = particles[i];
                if(&p2 != this)
                {
                    sf::Vector2f diff = pos - p2.pos;
                    float d = std::sqrt(diff.x * diff.x + diff.y * diff.y);
                    if(d < radius + p2.radius)
                    {
                        collide(p2, d);
                    }
                }
            }
        }
    }

    void bounds(float width, float heigth)
    {
        if(pos.x > width - radius)
        {
            pos.x = width - radius;
        } else if(pos.x < 0 + radius)
        {
            pos.x = 0 + radius;
        }
        if(pos.y > heigth - radius)
        {
            pos.y = heigth -radius;
        } else if(pos.y < 0 + radius)
        {
            pos.y = 0 + radius;
        }
    }

    void draw()
    {
        sprite.setPosition(pos.x - radius, pos.y - radius);
    }

};
