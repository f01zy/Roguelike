#pragma once

#include "../Types/Object.h"
#include <glm/glm.hpp>
#include <vector>

class Map;

class ObjectsManager final {
public:
  ObjectsManager();
  static ObjectsManager &getInstance();

  Object *get(int, int);
  void add(int, int, Object *);
  void remove(int, int);
  void clear();
  glm::vec2 size();

  Map &map;

private:
  std::vector<std::vector<Object *>> objects;
};
