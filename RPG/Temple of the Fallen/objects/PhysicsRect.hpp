#pragma once
#include <iostream>
#include <vector>
#include <variant>
#include <SFML/Graphics.hpp>
#include "PhysicsCircle.hpp"
#include "Rect.hpp"
#include "Circle.hpp"

class PhysicsCircle;

class PhysicsRect {
private:
    Rect *parent;
    sf::Vector2f vel;
    sf::Vector2f accel;

    bool collision;
    bool movable;
    int grav;

public:
    PhysicsRect(Rect *father, bool collisionType, bool move, int gravType, float vx, float vy, float ax, float ay);
    void update(float dt);
};