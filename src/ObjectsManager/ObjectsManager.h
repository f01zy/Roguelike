#pragma once

#include <glm/glm.hpp>
#include <vector>

class Rectangle;
class Map;

class ObjectsManager final {
public:
  ObjectsManager();
  static ObjectsManager &getInstance();

  Rectangle *get(int, int);
  void add(int, int, Rectangle *);
  void remove(int, int);
  void clear();
  glm::vec2 size();

  Map &map;

private:
  std::vector<std::vector<Rectangle *>> objects;
};
