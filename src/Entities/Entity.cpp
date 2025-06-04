#include "Entity.h"

Entity::Entity(int width, int height, float damage, float armor, float health,
               float speed)
    : width(width), height(height), damage(damage), health(health),
      armor(armor), speed(speed) {}

void Entity::top() { y -= speed; }

void Entity::bottom() { y += speed; }

void Entity::left() { x -= speed; }

void Entity::right() { x += speed; }
