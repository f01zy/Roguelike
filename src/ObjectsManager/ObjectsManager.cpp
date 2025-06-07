#include "ObjectsManager.h"
#include "../Figures/Rectangle/Rectangle.h"
#include "../Map/Map.h"

ObjectsManager::ObjectsManager()
    : map(Map::getInstance()),
      objects(map.roomSide * map.getGridSize(),
              std::vector<Rectangle *>(map.roomSide * map.getGridSize(),
                                       nullptr)) {}

ObjectsManager &ObjectsManager::getInstance() {
  static ObjectsManager objectsManager;
  return objectsManager;
}

Rectangle *ObjectsManager::get(int x, int y) { return objects[y][x]; }

void ObjectsManager::add(int x, int y, Rectangle *object) {
  objects[y][x] = object;
}

void ObjectsManager::remove(int x, int y) { objects[y][x] = nullptr; }

void ObjectsManager::clear() {
  for (int i = 0; i < objects.size(); i++) {
    for (int j = 0; j < objects[i].size(); j++) {
      objects[i][j] = nullptr;
    }
  }
}

glm::vec2 ObjectsManager::size() {
  return glm::vec2(objects.size(), objects[0].size());
}
