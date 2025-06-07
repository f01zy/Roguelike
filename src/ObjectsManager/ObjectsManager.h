#pragma once

#include <glm/glm.hpp>
#include <vector>

class Figure;
class Map;

class ObjectsManager final {
public:
  ObjectsManager();
  static ObjectsManager &getInstance();

  Figure *get(int, int);
  void add(int, int, Figure *);
  void remove(int, int);
  void clear();
  glm::vec2 size();

  Map &map;

private:
  std::vector<std::vector<Figure *>> objects;
};
