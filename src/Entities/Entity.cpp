#include "Entity.h"
#include <vector>

Entity::Entity(int width, int height, float damage, float armor, float health,
               float speed)
    : width(width), height(height), damage(damage), health(health),
      armor(armor), speed(speed) {}

void Entity::setPosition(int ax, int ay) {
  x = ax;
  y = ay;
}

std::vector<int> Entity::getPosition() { return std::vector<int>{x, y}; }
