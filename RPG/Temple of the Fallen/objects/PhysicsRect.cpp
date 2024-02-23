#include "PhysicsRect.hpp"


PhysicsRect::PhysicsRect(Rect *father, bool collisionType, bool move, int gravType, float vx, float vy, float ax, float ay) 
            : parent(father), 
              vel(vx, vy), 
              accel(ax, ay),
              collision(collisionType),
              movable(move),
              grav(gravType) {}

void PhysicsRect::update(float dt, std::vector<PhysicsCircle> &PCircle, std::vector<PhysicsRect> &PRect) {
    if (grav == 1) {
        accel.y += 10.0f;
    }

    if (collision == true) {

    }

    if (movable == true) {
        vel += accel * dt;
        parent->pos += vel * dt;
    }
}
