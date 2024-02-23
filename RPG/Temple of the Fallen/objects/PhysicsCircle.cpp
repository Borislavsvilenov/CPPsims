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
        accel.y += 500.0f;
    }

    if (collision == true) {
        checkCollisions(PCircle, PRect);
    }

    if (movable == true) {
        vel += accel * dt;
        parent->pos += vel * dt;
        accel.x = 0.0f; 
        accel.y = 0.0f;
    }
}

void PhysicsCircle::checkCollisions(std::vector<PhysicsCircle> &PCircle, std::vector<PhysicsRect> &PRect) {
  for(int pc = 0; pc < PCircle.size(); pc++) {
    if(PCircle[pc].collision) {
      if(&(PCircle[pc].parent) != &(this->parent)) {
        sf::Vector2f to_obj = PCircle[pc].parent->pos - this->parent->pos;
        float d = std::sqrt(to_obj.x * to_obj.x + to_obj.y * to_obj.y);
        if(d < PCircle[pc].parent->r + this->parent->r) {
          float overlap = (PCircle[pc].parent->r - this->parent->r) / 2;
          to_obj /= d;
          
          PCircle[pc].parent->pos += to_obj * overlap;
        }
      }
    }
  }
}
