#pragma once

#include <glm/glm.hpp>

class Entity;

class Collision {
public:
  bool checkAllObjectsCollision(Entity &);

private:
  bool checkCertainObjectCollision(glm::vec2, int, int, glm::vec2, int, int);
};
