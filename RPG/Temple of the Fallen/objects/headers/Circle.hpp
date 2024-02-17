#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Rect.hpp"

class Rect;

class Circle {
public:
    sf::Vector2f pos;
    float r;

    Circle(float x, float y, float rad);
    void moveTo(sf::Vector2f Apos);
    bool overlapsRect(Rect &obj);
    bool overlapsCircle(Circle &obj);
    void simpleDraw(sf::RenderWindow &window);
};