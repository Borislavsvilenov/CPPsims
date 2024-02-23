#include "PhysicsCircle.hpp"

PhysicsCircle::PhysicsCircle(Circle *father, bool collisionType, bool move, int gravType, float vx, float vy, float ax, float ay) 
              : parent(father), 
                vel(vx, vy), 
                accel(ax, ay),
                collision(collisionType),
                movable(move),
                grav(gravType) {}


void PhysicsCircle::update(float dt, std::vector<PhysicsCircle> &PCircle, std::vector<PhysicsRect> &PRect) {
    if (grav == 1) {
        accel.y += 10.0f;
    }

    if (collision == true) {
        checkCollisions(PCircle, PRect);
    }

    if (movable == true) {
        vel += accel * dt;
        parent->pos += vel * dt;
    }
}

void PhysicsCircle::checkCollisions(std::vector<PhysicsCircle> &PCircle, std::vector<PhysicsRect> &PRect) {
  for(int pc = 0; pc < PCircle.size(); pc++) {
    if(PCircle[pc].collision) {
      if(&(PCircle[pc].parent) != &(this->parent)) {
        sf::Vector2f to_obj = PCircle[pc].parent->pos - this->parent->pos;
        float d = std::sqrt(to_obj.x * to_obj.x + to_obj.y * to_obj.y);
        if(d < PCircle[pc].parent->r + this->parent->r) {
          to_obj /= d;
          
        }
      }
    }
  }
}
