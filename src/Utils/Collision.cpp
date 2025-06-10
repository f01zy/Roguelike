#include "Collision.h"
#include "../ObjectsManager/ObjectsManager.h"
#include "../Types/Object.h"

bool Collision::checkAllObjectsCollision(glm::vec2 position, int width,
                                         int height) {
  ObjectsManager objectsManager = ObjectsManager::getInstance();
  glm::vec2 size = objectsManager.size();

  for (int i = 0; i < size.y; i++) {
    for (int j = 0; j < size.x; j++) {
      Object *object = objectsManager.get(j, i);

      if (!object)
        continue;

      glm::vec2 objectPosition = object->figure->getPosition();
      int objectWidth = object->figure->width;
      int objectHeight = object->figure->height;

      if (checkCertainObjectCollision(position, width, height, objectPosition,
                                      objectWidth, objectHeight))
        return true;
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
