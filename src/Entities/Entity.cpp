#include "Entity.h"

Entity::Entity(float size, float damage, float armor, float health, float speed)
    : size(size), damage(damage), health(health), armor(armor), speed(speed) {}

void Entity::top() { y -= speed; }

void Entity::bottom() { y += speed; }

void Entity::left() { x -= speed; }

void Entity::right() { x += speed; }
