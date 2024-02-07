#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "shapes.cpp"

class PhysicsRect {
private:
    Rect& parent;
    sf::Vector2f vel;
    sf::Vector2f accel;

    bool collision;
    bool movable;
    int grav;

public:
    PhysicsRect(Rect &father, bool collisionType, bool move, int gravType, float vx, float vy, float ax, float ay) 
        : parent(father), 
          vel(vx, vy), 
          accel(ax, ay),
          collision(collisionType),
          movable(move),
          grav(gravType)
    {

    }

    void update(float dt) {
        if (grav == 1) {
            accel.y += 1000.0f;
        }

        if (collision == true) {

        }

        if (movable == true) {
            vel += accel * dt;
            parent.pos += vel * dt;
        }
    }
};