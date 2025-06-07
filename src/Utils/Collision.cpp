#include "Collision.h"
#include "../Entities/Entity.h"
#include "../Figures/Rectangle/Rectangle.h"
#include "../ObjectsManager/ObjectsManager.h"

bool Collision::checkAllObjectsCollision(Entity &entity) {
  ObjectsManager objectsManager = ObjectsManager::getInstance();
  glm::vec2 size = objectsManager.size();

  for (int i = 0; i < size.y; i++) {
    for (int j = 0; j < size.x; j++) {
      Rectangle *object = objectsManager.get(j, i);

      if (object) {
        glm::vec2 objectPosition = object->getPosition();

        if (checkCertainObjectCollision(entity.getPosition(), entity.width,
                                        entity.height, objectPosition,
                                        object->width, object->height))
          return true;
      }
    }
  }

  return false;
}

bool Collision::checkCertainObjectCollision(glm::vec2 ap, int aw, int ah,
                                            glm::vec2 bp, int bw, int bh) {
  bool collisionX = ap.x + aw >= bp.x && bp.x + bw >= ap.x;
  bool collisionY = ap.y + ah >= bp.y && bp.y + bh >= ap.y;

  return collisionX && collisionY;
}
