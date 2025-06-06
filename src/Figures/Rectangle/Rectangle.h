#pragma once

#include "../../Assets/Texture/Texture.h"
#include "../Figure.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL/SOIL.h>

class Rectangle final : public Figure {
public:
  Rectangle(glm::vec2, int, int, glm::vec3 = {0.0f, 0.0f, 0.0f},
            std::string = "");
  void render();

private:
  unsigned indices[6]{0, 1, 3, 1, 2, 3};
};
