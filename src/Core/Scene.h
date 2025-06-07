#pragma once

#include "../Camera/Camera.h"
#include "../Map/Minimap.h"
#include <glm/glm.hpp>
#include <vector>

class EntityManager;
class Map;
class Rectangle;
class Entity;
class ObjectsManager;

class Scene final {
public:
  Scene(int, int);
  void init();
  void render();

private:
  int width, height;

  ObjectsManager &objectsManager;
  EntityManager &entityManager;
  Map &map;
  Minimap minimap;
  Camera camera;

  void renderObjects();
  void initializeObject(int, int, int, int);
};
