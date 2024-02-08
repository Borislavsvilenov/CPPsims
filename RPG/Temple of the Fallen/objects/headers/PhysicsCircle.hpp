#pragma once
#include <iostream>
#include <vector>
#include <variant>
#include <SFML/Graphics.hpp>
#include "Rect.hpp"
#include "Circle.hpp"
#include "PhysicsRect.hpp"

class PhysicsCircle {
private:
    Circle &parent;
    sf::Vector2f vel;
    sf::Vector2f accel;

    bool collision;
    bool movable;
    int grav;

public:
    

    PhysicsCircle(Rect &father, bool collisionType, bool move, int gravType, float vx, float vy, float ax, float ay);
    void update(float dt);
    void checkCollisions();
};