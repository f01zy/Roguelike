#include "Entity.h"
#include "../Figures/Rectangle/Rectangle.h"
#include "../Types/Variables.h"

Entity::Entity(glm::vec2 position, int width, int height, float damage,
               float armor, float health, float speed)
    : position(position), width(width), height(height), damage(damage),
      health(health), armor(armor), speed(speed) {}

void Entity::setPosition(glm::vec2 newPosition) { position = newPosition; }

glm::vec2 Entity::getPosition() { return position; }

void Entity::render() {
  Rectangle figure(position, DEFAULT, width, height);
  figure.render();
}
