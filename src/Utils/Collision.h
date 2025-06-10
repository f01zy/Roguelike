#pragma once

#include <glm/glm.hpp>

class Collision {
public:
  bool checkAllObjectsCollision(glm::vec2, int, int);

private:
  bool checkCertainObjectCollision(glm::vec2, int, int, glm::vec2, int, int);
};
