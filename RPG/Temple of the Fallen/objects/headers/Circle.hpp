#pragma once
#include <SFML/Graphics.hpp>
#include "Rect.hpp"

class Circle {
public:
    sf::Vector2f pos;
    float r;

    Circle(float x, float y, float rad);
    void moveTo(sf::Vector2f Apos);
    bool overlapsRect(Rect &obj);
    bool overlapsCircle(Circle &obj);
};