#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Rect {

public:
    sf::Vector2f pos;
    sf::Vector2f vel;
    sf::Vector2f accel;
    sf::Vector2f size;

    Rect(float x, float y, float vx, float vy, float ax, float ay, float w, float h) : pos(x, y), vel(vx, vy), accel(ax, ay), size(w, h)
    {

    }

    void moveTo(sf::Vector2f Apos) {
        pos = Apos;
    }

    bool overlapsRect(Rect &obj) {
        bool horizontalOverlap = (pos.x < obj.pos.x + obj.size.x) && (pos.x + size.x > obj.size.x);
        bool verticalOverlap = (pos.y < obj.pos.y + obj.size.y) && (pos.y + size.y > obj.size.y);
        return horizontalOverlap &&verticalOverlap;
    }

    bool overlapsCircle(Circle &obj) {
        float closestX = std::max(pos.x, std::min(obj.pos.x, pos.x + size.x));
        float closestY = std::max(pos.y, std::min(obj.pos.y, pos.y + size.y));

        float dx = obj.pos.x - closestX;
        float dy = obj.pos.y - closestY;

        return (dx * dx + dy * dy) <= (obj.r * obj.r);
    }
};

class Circle {
public:
    sf::Vector2f pos;
    sf::Vector2f vel;
    sf::Vector2f accel;
    float r;

    Circle(float x, float y, float vx, float vy, float ax, float ay, float w, float h, float rad) : pos(x, y), vel(vx, vy), accel(ax, ay)
    {
        r = rad;
    }

    void moveTo(sf::Vector2f Apos) {
        pos = Apos;
    }

    bool overlapsRect(Rect &obj) {
        float closestX = std::max(obj.pos.x, std::min(pos.x, obj.pos.x + obj.size.x));
        float closestY = std::max(obj.pos.y, std::min(pos.y, obj.pos.y + obj.size.y));

        float dx = pos.x - closestX;
        float dy = pos.y - closestY;

        return (dx * dx + dy * dy) <= (r * r);
    }

    bool overlapsCircle(Circle &obj) {
        sf::Vector2f toObj = pos - obj.pos;

        float d = std::sqrt(toObj.x * toObj.x + toObj.y * toObj.y);

        return d <= r + obj.r;
    }
};