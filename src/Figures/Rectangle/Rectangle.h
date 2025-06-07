#pragma once

#include "../Figure.h"
#include <glm/glm.hpp>
#include <string>

class Rectangle final : public Figure {
public:
  Rectangle(glm::vec2, int, int, glm::vec3 = {0.0f, 0.0f, 0.0f},
            std::string = "");
  void render();

private:
  unsigned indices[6]{0, 1, 3, 1, 2, 3};
};
