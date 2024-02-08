#include "headers/PhysicsCircle.hpp"

PhysicsCircle::PhysicsCircle(Circle &father, bool collisionType, bool move, int gravType, float vx, float vy, float ax, float ay) 
            : parent(father), 
              vel(vx, vy), 
              accel(ax, ay),
              collision(collisionType),
              movable(move),
              grav(gravType) {}


void PhysicsCircle::update(float dt) {
    if (grav == 1) {
        accel.y += 1000.0f;
    }

    if (collision == true) {
        checkCollisions();
    }

    if (movable == true) {
        vel += accel * dt;
        parent.pos += vel * dt;
    }
}

void PhysicsCircle::checkCollisions() {
    
}
