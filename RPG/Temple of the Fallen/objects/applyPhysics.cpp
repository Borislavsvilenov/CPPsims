#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "shapes.cpp"

class PhysicsRect {
public:
    sf::Vector2f vel;
    sf::Vector2f accel;

    bool collision;
    std::string grav;

    PhysicsRect(Rect &father, bool collisionType, std::string gravType, float vx, float vy, float ax, float ay) : vel(vx, vy), accel(ax, ay)
    {
        Rect parent = father;

        collision = collisionType;
        grav = gravType;
    }

    void update(float dt) {
        if (grav == "down") {
            accel.y = 1000.0f;
        }

        if (collision == true) {

        }
    }
};