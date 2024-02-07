#include "headers/Circle.hpp"

Circle::Circle(float x, float y, float rad) 
       : pos(x, y), 
         r(rad) {}

void Circle::moveTo(sf::Vector2f Apos) {
    pos = Apos;
}

bool Circle::overlapsRect(Rect &obj) {
    float closestX = std::max(obj.pos.x, std::min(pos.x, obj.pos.x + obj.size.x));
    float closestY = std::max(obj.pos.y, std::min(pos.y, obj.pos.y + obj.size.y));

    float dx = pos.x - closestX;
    float dy = pos.y - closestY;

    return (dx * dx + dy * dy) <= (r * r);
}

bool Circle::overlapsCircle(Circle &obj) {
    sf::Vector2f toObj = pos - obj.pos;

    float d = std::sqrt(toObj.x * toObj.x + toObj.y * toObj.y);

    return d <= r + obj.r;
}