#pragma once

#include "../Camera/Camera.h"
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
  Map &map;
  EntityManager &entityManager;
  Camera camera;

  void renderObjects();
  void initializeObject(int, int, int, int);
};
