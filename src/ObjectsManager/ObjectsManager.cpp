#include "ObjectsManager.h"
#include "../Map/Map.h"

ObjectsManager::ObjectsManager()
    : map(Map::getInstance()),
      objects(map.blocksInMapSide,
              std::vector<Object *>(map.blocksInMapSide, nullptr)) {}

ObjectsManager &ObjectsManager::getInstance() {
  static ObjectsManager objectsManager;
  return objectsManager;
}

Object *ObjectsManager::get(int x, int y) { return objects[y][x]; }

void ObjectsManager::add(int x, int y, Object *object) {
  objects[y][x] = object;
}

void ObjectsManager::remove(int x, int y) { objects[y][x] = nullptr; }

void ObjectsManager::clear() {
  for (int i = 0; i < objects.size(); i++) {
    for (int j = 0; j < objects[i].size(); j++) {
      delete objects[i][j];
      objects[i][j] = nullptr;
    }
  }
}

glm::vec2 ObjectsManager::size() {
  return glm::vec2(objects.size(), objects[0].size());
}
