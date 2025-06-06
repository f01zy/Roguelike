#pragma once

#include "../Assets/Shader/Shader.h"
#include "../Entities/Entity.h"
#include "../Map/Map.h"
#include <GL/glew.h>
#include <algorithm>
#include <cmath>
#include <glm/glm.hpp>

class Camera final {
public:
  Camera(glm::vec2, int, int, int);
  Camera(Camera &) = delete;

  void update(Entity &);

private:
  const int width, height;
  const int mapSide;

  glm::vec2 position;
};
