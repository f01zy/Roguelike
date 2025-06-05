#include "Entity.h"

Entity::Entity(glm::vec2 position, int width, int height, float damage,
               float armor, float health, float speed)
    : position(position), width(width), height(height), damage(damage),
      health(health), armor(armor), speed(speed) {}

void Entity::setPosition(glm::vec2 newPosition) { position = newPosition; }

glm::vec2 Entity::getPosition() { return position; }

void Entity::render() {
  Rectangle figure(position, width, height);
  figure.render();
}

bool Entity::checkCollision(glm::vec2 ap, int aw, int ah, glm::vec2 bp, int bw,
                            int bh) {
  bool collisionX = ap.x + aw >= bp.x && bp.x + bw >= ap.x;
  bool collisionY = ap.y + ah >= bp.y && bp.y + bh >= ap.y;

  return collisionX && collisionY;
}
