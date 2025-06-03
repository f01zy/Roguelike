#include "Entity.h"

Entity::Entity(float width, float height, float damage, float armor,
               float health, float speed)
    : width(width), height(height), damage(damage), health(health),
      armor(armor), speed(speed) {}

void Entity::top() {
  if (!checkCollision())
    y -= speed;
}

void Entity::bottom() {
  if (!checkCollision())
    y += speed;
}

void Entity::left() {
  if (!checkCollision())
    x -= speed;
}

void Entity::right() {
  if (!checkCollision())
    x += speed;
}

bool Entity::checkCollision() {
  // ...
  return false;
}
