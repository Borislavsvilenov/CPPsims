#include "../Rect.hpp"

Rect::Rect(float x, float y, float w, float h)
     : pos(x, y), 
       size(w, h) {}

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

void Rect::simpleDraw(sf::RenderWindow &window) {
    sf::RectangleShape draw;
    draw.setPosition(pos.x, pos.y);
    draw.setSize(size);
    draw.setFillColor(sf::Color::White);
    window.draw(draw);
} 
