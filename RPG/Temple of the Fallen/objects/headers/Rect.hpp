#pragma once
#include <SFML/Graphics.hpp>
#include "Circle.hpp"

class Circle;

class Rect {
public:
    sf::Vector2f pos;
    sf::Vector2f size;

    Rect(float x, float y, float w, float h);

    void moveTo(sf::Vector2f Apos);
    bool overlapsRect(Rect &obj);
    bool overlapsCircle(Circle &obj);
};