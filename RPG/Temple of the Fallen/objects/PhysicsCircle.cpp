#include "headers/PhysicsCircle.hpp"

PhysicsCircle::PhysicsCircle(Circle &father, bool collisionType, bool move, int gravType, float vx, float vy, float ax, float ay) 
            : parent(father), 
              vel(vx, vy), 
              accel(ax, ay),
              collision(collisionType),
              movable(move),
              grav(gravType) {}


void PhysicsCircle::update(float dt, std::vector<PhysicsCircle> &PCircle, std::vector<PhysicsRect> &PRect) {
    if (grav == 1) {
        accel.y += 1000.0f;
    }

    if (collision == true) {
        checkCollisions(PCircle, PRect);
    }

    if (movable == true) {
        vel += accel * dt;
        parent.pos += vel * dt;
    }
}

void PhysicsCircle::checkCollisions(std::vector<PhysicsCircle> &PCircle, std::vector<PhysicsRect> &PRect) {
    for(int pc = 0; pc < PCircle.size(); pc++) {
        if(PCircle[pc].collision) {
            if(&(PCircle[pc].parent) != &(this->parent)) {
                continue;
            }
        }
    }
}
