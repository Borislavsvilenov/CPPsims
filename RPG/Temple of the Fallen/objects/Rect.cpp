#include "Rect.hpp"
#include "Circle.hpp"

Rect::Rect(float x, float y, float vx, float vy, float ax, float ay, float w, float h)
    : pos(x, y), vel(vx, vy), accel(ax, ay), size(w, h) {}

void Rect::moveTo(sf::Vector2f Apos) {
    pos = Apos;
}

bool Rect::overlapsRect(Rect &obj) {
    bool horizontalOverlap = (pos.x < obj.pos.x + obj.size.x) && (pos.x + size.x > obj.size.x);
    bool verticalOverlap = (pos.y < obj.pos.y + obj.size.y) && (pos.y + size.y > obj.size.y);
    return horizontalOverlap && verticalOverlap;
}

bool Rect::overlapsCircle(Circle &obj) {
    float closestX = std::max(obj.pos.x, std::min(pos.x, obj.pos.x + obj.r));
    float closestY = std::max(obj.pos.y, std::min(pos.y, obj.pos.y + obj.r));

    float dx = pos.x - closestX;
    float dy = pos.y - closestY;

    return (dx * dx + dy * dy) <= (obj.r * obj.r);
}